n=int(raw_input())
number=[]
number=raw_input().split(' ')
target=int(raw_input())
for i in range(n):
    if str(target-int(number[i])) in number:
        print i+1, number.index(str(target-int(number[i])))+1
        break