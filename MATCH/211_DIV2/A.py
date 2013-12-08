n = int(raw_input())



m = [
    'O-|-OOOO',
    'O-|O-OOO',
    'O-|OO-OO',
    'O-|OOO-O',
    'O-|OOOO-',
    '-O|-OOOO',
    '-O|O-OOO',
    '-O|OO-OO',
    '-O|OOO-O',
    '-O|OOOO',
    ]

if n==0:
  print m[0]

while n:
  print m[ n%10 ]
  n/=10

