
 #include<bits/stdc.h>
#include<math.h>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
   sort(heights.begin(), heights.end());
       int min_index = 0;
        for (int i = 1; i < n; i++) {
            if (heights[i] - heights[i - 1] < heights[min_index + 1] - heights[min_index]) {
                min_index = i - 1;
            }
        }
        cout << heights[min_index] << " ";
        for (int i = min_index + 2; i < n; i++) {
            cout << heights[i] << " ";
        }
        for (int i = 0; i < min_index; i++) {
            cout << heights[i] << " ";
        }
        cout << heights[min_index + 1] << endl;
    }

    return 0;
}

