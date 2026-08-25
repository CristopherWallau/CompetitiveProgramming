from collections import Counter

n = int(input())
a = list(map(int, input().split()))

freq = Counter(a)

if all(x % 3 == 0 for x in freq.values()):
    print("N")
else:
    print("Y")