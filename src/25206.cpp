#include <iostream>
#include <string>

using namespace std;

float score_to_point(string score)
{
    if(score == "A+") return 4.5;
    else if(score == "A0") return 4.0;
    else if(score == "B+") return 3.5;
    else if(score == "B0") return 3.0;
    else if(score == "C+") return 2.5;
    else if(score == "C0") return 2.0;
    else if(score == "D+") return 1.5;
    else if(score == "D0") return 1.0;
    else if(score == "F") return 0.0;
    else return -1;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string object, credit, score;
    float point_sum = 0;
    float credit_sum = 0;
    
    for(int i = 0; i < 20; i++)
    {
        cin >> object >> credit >> score;
        
        if(score != "P")
        {
            point_sum += score_to_point(score) * stof(credit);
            credit_sum += stof(credit);
        }
    }

    cout << point_sum / credit_sum << endl;
    
    return 0;
}