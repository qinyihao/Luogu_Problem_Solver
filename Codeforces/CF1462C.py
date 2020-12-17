t=int(input())
for i in range(t):
	x=int(input())
	if(x>45):
		print(-1)
	else:
		s=''
		curr=9
		while(x>0):
			if((x-curr)>=0):
				x-=curr
				s+=str(curr)
			curr-=1
		print(s[::-1])
