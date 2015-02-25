# -*- coding: utf-8 -*-

a = raw_input()
b = raw_input()

s1 = 0
s2 = 0
for i in xrange(len(a)):
  t = 26**(len(a)-1-i)
  s1 += ( ord(a[i]) - ord('a') ) * t
  s2 += ( ord(b[i]) - ord('a') ) * t

if s1 < s2-1:
  s = s1 + 1
  ans = []
  for i in xrange(len(a)):
    ans.append( chr( ord('a') + s % 26) )
    s /= 26
  print ''.join(ans[::-1])
  exit(0)

print 'No such string'
