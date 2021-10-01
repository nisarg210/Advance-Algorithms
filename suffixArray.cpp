// Time complexity of the Code is O(n log^2n)
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    s += '$';

    int n = s.size();
    vector<int> suffixArray(n), suffixClass(n); // array p will contain ordering of strings and array c will contain there equivalent classes.

    {
        // k = 0;
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            suffixArray[i] = a[i].second;
        }

        suffixClass[suffixArray[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                suffixClass[suffixArray[i]] = suffixClass[suffixArray[i - 1]];
            }
            else
            {
                suffixClass[suffixArray[i]] = suffixClass[suffixArray[i - 1]] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) < n)
    {
        // k -> k+1
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {{suffixClass[i], suffixClass[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
        {
            suffixArray[i] = a[i].second;
        }

        suffixClass[suffixArray[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                suffixClass[suffixArray[i]] = suffixClass[suffixArray[i - 1]];
            }
            else
            {
                suffixClass[suffixArray[i]] = suffixClass[suffixArray[i - 1]] + 1;
            }
        }
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << suffixArray[i] << " " << s.substr(suffixArray[i], n - suffixArray[i]) << "\n";
    }

    return 0;
}
