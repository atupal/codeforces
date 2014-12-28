n = int(raw_input())

A = [ int(_) for _ in raw_input().split() ]

for i in xrange(n):
  A[i] = [A[i], i+1]

A.sort()

k = int(raw_input())

ans = 0
mm = 100000000000000000000
dis = 100000000000000000000

def get(x):
  ret = 0

  for i  in xrange(x+1, x + k):
    ind = i - x 
    ret += (A[i][0] - A[i-1][0]) * ( ind * ( k - ind ) )
    if ret >= dis:
      return 100000000000000000000
  return ret

S = [0] * n
S[0] = A[0][0]
for  i in xrange(1, n):
  S[i] = S[i-1] + A[i][0]

t = dis = get(0)
ans = 0

for i in xrange(1, n-k+1):
  #t = get(i)
  #t += 2 * (S[i+k-2] - S[i-1]) + A[i-1][0] * (k-1) + A[i+k-1][0] * (k-1)
  t += -(S[i-2+k]-S[i-1]-A[i-1][0]*(k-1))+(A[i-1+k][0]*(k-1)-(S[i-2+k]-S[i-1]))
  if t < dis:
    ans = i
    dis = t

for i in xrange(k):
  print A[i+ans][1],
