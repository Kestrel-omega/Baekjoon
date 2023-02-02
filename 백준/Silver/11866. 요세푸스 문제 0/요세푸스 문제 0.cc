#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> array;

    for(int i = 1; i <= N; i++) array.push_back(i);

    cout << "<";

    int count = 0;

    while(array.size() > 0)
    {
        if(count >= array.size()) count = 0;
        for(int i = 0; i < K-1; i++)
        {
            count++;
            if(count >= array.size()) count = 0;
        }
        
        // cout << ">> ";
        // for(int i = 0; i < array.size(); i++) cout << array[i] << " ";
        // cout << endl;

        cout << array[count];
        if(array.size() != 1) cout << ", ";
        array.erase(array.begin() + count);

        
    }
    cout << ">";

    return 0;
}