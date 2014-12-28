'''
3 1000
1000
0 0
0 1
0 3
'''

t = raw_input().split(' ')
n = int(t[0])
d = int(t[1])
x = [None] * n
y = [None] * n
c = [None] * n

for i in xrange(n - 2):
    c[i + 1] = int(raw_input())

for i in xrange(n):
    t = raw_input().split(' ')
    x[i] = int(t[0])
    y[i] = int(t[1])


