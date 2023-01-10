#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> account_book;
    int K;
    int sum = 0;

    cin >> K;

    while(K--)
    {
        int temp;
        cin >> temp;
        if(temp == 0 && account_book.size()) account_book.pop();
        else account_book.push(temp);
    }

    while(account_book.size())
    {
        sum += account_book.top();
        account_book.pop();
    }
    
    cout << sum << "\n";

    return 0;
}