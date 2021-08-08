#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int n;
int a[N];

vector<int> ans[N];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[i].clear();
    }
    ans[1].push_back(1);
    for (int i = 2; i <= n; i++) { 
        int f = 0;
        for (int j = ans[i - 1].size() - 1; j >= 0; j--) {
           
            if (ans[i - 1][j] + 1 == a[i]) {
                for (int k = 0; k < j; k++) {
                    ans[i].push_back(ans[i - 1][k]);
                }
                ans[i].push_back(a[i]);
                f = 1;
                break;
            }
          
        }  
        if (f == 0 && a[i] == 1) {
            for (int j = 0; j < ans[i - 1].size(); j++) {
                ans[i].push_back(ans[i - 1][j]);
            }
            ans[i].push_back(a[i]);
            //cout << "size " << ans[i].size() << endl;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < ans[i].size(); j++) {
            if (j == ans[i].size() - 1) {
                cout << ans[i][j] << endl;
            } else {
               cout << ans[i][j] << "."; 
            }
            
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}