r1, c1, r2, c2 = [int(_) for _ in raw_input().split()]

if r1 == r2 or c1 == c2:
  print 1,
else:
  print 2,


ll = max(abs(r1-r2), abs(c1-c2)) + 1
ss = min(abs(r1-r2), abs(c1-c2)) + 1

rr = (ll --ss) / (ss - 1)

if ((rr+1) % 2) ** ss == ss:
  print 1 + rr,
else:
  print 0,

#if abs(r1 - r2) == abs(c1 - c2):
#  print 1,
#else:
#  print 0,
#

print max( abs(r1 - r2), abs(c1 - c2) )

