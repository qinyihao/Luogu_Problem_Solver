for _ in range(int(input())):
    c = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    if all(c[i]-a[i]>=0 for i in range(3)) and sum(c)>=sum(a):
        if max(0,a[0]+a[3]-c[0])+max(0,a[1]+a[4]-c[1])<=c[2]-a[2]:
            print('YES')
            continue
    print('NO')
