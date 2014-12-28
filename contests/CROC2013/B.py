s = raw_input().strip()

flag = 0
p = ''
for i in xrange(len(s)):
    if flag:
        if s[i] != '"':
            p += s[i]
        else:
            print '<%s>'%p
            flag = 0
            p = ''
    else:
        if s[i] == '"':
            flag = 1
        elif s[i] != ' ':
            p += s[i]
        else:
            if p.strip() != '':
                print '<%s>'%p
            p = ''

if p != '':print '<%s>'%p
