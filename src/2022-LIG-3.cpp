#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fold(vector<int> paper, int fold_idx)
{
    vector<int> folded_paper;
    int paper_length = (int)paper.size();

    if (fold_idx * 2 <= paper_length) // 중간 이전에서 접기
    {
        int i, num;
        for (i = fold_idx; i < fold_idx * 2; i++)
        {
            num = paper[i] + paper[fold_idx * 2 - 1 - i];
            folded_paper.push_back(num);
        }
        for (i; i < paper_length; i++)
        {
            num = paper[i];
            folded_paper.push_back(num);
        }
    }
    else // 중간 이후에서 접기
    {
        int i, num;
        for (i = 0; i < fold_idx * 2 - paper_length; i++)
        {
            num = paper[i];
            folded_paper.push_back(num);
        }
        for (i; i < fold_idx; i++)
        {
            num = paper[i] + paper[fold_idx * 2 - 1 - i];
            folded_paper.push_back(num);
        }
    }

    // printf("접은 결과 : [ ");
    // for (int i; i < (int)folded_paper.size(); i++)
    //     printf("%d ", folded_paper[i]);
    // printf("]\n");

    return folded_paper;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int folding_num, paper_length;
    int num;
    int loop = 0;

    while (1)
    {
        vector<int> paper;
        vector<int> folded_paper;
        vector<vector<int>> paper_results;

        printf("데이터 (종이 길이, 접을 횟수, 종이에 적힌 숫자) : ", ++loop);
        cin >> paper_length;

        if (paper_length < 0)
            return -1;
        cin >> folding_num;
        if (folding_num > 4 || folding_num < 0)
            return -1;
        for (int i = 0; i < paper_length; i++)
        {
            cin >> num;
            paper.push_back(num);
        }

        int max = *max_element(paper.begin(), paper.end());

        printf("Loop %d = 종이의 길이 : %d, 접을 횟수 : %d, 종이에 적힌 숫자 : [ ", loop, paper_length, folding_num);
        for (int i = 0; i < paper_length; i++)
        {
            printf("%d ", paper[i]);
        }
        printf("]\n");

        int max_idx = 0;

        paper_results.push_back(paper);

        while (folding_num)
        {
            vector<vector<int>> temp_paper_results;
            for (int i = 0; i < (int)paper_results.size(); i++)
            {
                for (int j = 1; j < (int)paper_results[i].size(); j++)
                {
                    // printf("접은 위치 : %d, ", j);
                    folded_paper = fold(paper_results[i], j);
                    int max_paper = *max_element(folded_paper.begin(), folded_paper.end());
                    if (max < max_paper)
                        max = max_paper;
                    temp_paper_results.push_back(folded_paper);
                }
            }
            paper_results = temp_paper_results;
            folding_num--;
        }

        printf("최댓값 : %d\n", max);
    }

    return 0;
}