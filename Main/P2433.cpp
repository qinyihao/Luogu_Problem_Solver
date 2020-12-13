#include<bits/stdc++.h>
using namespace std;
const double pi=3.141593;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout<<14/4<<endl<<14-14/4+1<<endl<<14%4;
    } else if (T == 4) {
        printf("%.3lf",500.0/3);
    } else if (T == 5) {
        cout<<(260+220)/(12+20);
    } else if (T == 6) {
        cout<<sqrt(6*6+9*9);
    } else if (T == 7) {
        cout<<100+10<<endl<<100+10-20<<endl<<0;
    } else if (T == 8) {
        cout<<pi*10<<endl<<pi*25<<endl<<500*1.0/3*pi<<endl;
    } else if (T == 9) {
        cout<<(((1+1)*2+1)*2+1)*2;
    } else if (T == 10) {
        double v=7.5;
        double s=(8-v)*30;
        cout<<1.5+v;
    } else if (T == 11) {
        cout<<100.0/(8-5);
    } else if (T == 12) {
        cout<<13<<endl<<"R";
    } else if (T == 13) {
        cout<<16;
    } else if (T == 14) {
        cout<<50;
    }
    return 0;
}
