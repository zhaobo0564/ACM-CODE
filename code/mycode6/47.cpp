#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], n, t;

int main() {
    ios::sync_with_stdio(0);

    t = 1;
    while (t--) {
        cin >> n; 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        vector<int> ans;
        if (n >= 3) {
            ans.push_back(a[n]);
            ans.push_back(a[n - 2]);
            ans.push_back(a[n - 1]);
            int i = n - 3;
            int cnt = 1;
            while (1) {
                if (i - 1 > 0) {
                    ans.push_back(a[i - 1]);
                    ans.push_back(a[i]);
                    i -= 2;
                    cnt++;
                } else {
                    break;
                }
                
            }
            while(i)ans.push_back(a[i]), i--;
            cout << cnt << endl;
            for(int it: ans) {
                cout << it << " ";
            }
            cout << endl;
        } else {
            cout << "0\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}