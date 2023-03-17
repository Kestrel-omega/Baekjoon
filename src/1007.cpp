#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

pair<int, int> coordinate_point_x_y[21];
vector<vector<int>> minus_vectors;
vector<int> arr, comb;

int N, idx, depth;
double result;

void combination(vector<int> arr, vector<int> comb, int R, int idx, int depth)
{
    if (R == 0) minus_vectors.push_back(comb);
    else if (depth == arr.size()) return;
    else
    {
        comb[idx] = arr[depth];
        combination(arr, comb, R - 1, idx + 1, depth + 1);
        combination(arr, comb, R, idx, depth + 1);
    }
}

double calculate(vector<int> minus_vector, int n)
{
    bool is_calculated[21] = {false, };

    int x = 0;
    int y = 0;

    for (int i = 0; i < minus_vector.size(); i++)
    {
        int idx = minus_vector[i];
        is_calculated[idx] = true;

        x -= coordinate_point_x_y[idx].first;
        y -= coordinate_point_x_y[idx].second;
    }

    for (int i = 0; i < n; i++)
    {
        if (is_calculated[i] == false)
        {
            x += coordinate_point_x_y[i].first;
            y += coordinate_point_x_y[i].second;
        }
    }

    return sqrt((double)x * (double)x + (double)y * (double)y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        arr.clear();
        comb.clear();
        minus_vectors.clear();
        result = 1e300;
        idx = 0;
        depth = 0;

        int N;
        cin >> N;
        int R = N / 2;

        arr.resize(N);
        comb.resize(R);

        for (int i = 0; i < N; i++)
        {
            int x, y;
            cin >> x >> y;
            coordinate_point_x_y[i] = make_pair(x, y);
            arr[i] = i;
        }
        
        combination(arr, comb, R, idx, depth);

        for (int i = 0; i < minus_vectors.size(); i++)
        {
            double temp = calculate(minus_vectors[i], N);
            result = min(result, temp);
        }

        cout << fixed;
        cout.precision(7);
        cout << result << "\n";
    }

    return 0;
}