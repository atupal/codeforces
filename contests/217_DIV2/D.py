n, m = [ int(_) for _ in raw_input().split() ]

A = [None] * n

for i in xrange(n): 
  A[i] = raw_input()

l, r, u, d = 2000001,0, 20000001 ,0

for ind, i in enumerate(A):
  t = i.find('w')
  if t != -1:
    if t < l:
      l = t
    if ind < u:
      u = ind
    if ind > d:
      d = ind

for i in A:
  t = i.rfind('w')
  if t > r:
    r = t

ll = max( d - u, r - l ) + 1


x = u
y = l

if x + ll > n:
  if x - (x + ll - n) + ll > d:
    x = x - (x + ll - n)
  else:
    print -1
    exit()

if y + ll > m:
  if y - (y + ll - m) + ll > r:
    y = y - (y + ll - m)
  else:
    print -1
    exit()

if x >= 0 and y >= 0:
  pass
else:
  print -1
  exit()


def out():
  for i in A:
    print i

for i in [x, x + ll - 1]:
  A[i] = A[i][:y] + A[i][y:y+ll].replace('.', '+') + A[i][y+ll:]


for i in xrange(x+1, x+ll):
  A[i] = A[i][:y] + A[i][y].replace('.', '+') + A[i][y+1:y+ll-1] +A[i][y+ll-1].replace('.', '+') +  A[i][y+ll:]

out()
