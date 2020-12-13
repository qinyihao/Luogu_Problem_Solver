#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
int n, score[1010], i;
ull ans;

int main(){
	cin >> n ;
	for(i=1; i<=n; i++)
		cin >> score[i];
	sort(score+1, score+n+1);
	for(i=2; i<=n-1; i++)
		ans += score[i];
	cout << fixed << setprecision(2) << (double)ans/(n-2) << endl;
	return 0;
}
