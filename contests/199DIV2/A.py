
n = int(raw_input())

c = [ 0 for i in xrange(10)]

for _ in raw_input().split():
  c[int(_)] += 1 

r = [n / 3 for i in xrange(4)]

if c[1] < n / 3 or c[5] % 2 != 0 or c[7] % 2 != 0:
  print -1
  exit()

r[2] -= c[5] / 2 + c[7] / 2 + c[3] / 2
if c[3] % 2 == 1:
  if c[6] > 0:
    r[2] -= 1
    c[6] -= 1
  else:
    print -1
    exit()

if c[1] > n / 3:
  r[2] -= c[1] - n / 3

if c[2] > n / 3 - r[2]:
  for i in xrange(c[5]):
    print 1, 5, 5
  for i in xrange(c[7]):
    print 1, 7,7
  for i in xrange(c[3]):
    print 1,3,3
  if c[3] % 2 == 1:
    print 1,3,6

  for i in xrange(c[4]):
    print 1,2,4
  for i in xrange(c[6]):
    print 1,2,6
  for i in xrange( ( c[2] - n / 3 - r[2] )/2 ):
    print 1,2,2
else:
  for i in xrange(c[5]):
    print 1, 5, 5
  for i in xrange(c[7]):
    print 1, 7,7
  for i in xrange(c[3]):
    print 1,3,3
  if c[3] % 2 == 1:
    print 1,3,6

  if n / 3 - r[2] - c[2] > c[4] / 2:
    for i in xrange(c[4] / 2):
      print 1,4,4
    for i in xrange(n / 3 - r[2] - c[2] - c[4] / 2):
      print 1,6,6
  else:
    for i in xrange(n / 3 - r[2] - c[2]):
      print 1, 4,4
    for i in xrange( c[4] - (n / 3 - r[2] - c[2]) * 2 ):
      print 1, 2,4
    for i in xrange(c[6]):
      print 1, 2,6
