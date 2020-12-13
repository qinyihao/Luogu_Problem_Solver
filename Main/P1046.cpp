#include<bits/stdc++.h>
using namespace std;
int main(){
	int apples[10];
	int high;
	int count = 0;
	int i = 0;
	for (i; i < 10; i++){
		cin >> apples[i];
	}
	cin >> high;
	high = high + 30;
	for(i = 0; i < 10; i++){
		if (apples[i] <= high){
			count++;
		}
	}
	cout << count;
  return 0;
}
