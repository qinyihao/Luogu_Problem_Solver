#include<bits/stdc++.h>

#define fi first

#define sc second

#define N 1000005

using namespace std;

typedef pair<int , int> II;

typedef pair<int , char> IC;

typedef pair<II , int> III;

typedef pair<II , II> IV;

typedef pair<int , long long> IL;

typedef pair<long long , int> LI;

typedef pair<IL , int> ILI;

int amount;

int val[N] , pre[N];

void solve()
{
    for(int i = 2; i <= amount; i++){

        printf("XOR 1 %d\n", i );

        fflush( stdout );

        scanf("%d", &val[i] );
    }

    bool is_found = false;

    for(int i = 2 ;i <= amount; i++){

        if( pre[ val[i] ] ){

            printf("AND %d %d\n", pre[ val[i] ] , i );

            fflush( stdout );

            int num; scanf("%d", &num );

            val[1] = val[i] ^ num;

            is_found = true;

            break;
        }

        else pre[ val[i] ] = i;
    }

    if( !is_found ){

        if( !pre[ amount - 1 ] ){

            val[1] = amount - 1;

            goto L1;
        }

        int nex_now = 2 + ( pre[ amount - 1 ] == 2 );

        printf("AND 1 %d\n", nex_now ); fflush( stdout );

        int fir_and_nex; scanf("%d", &fir_and_nex );

        printf("AND %d %d\n", nex_now , pre[ amount - 1 ] ); fflush( stdout );

        int nex_and_last; scanf("%d", &nex_and_last );

        int fir_plus_nex = val[nex_now] + 2*fir_and_nex;

        int nex_plus_last = ( val[nex_now] ^ val[ pre[amount - 1] ] ) + 2*nex_and_last;

        int nex_val = ( fir_plus_nex + nex_plus_last - amount + 1 ) / 2;

        val[1] = nex_val ^ val[ nex_now ];
    }

    L1:;

    for(int i =2 ;i <= amount; i++)

        val[i] = val[i] ^ val[1];

    printf("! ");

    for(int i =1 ;i <= amount; i++)

        printf("%d ", val[i] );

        /// 1 0 2 3
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    scanf("%d", &amount );

    solve();
}
