#include <iostream>
using namespace std;

int main()
{
    int b=0,g=0;
    string str;
    cin >> str;
    for(int i = 0;i < str.length();i++)
    {
        if(str[i] == 'b' || str[i+1] == 'o' || str[i+2] == 'y')  b++;
        if(str[i] == 'g' || str[i+1] == 'i' || str[i+2] == 'r' || str[i+3] == 'l')  g++;
    }

    cout << b << endl << g << endl;
}
