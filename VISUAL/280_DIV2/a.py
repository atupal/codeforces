
n = int(raw_input())


ans = 0
sum = 0
for i in xrange(1, n*10):
  sum += i
  ans += sum
  if ans > n:
    print i-1
    exit(0)
