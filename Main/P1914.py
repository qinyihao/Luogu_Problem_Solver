n=int(input())
s=input()

t=''
for i in range(len(s)):
    m=ord(s[i])+n
    while m>ord('z'):
        m=m-ord('z')+ord('a')-1
    t=t+chr(m)
print(t)
