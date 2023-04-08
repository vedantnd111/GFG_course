#include <bits/stdc++.h>
using namespace std;

void power_sets(string st, string curr, int k, vector<string>& ans)
{
    // cout << "k=" << k << endl;
    if (k == (st.length()))
    {
        ans.push_back(curr);
        return;
    }
    power_sets(st, curr, k + 1, ans);
    power_sets(st, curr + st[k], k + 1, ans);
}

int main()
{
    string st;
    cin >> st;
    string curr = "";
    vector<string> ans;
    power_sets(st, curr, 0, ans);
    // cout << ans << endl;
    sort(ans.begin(), ans.end());
    for (string i : ans)
    {
        cout << i << endl;
    }
}