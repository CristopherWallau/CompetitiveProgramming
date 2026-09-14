import sys

def solve():
    # Lê toda a entrada de uma vez para ser mais rápido
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    
    # Soma esperada de 1 até n
    expected_sum = n * (n + 1) // 2
    
    # Soma dos n - 1 números fornecidos
    actual_sum = sum(map(int, input_data[1:]))
    
    print(expected_sum - actual_sum)

if __name__ == '__main__':
    solve()