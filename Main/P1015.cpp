#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string str;

bool isReverse(string str)
{
	string ss = str;
	reverse(ss.begin(), ss.end());
	if (ss == str)
		return true;
	return false;
}

short getnum(char ch)
{
	if (ch >= '0'&&ch <= '9')
		return ch - '0';
	return ch - 'A' + 10;
}

char getch(short int n)
{
	if (n >= 0 && n <= 9)
		return n + '0';
	return n - 10 + 'A';
}

string add(string tmp)
{
	string rtmp = tmp;
	int rst[200];
	memset(rst, 0, sizeof(rst));
	reverse(rtmp.begin(), rtmp.end());
	int cnt = 0, x1, x2;
	for (int i = 0; i < rtmp.length(); i++)
	{
		x1 = getnum(tmp[i]);
		x2 = getnum(rtmp[i]);
		rst[cnt + 1] += (rst[cnt] + x1 + x2) / n;
		rst[cnt] = (rst[cnt] + x1 + x2) % n;
		cnt++;
	}
	if (rst[cnt] != 0)
		cnt++;
	string ans;
	for (int i = cnt-1; i >= 0; --i)
		ans += getch(rst[i]);
	return ans;
}

int main()
{
	cin >> n >> str;
	int step = 0;
	while (!isReverse(str) && step <= 30)
	{
		step++;
		str = add(str);
	}
	if (step <= 30)
		cout << "STEP=" << step;
	else
		cout << "Impossible!";
	cin >> n;
	return 0;
}
