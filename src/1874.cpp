#include <iostream>
#include <bits/stdc++.h>

using namespace std;
stack<int> stk;

unsigned multiple(unsigned n)
{
    unsigned sum = 1;
    for (int i = 0; i < n; i++)
        sum = sum * 2;
    return sum;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned n, i = 0, j = 0, num = 1; // n은 문제에서 주어진 n, i와 j는 각각 arr과 pnt의 인덱스, num은 반복문에 의해 1부터 n까지 1씩 차례대로 증가합니다.
    cin >> n;                          // n을 입력받습니다. (예 : 8)
    unsigned arr[n] = {
        0,
    };                        // arr 배열은 입력받을 수열을 저장하는 배열입니다.
    bool error = 0, over = 0; // 아래 반복문에서 arr에 최댓값인 n과 num이 마주치면 그 이후부터는 over 가 1이 됩니다.
    char pnt[multiple(n)];    // +와 -를 저장하기 위한 배열입니다.

    for (unsigned o = 0; o < n; o++)
        scanf("%u", arr + o); // 배열에 수열을 입력합니다.

    while (i != n) // i는 arr의 인덱스입니다. 수열 arr의 끝에 도달하는 순간 반복문은 종료됩니다.
    {
        if (num <= n) // 현재 num이 n보다 작으면 무조건 스택에 push 및 + 기록
        {
            stk.push(num);
            pnt[j] = '+';
            j++;
        }
        else // 수열 arr에서 n이 등장한 이후부터는 push하지 않고 뺄 일만 남음.
        {    // Over = 1
            over = 1;
        }
        if (arr[i] == stk.top()) // 최상단 수가 현재 i번째 수열의 원소와 같다면
        {
            while (!stk.empty() && (arr[i] == stk.top())) // i를 움직이며 최상단이 수열의 원소와 같아지지 않을 때까지 i를 움직이며 계속 pop
            {
                stk.pop();
                pnt[j] = '-';
                j++;
                i++;
            }
            if (over && (i != n))
            {
                error = 1;
                break;
            } // Over 이후에 나오는 모든 수열의 원소들은 스택에 순서대로 배치되어 있어야만 함. 그렇지 못하다면 이 if문을 읽고 error처리

            if (!over)
                num++; // Over가 아니면 num 증가, 다음 while 루프로 진행
        }
        else
            num++; // 최상단 수가 i번째 수열의 원소와 다르다면 num 증가후 다음 루프로 진행
    }

    // 아래는 출력 코드입니다.
    if (error)
        cout << "NO" << '\n';

    else
    {
        for (int k = 0; k < i; k++)
        {
            cout << pnt[k] << '\n';
        }
    }
}