#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(void)
{
    string a;
    cin >> a;
    string b;
    int c;

    for(int i=0;i<a.size()-1;++i)
    {
        b = a.substr(i,i+1);
        cout<<b<<endl;
        c = atoi(b.c_str());
        cout << c << " ";
    }
    cout << endl;
    string sa,ss;
    cin>>ss>>sa;
    ss.swap(sa);
    ss.reverse(5);
    cout<<ss<<endl;
    cout<<sa<<endl;
    return 0;
}
