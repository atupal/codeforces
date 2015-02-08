
n = int(raw_input())

a = map(int, raw_input().split())

ans = 10000000000000
for i in xrange(1, n-1):
  t = a[i]
  a[i] = a[i-1]
  m = 0
  for j in xrange(n-1):
    if abs(a[j+1] - a[j]) > m:
      m = abs(a[j+1] - a[j])
  ans = min(ans, m)
  a[i] = t
print ans
