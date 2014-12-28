
def get(aa, b, n):
  ret = 1
  tmp=aa
  while b:
    if b&0x1:ret=ret*tmp%n
    tmp = tmp*tmp%n
    b >>=1
  return ret


n,x = [int(_) for _ in raw_input().split()]
s = [int(_) for _ in raw_input().split()]

MOD=1000000007 
ans=0

sum_ = sum(s)
sed = [sum_ - _ for _ in s]
a = [1] * len(sed)



while 1:
  l = min(sed)

  #for i in xrange(l):
  #  ans *= (x % MOD)
  #  ans %= MOD
  #ans *= get(x, l, MOD)
  if sum_ - l < 0:
    ans += sum_
    break
  else:
    ans += l
    sum_ -= l
  #ans %= MOD

  for i in xrange(len(sed)):
    sed[i] -= l

  remain = 0
  remove = []
  for i in xrange(len(sed)):
    if sed[i] == 0:
      remove.append(i)
      remain += a[i]

  for i in remove[::-1]:
    sed.pop(i)
    a.pop(i)

  ts = 0
  while remain % x == 0:
    ts += 1
    remain /= x

  if not ts:
    break

  sed.append(ts)
  a.append(remain)


print get(x, ans, MOD)
