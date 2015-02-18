# -*- coding: utf-8 -*-

a, b, s = map(int, raw_input().split())


t = s-(abs(a)+abs(b))

if t<0:
  print 'NO'
elif t%2==0:
  print 'YES'
else:
  print 'NO'
