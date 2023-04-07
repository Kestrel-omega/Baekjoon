#include <iostream>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        long long N;
        int ans = 0;
        cin >> N;
        
        for(int i = 0; i < 9; i++) 
        {
            if (N == 0) break;
            int cost = N % 100;
            N /= 100;

            if(cost % 25 == 0) ans += cost / 25;
            else if (cost < 25)
            {
                ans += cost / 10;
                ans += cost % 10;
            }
            else
            {
                switch(cost/5)
                {
                case 6:
                case 8:
                case 11:
                case 13:
                case 16:
                case 18:
                    ans += (cost / 25 - 1);
                    cost = cost % 25 + 25;
                    ans += cost / 10;
                    ans += cost % 10;
                    break;
                default:
                    ans += cost / 25;
                    cost = cost % 25;
                    ans += cost / 10;
                    ans += cost % 10;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}