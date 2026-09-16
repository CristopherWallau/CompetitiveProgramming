import sys

def solve():
    linha = sys.stdin.readline().strip()
    if not linha:
        return
    n = int(linha)
    soma =1
    for i in range(1, n + 1):
        soma = 2 * soma
        soma = soma % 1000000007
    print(soma) 
if __name__ == '__main__':
    solve()
