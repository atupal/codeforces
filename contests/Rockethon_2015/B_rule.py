



def cl(a):
  a = [0]+list(a)
  l = len(a)
  s = 0
  for i in xrange(1, l):
    for j in xrange(i, l):
      s += min(a[i:j+1])

  return s

import itertools

for x in xrange(1, 9):
  c = cl(xrange(1, x))
  cnt = 0
  for a in itertools.permutations(xrange(1,x)):
    if cl(a) == c:
      cnt += 1
      print a, '->', cl(a)
  print cnt, '*' * 50

exit(0)


maxn = 51

n, m = map(int, raw_input().split() )

p = [0] * 51
p[1] = 1
for i in xrange(2, maxn):
  p[i] = p[i-1] * i


def get(a, idx):
  l = len(a)
  if l == 1: 
    print a[0]
    return
  i = 1
  while i*p[l-1] < idx: i+=1
  i -= 1
  print a[i],
  a.remove(a[i])
  get( [_ for _ in a], idx - i*p[l-1])

get([_+1 for _ in xrange(n)], m)
