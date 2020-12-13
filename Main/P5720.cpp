#include<cstdio>
int main()
{
    int a,num=1;
    scanf("%d",&a);
    while (a!=1)
    {
        a=int(a/2.0);
        num+=1;
    }
    printf("%d",num);
    return 0;
}
