#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long
#define N 100010
#define M 1010

using namespace std;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int q, n;
int yu[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int read() {
  int s = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}

void work1() {
  int year = -4712, mon = 1, day = 1, t = n / (365 * 3 + 366);
  year += t * 4, n -= t * (365 * 3 + 366);
  for (int i = 1; i <= 3; i++) {
    int res = 365 + (year % 4 == 0);
    if (n >= res) year++, n -= res;
    else break;
  }
  for (int i = 1; i <= 12; i++) {
    int res = yu[i] + (i == 2 && (year % 4 == 0));
    if (res <= n) mon++, n -= res;
    else break;
  }
  if (year <= 0) cout << day + n<< " " << mon << " " << 1 - year << " BC\n";
  else cout << day + n << " " << mon << " " << year << "\n";
}

void work2() {
  int year = 1582, mon = 10, day = 15;
  if (n <= 16) {
    cout << day + n << " " << mon << " " << year << "\n";
    return ;
  }
  mon++, day = 1, n -= 17;
  if (n < 30) {
    cout << day + n << " " << mon << " " << year << "\n";;
    return;
  }
  mon++, n -= 30;
  if (n < 31) {
    cout << day + n << " " << mon << " " << year << "\n";;
    return;
  }
  mon = 1, n -= 31, year++;
  
  int per = (97 * 366 + 303 * 365);
  int t = n / per;
  n -= per * t, year += t * 400;
  for (int i = 1; i <= 400; i++) {
    int res = 365 + (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0));
    if (n >= res) year++, n -= res;
    else break;
  }
  for (int i = 1; i <= 12; i++) {
    int res = yu[i] + (i == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)));
    if (n >= res) mon++, n -= res;
    else break; 
  }
  cout << day + n << " " << mon << " " << year << "\n";
}

signed main() {
  //freopen("julian.in", "r", stdin);
  //freopen("julian.out", "w", stdout);
  q = read();
  for (int i = 1; i <= q; i++) {
    n = read();
    if (n <= 2299160) work1(); 
    else n -= 2299161, work2();
  }
}
