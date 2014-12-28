

s = raw_input()

k = int(raw_input())

n = len(s)

if k >= n:
  print (k+n)/2
  exit(0)


ans = 0

for i in xrange(n):
  j = 2
  while 1:
    if i+j >= n:
      break

    if s[i:i+j/2].startwith(s[i+j/2,i+j]):
      ans = max(ans, j/2)

    j += 2

print ans
