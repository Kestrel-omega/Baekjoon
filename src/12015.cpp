/*
NlogN LIS Algorithm

1. create an vector of size N
2. push the first element of the array into the vector that too small to create a LIS
3. for the rest of the elements of the array, if the element is greater than the last element of the vector, push it into the vector
4. else, find the first element of the vector that is greater than the current element and replace it with the current element
5. the size of the vector is the length of the LIS
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int length = 0;
    int N;
    vector<int> A;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (i == 0)
        {
            A.push_back(temp);
            length++;
        }
        else
        {
            if (temp > A[length - 1])
            {
                A.push_back(temp);
                length++;
            }
            else
            {
                int start = 0;
                int end = length - 1;
                int mid;
                while (start <= end)
                {
                    mid = (start + end) / 2;
                    if (A[mid] < temp) start = mid + 1;
                    else end = mid - 1;
                }
                A[start] = temp;
            }
        }
    }

    cout << length << endl;
    
    return 0;
}