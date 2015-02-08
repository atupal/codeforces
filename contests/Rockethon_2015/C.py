
n = int(raw_input())

s = []

x = []

for i in xrange(n):
  l, r = map( int, raw_input().split() )
  s.append( [l, r] )
  x.append(l)
  x.append(r)

x.sort()


ans = 0.
interval = []
def dfs(idx, prob):
  if idx == n:
    global ans
    tmp = [i for i in interval]
    tmp.sort(reverse=True)

    if tmp[0] != tmp[1]:
      ans += prob*sum(tmp[1])/2
    else:
      i = 1
      while i+1 < n and tmp[i+1] == tmp[i]: i+=1
      l, r = tmp[0]
      print l, r
      if l == r:
        ans += prob*l
        return
      c = 0.
      for j in xrange(l, r+1):
        c += 1.*j*(r-j+1)/(r-l+1)  * (j/(r-l+1)) ** (i-1)  / (r-l+1)  * (i+1)*(i)/2
      print c
      ans += prob*c
    return
  l, r = s[idx]
  p = set()
  p.add(l)
  p.add(r)
  for i in x:
    if i >= l and i <= r:
      p.add(i)
  p = list(p)
  p.sort()
  for i in xrange(1, len(p)):
    sel = [ p[i-1], p[i]-1 ]
    interval.append(sel)
    dfs( idx+1, prob*(p[i]-p[i-1])/(r-l+1) )
    interval.pop()

  sel = [ p[-1], p[-1] ]
  interval.append(sel)
  dfs(idx+1,  prob/(r-l+1))
  interval.pop()

dfs(0, 1.)

print ans
