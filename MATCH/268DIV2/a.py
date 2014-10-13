
n = int(raw_input())

p = map(int, raw_input().split())
q = map(int, raw_input().split())


for i in xrange(n):
    if i+1 not in p[1:]+q[1:]:
        print 'Oh, my keyboard!'
        exit(0)


print 'I become the guy.'
