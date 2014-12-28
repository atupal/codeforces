n =  int(raw_input())

B = [ int(_) for _ in raw_input().split() ]
B = [0] + B

m = int(raw_input())


A = [0] * (n+1)
C = [0] * (n+1)

def add(x):
  while x <= n:
    C[x] += 1
    x += (x & (-x))

def rem(x):
  while x <= n:
    C[x] -= 1
    x += (x & (-x))

def get(x):
  ret = 0
  while x > 0:
    ret += C[x]
    x -= (x & (-x))
  return ret


def find(y):
  tmp = get(y-1)
  lef = y-1
  rig = n+1
  while lef < rig - 1:
    mid = (lef + rig) >> 1
    if ( get(mid) == tmp):
      lef = mid
    else:
      rig = mid

  return rig

for i in xrange(1, n+ 1):
  add(i)

for i in xrange(m):
  c = [ int(_) for _ in raw_input().split() ]
  if c[0] == 1:
    y , z= c[1],c[2]
    while y < n + 1 and z > 0:
      y = find(y)
      if y < n + 1:
        A[y] += z
        z = 0
        if B[y] < A[y]:
          z = A[y] - B[y]
          A[y] = B[y]
          rem(y)
  else:
    print A[c[1]]
