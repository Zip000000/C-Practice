list=[]
l1=[]
l1pos=[]
l2=[]
l2pos=[]
for x in raw_input().split(' '):
    list.append(int(x))
cnt=1
for i in list:
    if cnt % 3 == 0:
        l1.append(i)
        l1pos.append(cnt)
    if cnt % 3 != 0 and cnt % 2 == 0:
        l2.append(i)
        l2pos.append(cnt)
    cnt+=1

l1.sort(reverse=True)
l2.sort()
cnt=0
for i in l1pos:
    list[i-1]=l1[cnt]
    cnt+=1
cnt=0
for i in l2pos:
    list[i-1]=l2[cnt]
    cnt+=1
strl=str(list)
strl=strl.replace("[", "")
strl=strl.replace("]", "")
strl=strl.replace(",", "")
print strl
