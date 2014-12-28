from random import randint

n = randint(1, 100)
s = set()

for i in xrange(randint(1, 10)):
    l = randint(1, n - 1)
    r = randint(1, n - l)
    s.add((l, r))

print n, len(s)
for i in s:
    print i[0], i[1]
