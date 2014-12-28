n,k = [ int(_) for _ in raw_input().split() ]

A = [int(_) for _ in raw_input().split()]


ans = 0


for j in xrange(k):
  B = []
  for i in xrange( n/ k):
    B.append( A[ i * k + j ] )
  _1 = B.count(1)
  _2 = B.count(2)

  ans += min( _1, _2)


print ans
