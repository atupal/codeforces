n = 10000

A = [0] * (n + 1)

A[5] = 1

if n < 5:
    print 1
    exit()

import math
for x in xrange(6, n + 1, 1):
    A[x] = A[x - 1]
    for i in xrange(1, int(math.sqrt(x * x / 2)) + 1, 1):
        t = x ** 2 - i ** 2
        if math.sqrt(t) % 1 == 0.0:
            A[x] += 1



print A
