# -*- coding: utf-8 -*-

import sys
reload(sys)
#sys.setdefaultencoding("utf-8")


s = input().strip()

# columm是w位的字符串


for i in range(len(s)+1):
  for j in range(26):
    l = [ _ for _ in s ]
    l.insert(i, chr( ord('a') + j))
    if ''.join( l[:len(l)/2] ) == ''.join( l[::-1][:len(l)/2] ):
      print (''.join(l))
      exit(0)

print ('NA')
