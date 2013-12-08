n,m,a = [int(_) for _ in raw_input().split()]
b = [int(_) for _ in raw_input().split()]
b=[-1] + b
p = [int(_) for _ in raw_input().split()]
p=[-1] + p
b.sort()
p.sort()

r = [0] * (n+2)
s = [0] * (n+2)
mon = [0] * (n+2)

r[0] = 0
s[0] = a
mon[0] = 0

if s[0] + b[1] >= p[1]:
  r[1] = 1
  s[1] = s[0] - max(0, p[1] - b[1])
  mon[1] = mon[0] + min(p[1], b[1])

#print 1,":",r[1],s[1]
for i in xrange( 2, n+1, 1 ):
    if r[i-1] >= m:
      r[i] = r[i-1]
      s[i] = s[i-1]
      mon[i] = mon[i-1]
    elif s[i-1] + b[i] >= p[ r[i-1]+1 ]:
      r[i] = r[i-1] + 1
      s[i] = s[i-1] - max( 0, p[ r[i-1]+1 ] - b[i] )
      mon[i] = mon[i-1] + min( p[ r[i-1]+1 ] , b[i])
    else:
      t=i-2
      while t>=0 and r[t] == r[i-1]:t-=1
      if s[t] + b[i] >= p[ r[t]+1 ] and s[t] - max(0, p[ r[t]+1 ] - b[i]) > s[i-1]:
        r[i] = r[t] + 1
        s[i] = s[t] - max(0, p[ r[t]+1 ] - b[i])
        mon[i] = mon[t] + min( p[ r[t]+1 ] , b[i])
      else:
        r[i] = r[i-1]
        s[i] = s[i-1]
        mon[i] = mon[i-1]
    #print i,":" ,r[i], s[i]

print r[n], max(0, mon[n]-s[n])

"""
r=s=0

i=j=0
while i < n and j < m:
  ss=min(0, b[i]-p[j])
  if a+ss>=0:
    r+=1
    s+=min(b[i], p[j])
    a+=ss
    j+=1
  i+=1

print r,s-a
"""
