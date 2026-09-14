import sys

def solve():
    # Lê toda a entrada de uma vez para ser mais rápido
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    nums = list(map(int, input_data[1:]))
    mov = 0
    for i in range(1, n):
        if nums[i] < nums[i - 1]:
            mov += nums[i - 1] - nums[i]
            nums[i] = nums[i - 1] 
    print(mov)
if __name__ == '__main__':
    solve()
