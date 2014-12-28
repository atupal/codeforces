'''
7
1 ab
5 bacaba
1 abacaba
2 aca
5 ba
2 ba
aba
'''
ans = 0

def go(s):
    j = -1
    p = [-1 for _ in xrange(len(s))]
    for i in xrange(1, len(s), 1):
        while j > -1 and s[i] != s[j + 1]:
            j = p[j]
        if s[i] == s[j + 1]:
            j = j + 1
        p[i] = j
    return p

def match(x, s, p, go):
    global ans
    j = -1
    for i in xrange(len(s)):
        while j > -1 and s[i] != p[j + 1]:
            j = go[j]
        if s[i] == p[j + 1]:
            j += 1
        if j == len(p) - 1:
            t = get_index(x, i - j)
            if not vv[t[0] * n + t[1]]:
                ans += 1
            vv[t[0] * n + t[1]] = 1
            j = go[j]


n = int(raw_input())
p = [0 for i in xrange(n + 1)]
p[1] = 0
s = ['' for i in xrange(n + 1)]
s[1] = '#'
vis = [0 for i in xrange(n + 1)]

Max = 0

for i in xrange(n - 1):
    t = raw_input().split(' ')
    p[i + 2] = int(t[0])
    s[i + 2] = t[1]
    vis[int(t[0])] = 1
    Max = Max if Max > len(t[1]) else len(t[1])

vv = [0] * (n + 1) * Max

x = raw_input()
x = x[::-1]
jump = go(x)


vis[1] = 1
def get_line(x):
    ret = ''
    while x != 1:
        ret += s[x][::-1]
        x = p[x]
    return ret

def get_index(x, l):
    Len = 0
    while x != 1:
        Len += len(s[x])
        if Len >= l:
            return (x, Len - l)
        x = p[x]
    return x

for i in xrange(1, n + 1, 1):
    if not vis[i]:
        ret = get_line(i)
        match(i, ret, x, jump)

print ans
