
n = int(raw_input())

t = map(int, raw_input().split())

t1 = t.count(1)
t2 = t.count(2)
t3 = t.count(3)


cnt1 = 0
cnt2 = 0
cnt3 = 0
cnt = min(t1, t2, t3)
print cnt

out = [['', '', ''] for i in xrange(cnt)]

for i in xrange(n):
  if cnt1 < cnt and t[i] == 1:
    out[cnt1][0] = str(i+1)
    cnt1 += 1
  if cnt2 < cnt and t[i] == 2:
    out[cnt2][1] = str(i+1)
    cnt2 += 1
  if cnt3 < cnt and t[i] == 3:
    out[cnt3][2] = str(i+1)
    cnt3 += 1

for w in out:
  print ' '.join(w)
