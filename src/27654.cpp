#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;
    double answer = 0;
    double sum_correct = 0;
    double sum_problem = 0;
    cin >> N >> X;

    vector<pair<double, int>> scores(N);

    for(int i = 0; i < N; i++)
    {
        int P, Q;
        cin >> P >> Q;
        scores[i] = {(double)P/Q, Q};
    }

    sort(scores.begin(), scores.end(), greater<pair<double, int>>());

    for(int i = 0; i < X; i++)
    {
        sum_correct += scores[i].first * scores[i].second;
        sum_problem += scores[i].second;
    }

    answer = sum_correct / sum_problem;

    cout << fixed << setprecision(7) << answer << endl;
    
    return 0;
}