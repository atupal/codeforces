
tname = {
    'h': raw_input(),
    'a': raw_input(),
    }

n = int(raw_input())

r = {}
y = {}

s = [[] for i in xrange(100)] 
for i in xrange(n):
  s[i].append(raw_input())

h = set()

for i in xrange(n):
  for string in s[i]:
    time, name, num, color = string.split()
    if color == 'r':
      if name+num not in h:
        print tname[name], num, time
        h.add(name+num)
    else:
      key = name+num
      if key in y:
        y[key] += 1
      else:
        y[key] = 1
      if y[key] == 2:
        if key not in h:
          print tname[name], num, time
          h.add(key)
