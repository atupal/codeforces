while 1:
  s=raw_input()
  
  
  ans=''
  l = len(s)
  i = j = 0
  while i<l:
    j=i
    while j+1 < l and s[j+1]==s[j]:
      j+=1
    if j-i+1>1:
      if j+1<l and j+2<l and s[j+1]==s[j+2]:
        ans += s[j]
      else:
        ans += s[j]*2
    else:
      ans += s[j]
  
    i=j+1
  
  print ans
