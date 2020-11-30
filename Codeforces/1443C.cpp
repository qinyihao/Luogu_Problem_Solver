#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxN = 1e5 + 7;
const ll MOD = 1e9 + 7;

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}
 
ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x + MOD : x;
}
 
ll mul(ll A, ll B) {
	return (A * B) % MOD;
}
 
ll add(ll A, ll B) {
	return (A + B) % MOD;
}
 
ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}
 
ll sub(ll A, ll B) {
    return (A - B + MOD) % MOD;
}

bool isPowerOfTwo (int x) {
	return x && (!(x & (x - 1)));
}

void findPowerSet(vector<int> const &S, int n)
{
	// N stores total number of subsets
	int N = pow(2, n);

	// generate each subset one by one
	for (int i = 0; i < N; i++)
	{
		// check every bit of i
		for (int j = 0; j < n; j++)
		{
			// if j'th bit of i is set, print S[j]
			if (i & (1 << j))
				cout << S[j] << " ";
		}
		cout << endl;
	}
}

ll findSubarraySum(vector<int> arr, int n) {
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    vector<ll> prevSum;
 
    ll res = 0;

	int currN = 0;
    // Sum of elements so far.
    ll currsum = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Add current element to sum so far.
        currsum += arr[i];		
        if (currsum == 0) {	
            res++;			
			currsum = 0;
			currN = i;
			i--;
		}
        else if (find(prevSum.begin() + currN, prevSum.end(), currsum) != prevSum.end()) {
            res++;			
			currsum = 0;
			currN = i;
			i--;	
		}
		else {
        	prevSum.push_back(currsum);
		}
    }
 
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//TAKE MODULO FACTORIAL !!!
	//BINARY SEARCH RUN
	//ALWAYS CHECK FOR OUT OF BOUNDS
	
	int t;
  	cin >> t;
  	while (t--) {
		int n;
		cin >> n;
		vector<array<ll,2>> a(n);
		for (int i = 0; i < n; i++) cin >> a[i][0];
		for (int i = 0; i < n; i++) cin >> a[i][1];
		sort(a.begin(), a.end());
		ll sum = 0;
		ll ans = 1e18;
		for (int i = n-1; i >= 0; i--) {
			ans = min(ans, max(a[i][0], sum));
			sum += a[i][1];
		}

    cout << min(ans,sum) << endl;
  }
}
