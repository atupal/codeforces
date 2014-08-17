
n = int(raw_input())

s = []

for i in xrange(n):
  s.append(map(int, raw_input().split()))

s.sort()

flag = 0

for i in xrange(n-1):
  if s[i][1] > s[i+1][1]:
    flag = 1
    break;

if n == 1 or not flag:
  print 'Poor Alex'
else:
  print 'Happy Alex'
