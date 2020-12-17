for _ in range(int(input())):
    n=int(input())
    s=input()
    for i in range(5):
        
        if s[0:i]+s[n-(4-i):n]=='2020':
            print('YES')
            break
    else:
        print('NO')
