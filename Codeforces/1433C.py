for _ in range(int(input())):
	n = int(input())
	r = [int(i) for i in input().split()]
	o = max(r)
	if r.count(o)==len(r):
		print(-1)
		continue
	kq = -1
	for i in range(1,len(r)):
		if r[i]==o and (r[i]>r[i-1]):
			kq = i+1
	for i in range(len(r)-1):
		if r[i]==o and(r[i]>r[i+1]):
			kq = i+1
	print(kq)
