
n = int(raw_input())

s1 = []
s2 = []
ss1 = 0
ss2 = 0

for i in xrange(n):
  x = raw_input()
  if int(x) > 0:
    ss1 += int(x)
    s1.append(int(x))
    last1 = 1
    last2 = 0
  else:
    ss2 += int(x[1:])
    s2.append(int(x[1:]))
    last1 = 0
    last2 = 1

a = (ss1, s1, last1)
b = (ss2, s2, last2)

if a > b:
  print 'first'
elif b > a:
  print 'second'
