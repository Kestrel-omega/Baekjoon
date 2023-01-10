// #include <iostream>
// #include <algorithm>
// #include <deque>
// #include <string>

// using namespace std;

// int main()
// {
//     ios_base ::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     const string separator = ",";

//     int T, n;
//     string p, x;
//     deque<int> q;

//     cin >> T;

//     while (T--)
//     {
//         int cursor = 1;
//         int total_R_count = 0;

//         int pos, len;
//         bool err_flag = false;
//         string num;

//         cin >> p >> n >> x;
//         x.pop_back();

//         if (n > 0)
//         {
//             while ((pos = x.find(separator, cursor)) < x.length() - 1)
//             {
//                 len = pos - cursor;
//                 num = x.substr(cursor, len);
//                 q.push_back(stoi(num));
//                 cursor = pos + 1;
//             }
//             num = x.substr(cursor);
//             q.push_back(stoi(num));

//             for (int i = 0; i < p.length(); i++)
//             {
//                 if (p[i] == 'D')
//                 {
//                     if (!q.empty())
//                     {
//                         if (total_R_count % 2 == 0)
//                             q.pop_front();
//                         else
//                             q.pop_back();
//                     }
//                     else
//                     {
//                         err_flag = true;
//                         break;
//                     }
//                 }
//                 else if (p[i] == 'R')
//                     total_R_count++;
//                 // reverse(q.begin(), q.end());
//             }

//             if (err_flag)
//                 cout << "error\n";
//             else
//             {
//                 if (!q.empty())
//                 {
//                     if (total_R_count % 2 == 1)
//                         reverse(q.begin(), q.end());
//                     cout << "[";
//                     for (int i = 0; i < q.size() - 1; i++)
//                         cout << q[i] << ",";
//                     cout << q[q.size() - 1] << "]\n";
//                 }
//                 else
//                     cout << "[]\n";
//             }

//             string().swap(p);
//             string().swap(x);
//             string().swap(num);
//             deque<int>().swap(q);
//         }

//         else
//         {
//             for (int i = 0; i < p.length(); i++)
//             {
//                 if(p[i] == 'D')
//                 {
//                    cout << "error\n";
//                    break;
//                 }
//                 else cout << "[]\n";
//             }
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

deque<int> string_to_deque(string x_string)
{
    deque<int> num_deque;
    string temp_str = "";

    for(int i = 0; i < x_string.length(); i++)
    {
        if(isdigit(x_string[i])) temp_str += x_string[i];
        else
        {
            if(!temp_str.empty())
            {
                num_deque.push_back(stoi(temp_str));
                temp_str = "";
            }
        }
    }

    return num_deque;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, x_length;
    cin >> T;

    while(T--)
    {
        string orders = "";
        string x_string = "";
        bool error = false;
        bool reverse = false;

        cin >> orders >> x_length >> x_string;

        deque<int> num_deque = string_to_deque(x_string);

        for(char order : orders)
        {
            if(order == 'R')
            {
                if (reverse) reverse = false;
                else reverse = true;
            }
            else
            {
                if(num_deque.empty())
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if (reverse) num_deque.pop_back();
                else num_deque.pop_front();
            }
        }

        if(!error) cout << "[";
        
        if(!reverse && !num_deque.empty())
        {
            for(int i = 0; i < num_deque.size()-1; i++) cout << num_deque[i] << ",";
            cout << num_deque[num_deque.size()-1];
        }
        else if(reverse && !num_deque.empty())
        {
            for(int i = num_deque.size()-1; i > 0; i--) cout << num_deque[i] << ",";
            cout << num_deque[0];
        }

        if(!error) cout << "]\n";

    }

    return 0;
}