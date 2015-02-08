




s = 0.
maxn = 10000
for i in xrange(1, maxn+1):
  s += 1.*i*(maxn-i+1)/maxn*  ((1.*i/maxn)**3)  /maxn * 20

print s
