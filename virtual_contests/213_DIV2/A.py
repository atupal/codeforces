
n,k = [ int(_) for _ in raw_input().split() ]

cnt = 0

def get(x):
  b = [1] * (k+1)
  while x:
    if x % 10 > k:
      return 0
    b[x % 10] = 0
    x /= 10
  if sum(b):
    return 0
  return 1

for i in xrange(n):
  cnt += get(int(raw_input()))

print cnt
