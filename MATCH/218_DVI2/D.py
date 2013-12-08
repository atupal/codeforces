n =  int(raw_input())

B = [ int(_) for _ in raw_input().split() ]
B = [0] + B

m = int(raw_input())


def lowbit(x):
  return x & (-x)

A = [0] * (n+1)
C = [0] * (n+1)
BB = [0] * (n+1)

for i in xrange(1, n+1):
  BB[i] = BB[i-1] + B[i]

def modify(p, delta):
  A[p] += delta
  while p <= n:
    C[p] += delta
    p += ( p & (-p) )

def _sum(p):
  rs = 0
  while p:
    rs += C[p]
    p -= ( p & (-p) )
  return rs


def cal(x):
  low = x
  hig = n
  tmp = _sum(x-1) - BB[x-1]
  while low < hig:
    mid = (low + hig) >> 1
    if tmp + BB[mid]== _sum(mid):
      low = mid + 1
    else:
      hig = mid - 1
  return low

for i in xrange(m):
  c = [ int(_) for _ in raw_input().split() ]
  if c[0] == 1:
    x , y= c[1],c[2]
    while y > 0 and x <= n:
      x = cal(x)
      d = B[x] - A[x]
      if d >= y:
        modify(x, y)
      elif d > 0:
        modify(x, d)
      y -= d
      x += 1
  else:
    #print _sum(c[1]) - _sum(c[1] - 1)
    print A[ c[1] ]
