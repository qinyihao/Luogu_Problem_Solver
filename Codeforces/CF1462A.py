for _ in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	x,y=0,n-1
	while x<y:
		print(l[x],l[y],end=' ')
		x+=1
		y-=1
	if n%2==1:
		print(l[x],end=' ')
	print()
