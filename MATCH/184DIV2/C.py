'''
4
0 1 1 1
'''
n = int(raw_input())
t = raw_input().split(' ')
A = [int(_) for _ in t]
ans = 0
cur = 0

i = 0
while i < n:
    t = 1
    while i < n and A[i + 1] == A[i]:
        t += 1

    if A[i] > cur:
        ans += cur - i

    i += t
