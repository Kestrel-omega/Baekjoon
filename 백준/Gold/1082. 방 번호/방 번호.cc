#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, P[10];
    string room_number;
    vector<pair<int, int>> price_num;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> P[i];
        price_num.push_back(make_pair(P[i], i));
    }
    cin >> M;

    sort(price_num.begin(), price_num.end());

    if(N==1) 
    {
        cout << "0\n";
        return 0;
    }

    if(price_num[0].second != 0)
    {
        int count = M/price_num[0].first;
        for(int i = 0; i < count; i++) room_number += to_string(price_num[0].second);
        M -= count*price_num[0].first;
    }
    else
    {
        int remainder = M - price_num[1].first;
        if (remainder < 0)
        {
            cout << "0";
            return 0;
        }
        room_number += to_string(price_num[1].second);
        int count = remainder / price_num[0].first;
        for (int i = 0; i < count; i++)
            room_number += to_string(price_num[0].second);
        M = remainder - count * price_num[0].first;      
    }

    for(int i = 0; i < room_number.size(); i++)
    {
        bool is_possible = false;
        int cursor = P[room_number[i]-'0'];
        for(int j = N-1; j >= 0; j--)
        {
            if(M-(P[j]-cursor) >= 0)
            {
                M -= P[j]-cursor;
                is_possible = true;
                room_number[i] = j+'0';
            }
            if(is_possible) break;
        }
        if(!is_possible) break;
    }

    cout << room_number << "\n";

    return 0;
}