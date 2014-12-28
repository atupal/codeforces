n = int(raw_input())
s = raw_input()
t = raw_input()

cnt_s = s.count('1')
cnt_t = t.count('1')
cnt = 0

for i in xrange(n * 2):
    if s[i] == '1' and t[i] == '1':
        cnt += 1
cnt_s -= cnt
cnt_t -= cnt

res_s = (cnt + 1) / 2
res_t = cnt - res_s

m = min(cnt_s, cnt_t)
res_s += m
res_t += m

cnt_s -= m
cnt_t -= m

res_s += (cnt_s + (1 if cnt & 1 == 0 else 0)) / 2
res_t += (cnt_t + (1 if cnt & 1 else 0))/ 2

print "First" if res_s > res_t else "Second" if res_s < res_t else "Draw"

