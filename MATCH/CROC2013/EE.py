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

def get_jump(s):
    j = -1
    p = [-1 for _ in xrange(len(s))]
    for i in xrange(1, len(s), 1):
        while j > -1 and s[i] != s[j + 1]:
            j = p[j]
        if s[i] == s[j + 1]:
            j = j + 1
        p[i] = j
    return p


ans = 0
n = int(raw_input())
child = [[] for i in xrange(n + 1)]
word = ['' for i in xrange(n + 1)]
for i in xrange(n - 1):
    t = raw_input().split(' ')
    child[int(t[0])].append(i + 2)
    word[i + 2] = t[1]

pat =  raw_input()
jump = get_jump(pat)
m = len(pat)
stack = []
stack.append((1, -1))

while stack != []:
    node, j = stack.pop()
    jj = j
    for x in child[node]:
        j = jj
        for w in word[x]:
            while j > -1 and  w != pat[j + 1]:
                j = jump[j]
            if w == pat[j + 1]:
                j += 1
            if j == m - 1:
                ans += 1
                j = jump[j]
        stack.append((x, j))

print ans


