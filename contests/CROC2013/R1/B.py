'''
4 4
1 2
2 3
3 4
4 1
'''

t = raw_input().split(' ')
n = int(t[0])
m = int(t[1])


g = [0 for i in xrange(n + 1)]

for i in xrange(m):
    t = raw_input().split(' ')
    g[int(t[0])] += 1
    g[int(t[1])] += 1

cnt_1 = 0
cnt_2 = 0
cnt_n = 0
flag = 0
for i in g[1:]:
    if i == 1:
        cnt_1 += 1
    elif i == 2:
        cnt_2 += 1
    elif i == n - 1:
        cnt_n += 1
    else:
        flag = 1
        break

if not flag and cnt_1 == 2 and cnt_2 == n - 2:
    print 'bus topology'
    exit()

if not flag and cnt_1 == 0 and cnt_2 == n :
    print 'ring topology'
    exit()

if not flag and cnt_n == 1 and cnt_1 == n  -1:
    print 'star topology'
    exit()

print 'unknown topology'
