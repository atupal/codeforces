

def gcd(a, b):
    return b if a % b == 0 else gcd(b, a % b)



t = raw_input().split(' ')
n = int(t[0])
m = int(t[1])
x = int(t[2])
y = int(t[3])
a = int(t[4])
b = int(t[5])

t = gcd(max(a, b), min(a, b))
a /= t
b /= t

t = min(n / a, m / b)
a *= t
b *= t

dx = min(n - x, a / 2)
dx = a - dx

dy  = min(m - y, b / 2)
dy = b - dy

print max(x - dx, 0), max(y - dy, 0), max(x - dx , 0)+ a, max(y - dy, 0) + b
