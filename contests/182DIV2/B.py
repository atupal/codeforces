'''
4 9
1 2
2 1
1 1
2 2
1 2 3 4 5 6 7 8 9
'''

t = raw_input().split(' ')
n = int(t[0])
m = int(t[1])

t = [0] * n

for i in xrange(n):
    p = raw_input().split(' ')
    if i:
        t[i] = t[i - 1] + int(p[0]) * int(p[1])
    else:
        t[i] = int(p[0]) * int(p[1])

p = raw_input().split(' ')
q = [int(i) for i in p]

for m in q:
    l = 0
    r = n - 1
    while l < r:
        mid = (l + r) >> 1
        if t[mid] < m:
            l = mid + 1
        else:
            r = mid
    print r + 1
