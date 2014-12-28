

n,m,a,b = map(int, raw_input().split())


ans = 0
if (b+m-1) / m <= a:
    ans += (n/m)*b
    if n%m and n%m*a < b:
        ans += n%m*a
    elif n%m:
        ans += b
else:
    ans = n*a

print ans
