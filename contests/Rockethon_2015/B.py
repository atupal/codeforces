
maxn = 51

n, m = map(int, raw_input().split() )

p = [0] * 51
p[n] = 1
for i in xrange(1, n):
  p[i] = 2**(n-i-1)



a = [_+1 for _ in xrange(n)]
i = 1
while m and i <= n:
  while m-p[i]>0:
    m -= p[i]
    p[i] = 0
    i+=1
  a.remove(i)
  print i,
  i += 1

a.sort(reverse=True)
print ' '.join(map(str, a))
