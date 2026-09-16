import sys

def solve():
    linha = sys.stdin.readline().strip()
    if not linha:
        return
    n = int(linha)
    soma =0
    while n > 0:
        soma += n // 5
        n //= 5
    print(soma) 
if __name__ == '__main__':
    solve()
