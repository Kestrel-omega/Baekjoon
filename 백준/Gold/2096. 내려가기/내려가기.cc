#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a,b,c;
    int dp_max[3] = {0,};
    int dp_min[3] = {0,};

    cin >> N;
    cin >> a >> b >> c;

    dp_max[0] = a;
    dp_max[1] = b;
    dp_max[2] = c;
    dp_min[0] = a;
    dp_min[1] = b;
    dp_min[2] = c;

    N--;

    while(N--)
    {
        cin >> a >> b >> c;

        int temp_max[3] = {0,};
        int temp_min[3] = {0,};

        temp_max[0] = max(dp_max[0], dp_max[1]) + a;
        temp_max[1] = max(dp_max[0], max(dp_max[1], dp_max[2])) + b;
        temp_max[2] = max(dp_max[1], dp_max[2]) + c;

        temp_min[0] = min(dp_min[0], dp_min[1]) + a;
        temp_min[1] = min(dp_min[0], min(dp_min[1], dp_min[2])) + b;
        temp_min[2] = min(dp_min[1], dp_min[2]) + c;

        for(int i = 0; i < 3; i++)
        {
            dp_max[i] = temp_max[i];
            dp_min[i] = temp_min[i];
        }
    }

    int max_value = max(dp_max[0], max(dp_max[1], dp_max[2]));
    int min_value = min(dp_min[0], min(dp_min[1], dp_min[2]));

    cout << max_value << ' ' << min_value;

    
    return 0;
}