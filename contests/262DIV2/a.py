
n,m = map(int, raw_input().split())

ans = 0
cnt = n
while cnt:
  ans += 1
  cnt -= 1
  if ans % m == 0:
    cnt += 1

print ans
