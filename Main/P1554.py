s=input().split();k='';kk=''
for i in range(int(s[0]),int(s[1])+1):
    kk=str(i)
    k=k+kk
print(k.count('0'),k.count('1'),k.count('2'),k.count('3'),k.count('4'),k.count('5'),k.count('6'),k.count('7'),k.count('8'),k.count('9'))
