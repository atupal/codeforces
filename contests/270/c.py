
n = int(raw_input())

a = [[0,0]]
for  i in xrange(n):
    a.append(raw_input().split())
    a[i+1].sort()

p = map(int, raw_input().split())

pre = a[p[0]][0]

for i in xrange(1, n):
    if a[p[i]][0] > pre:
        pre = a[p[i]][0]
    elif a[p[i]][1] > pre:
        pre = a[p[i]][1]
    else:
        print 'NO'
        exit(0)

print 'YES'
