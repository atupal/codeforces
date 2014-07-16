


ss = raw_input()

for i in xrange(26):
  exec(chr(ord('a')+i) + '=%d'%i)

exec("sss=%s" % ss)
print len(sss)
