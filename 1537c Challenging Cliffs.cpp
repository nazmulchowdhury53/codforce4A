 #include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a,c,i,j;
    cin >>a;

    while (a--) {
        int b;
        cin >>b;

        vector<int>v(b);
        for (i = 0; i <b; i++) {
            cin >>v[i];
        }
   sort(v.begin(),v.end());
      c= 0;
        for (i = 1; i <b; i++) {
            if (v[i] -v[i - 1] <v[c+ 1] - v[c]) {
                c = i - 1;
            }
        }
        cout <<v[c] << " ";
        for (i = c + 2; i <b; i++) {
            cout << v[i] << " ";
        }
        for (i = 0; i <c; i++) {
            cout <<v[i] << " ";
        }
        cout <<v[c + 1] << endl;
    }

    return 0;
}

