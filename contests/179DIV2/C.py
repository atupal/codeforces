
tmp = raw_input().split(' ')
n = int(tmp[0])
m = int(tmp[1])
k = int(tmp[2])

s = raw_input().split(' ')
s = [int(_) for _ in s]

op = [[] for i in xrange(m)]
cnt = [ 0 for i in xrange(m)]
for i in xrange(m):
    tmp = raw_input().split(' ')
    op[i] = [int(_) for _ in tmp]

for i in xrange(k):
    tmp = raw_input().split(' ')
    x = int(tmp[0])
    y = int(tmp[1])
    for i in xrange(y - x + 1):
        cnt[i + x - 1] += 1
for i in xrange(m):
    for j in xrange(op[i][1] - op[i][0] + 1):
        s[j + op[i][0] - 1] += op[i][2] * cnt[i]


s = [str(i) for i in s]

print ' '.join(s)
