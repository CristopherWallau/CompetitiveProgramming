import sys

def solve():
    linha = sys.stdin.readline().strip()
    if not linha:
        return
    n = int(linha)
    # A soma só é divisível por 2 se n % 4 for 0 ou 3
    if n % 4 not in (0, 3):
        print("NO")
        return
    arr = [False] * 1000000
    print("YES")
    set1 = []
    set2 = []
    if n % 4 == 0:
        # Agrupa de 4 em 4 a partir de 1 até n
        for i in range(1, n + 1, 4):
            set1.append(i)
            set1.append(i + 3)
            set2.append(i + 1)
            set2.append(i + 2)
    else:
        # Trata a base 1, 2, 3 separadamente: 1 + 2 = 3
        set1.extend([1, 2])
        set2.append(3)
        # O restante (de 4 até n) tem quantidade múltipla de 4
        for i in range(4, n + 1, 4):
            set1.append(i)
            set1.append(i + 3)
            set2.append(i + 1)
            set2.append(i + 2)

    # Impressão do primeiro conjunto
    print(len(set1))
    print(" ".join(map(str, set1)))

    # Impressão do segundo conjunto
    print(len(set2))
    print(" ".join(map(str, set2)))
if __name__ == '__main__':
    solve()
