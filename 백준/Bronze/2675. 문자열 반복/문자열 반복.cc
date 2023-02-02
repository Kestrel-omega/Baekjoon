#include <iostream>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, r;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> r >> s;
        for(int j = 0; j < s.length(); j++)
            for(int k = 0; k < r; k++)
                cout << s[j];
        cout<<'\n';
    }
}