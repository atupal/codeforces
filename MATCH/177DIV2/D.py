
s = raw_input()
s = s.split(' ')
n = int(s[0])
k = int(s[1])
mod = 1000000007
print (k ** (k - 1) % mod * (n - k) ** (n - k) % mod) % mod
