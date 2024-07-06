#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v1;
        for (int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;
            v1.push_back(c);
        }
        vector<int> v3 = v1;
        sort(v3.begin(), v3.end());
        if (v1 == v3)
        {
            cout << "YES" << endl;
        }
        else
        {
            vector<int> v2;
            int i;

            for (i = 0; i < n; i++)
            {
                if (v1[i] > 9)
                {
                    int rem = v1[i] / 10;
                    v2.push_back(rem);
                    int tem = v1[i] - rem * 10;
                    v2.push_back(tem);
                    for (int j = i + 1; j < n; j++)
                    {
                        v2.push_back(v1[j]);
                    }
                    vector<int> v3 = v2;
                    sort(v3.begin(), v3.end());
                    if (v2 == v3)
                    {
                        cout << "YES" << endl;
                        break;
                    }
                    else
                    {
                        cout << "NO" << endl;
                        break;
                    }
                }
                else
                {
                    v2.push_back(v1[i]);
                }
            }
        }
    }
    return 0;
}