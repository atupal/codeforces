n = int(raw_input())

p = []

for i in xrange(1,n+1):
    p.append([])

for i in xrange(1,n+1):
    for ind, x in enumerate(raw_input().split()):
        p[i].append((int(x), ind+1))
    p[i].sort()
