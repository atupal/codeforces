
t = raw_input().split(' ')
n = int(t[0])
m = int(t[1])

t = raw_input().split(' ')
A = [int(i) for i in t]
s = abs(sum(A))
for i in xrange(m):
    t = raw_input().split(' ')
    l = int(t[0])
    r = int(t[1])
    t = r - l + 1
    if t % 2:
        print 0
    else:
        if t <= len(A) - s:
            print 1
        else:
            print 0
