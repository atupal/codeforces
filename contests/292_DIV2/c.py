# -*- coding: utf-8 -*-

n = int(raw_input())
s = map( int, raw_input() )

d = {}

d[2] = [2]
d[3] = [3]
d[4] = [2,2,3]
d[5] = [5]
d[6] = [5, 3]
d[7] = [7]
d[8] = [2,2,2,7]
d[9] = [7, 3,3, 2]


out = []
for i in s:
  if i > 1:
    out.extend( d[i] )

out.sort(reverse=True)

print ''.join( map(str, out) )
