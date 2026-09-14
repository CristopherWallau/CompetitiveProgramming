import sys

def solve():
    raw = sys.stdin.read().strip()
    if not raw:
        return
    n = int(raw)

    if n == 1:
        print(1)
        return
    if n == 2 or n == 3:
        print("NO SOLUTION")
        return

    # Pares: 2, 4, 6... seguidos dos Ímpares: 1, 3, 5...
    evens = range(2, n + 1, 2)
    odds = range(1, n + 1, 2)

    # Imprime usando join para máxima performance com n = 10^6
    sys.stdout.write(" ".join(map(str, evens)) + " " + " ".join(map(str, odds)) + "\n")

if __name__ == '__main__':
    solve()