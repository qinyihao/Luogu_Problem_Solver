#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> se;
	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++)
			se.insert(v[i] + v[j]);
	int Count = 0;
	for (int i = 0; i < v.size(); i++)
		if (se.find(v[i]) != se.end())
			Count++;
	cout << Count;
	return 0;
}
