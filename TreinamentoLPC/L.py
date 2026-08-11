import sys

def solve():
    # Leitura rápida de toda a entrada
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    idx = 0
    N = int(input_data[idx])
    idx += 1
    
    # 1. Lendo o dicionário e mapeando vetores
    dictionary = {}
    dict_order = []
    for _ in range(N):
        word = input_data[idx]
        x = int(input_data[idx+1])
        y = int(input_data[idx+2])
        dictionary[word] = (x, y)
        dict_order.append(word)
        idx += 3
        
    # 2. Lendo o texto (knowledge base)
    M = int(input_data[idx])
    idx += 1
    text = []
    for _ in range(M):
        text.append(input_data[idx])
        idx += 1
        
    # 3. Processando as Queries
    Q = int(input_data[idx])
    K_max = int(input_data[idx+1])
    idx += 2
    
    for _ in range(Q):
        F = int(input_data[idx])
        idx += 1
        query = []
        for _ in range(F):
            query.append(input_data[idx])
            idx += 1
        
        candidates = []
        # Tenta achar o contexto diminuindo K
        for k in range(K_max, 0, -1):
            ctx = query[-k:]
            # Varre o texto procurando a janela (graças ao Python isso é muito fácil)
            for i in range(M - k):
                if text[i:i+k] == ctx:
                    candidates.append(text[i+k])
            
            if candidates:
                break # Achou, não precisa diminuir o K
        
        if not candidates:
            print(" ".join(query) + " *")
            continue
        
        # Somando os vetores dos candidatos (S(d) linearizado)
        sum_x, sum_y = 0, 0
        for c in candidates:
            vx, vy = dictionary.get(c, (0, 0))
            sum_x += vx
            sum_y += vy
            
        # Achando a palavra com maior similaridade
        best_word = ""
        best_score = -float('inf')
        
        for d in dict_order:
            dx, dy = dictionary[d]
            # O produto escalar total é a soma dos produtos
            score = dx * sum_x + dy * sum_y 
            if score > best_score:
                best_score = score
                best_word = d
                
        print(" ".join(query) + " " + best_word)

if __name__ == '__main__':
    solve()