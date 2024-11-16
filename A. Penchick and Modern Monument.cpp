

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n),vv;
        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int h : v) {
            auto it = upper_bound(vv.begin(), vv.end(), h);
            if (it == vv.end())
                vv.push_back(h);
            else *it = h;
        }

        cout << n - vv.size() << endl;
    }
    return 0;
}
