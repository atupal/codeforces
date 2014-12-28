
n,k = [int(_) for _ in raw_input().split()]

for i in xrange(k):
  print 2*i+1, 2*i+2,

for i in xrange(k, n):
  print 2*i+2, 2*i+1,
