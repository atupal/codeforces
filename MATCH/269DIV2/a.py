#raw_input split

A = map(int, raw_input().split())

flag = 0
for i in A:
    if A.count(i) >= 4:
        flag = 1
        for x in xrange(4):
            A.remove(i)
        break

if not flag:
    print 'Alien'
    exit(0)

if A[0] == A[1]:
    print 'Elephant'
else:
    print 'Bear'
