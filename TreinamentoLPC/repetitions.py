import sys

def solve():
    # Lê toda a entrada de uma vez para ser mais rápido
    s = sys.stdin.read().strip()
    if not s:
        return
    soma_global = 1
    soma = 1
    for i in range(1, len(s)):
        anterior = s[i - 1]
        atual = s[i]
        if(atual == anterior):
            soma = soma + 1
            soma_global = max(soma_global, soma)
            continue
        else:
            soma = 1
            soma_global = max(soma_global, soma)
    print(soma_global)

if __name__ == '__main__':
    solve()