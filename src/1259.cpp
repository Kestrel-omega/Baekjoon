#include <iostream>
#include <string>

using namespace std;

int main()
{
    string palindrome;
    while(1)
    {

        bool check_palindrome = true;
        cin >> palindrome;
        if(palindrome == "0") break;
        int size_palindrome = palindrome.size();
        for(int i = 0; i < size_palindrome/2; i++)
        {
            if(palindrome[i] != palindrome[size_palindrome-i-1]) 
            {
                check_palindrome = false;
                break;
            }
        }
        if(check_palindrome == true) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}