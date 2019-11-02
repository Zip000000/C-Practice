m, n = 0, 1
list=[0]
cnt=0
while cnt < 52:
    list.append(n)
    m, n = n, m + n
    cnt+=1
a = raw_input()
print list[int(a)]