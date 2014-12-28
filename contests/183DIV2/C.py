n = int(raw_input())

if n % 2 == 0:
    print -1
    exit()

for i in xrange(n):
    print i,
print

t = n - 1
for i in xrange(n):
    print t,
    t = (t + n - 2) % n


print
for i in xrange(n - 1, -1, -1):
    print i,
