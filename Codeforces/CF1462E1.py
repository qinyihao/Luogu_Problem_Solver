t=int(input())
while(t):
    t-=1
    n=int(input())
    arr=list(map(int, input().split()))
    arr.sort()
    c=0
    j=0
    i=0
    while(i<n-2):
        if j<n and arr[j]-arr[i]<=2:
            j+=1
        else:
            if j-i>2:
                c+=(((j-i-2)*(j-i-1))//2)
            i+=1
        
    print(c)
