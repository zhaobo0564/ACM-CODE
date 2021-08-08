#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll; 

char mp[30];

vector<int> ans;
int n, k;
int cn[30][30];
int an = 0;



void solve() {
    int top = 1;
    for (int i = 'a'; i <= 'z'; i++) {
        mp[top++] = char(i);
    }
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        ans.push_back(i);
        for (int j = i + 1; j <= k; j++) {
            ans.push_back(i);
            ans.push_back(j);
        }
    }
  
    if (n <= ans.size()) {
        for (int i = 0; i < n; i++) {
            cout << mp[ans[i]];
        }
        cout << endl;
    } else {

        int cnt = ans.size();
        int ct = n / cnt;
        for (int i = 1; i <= ct; i++) {
            for (int j: ans) {
                cout << mp[j];
            }
          
        }
        ct = n % cnt;
        for (int i = 0; i < ct; i++) {
            cout << mp[ans[i]];
        }
        cout << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    int t = 1;
    while (t--) {
        solve();
    }
}