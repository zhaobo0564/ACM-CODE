#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

int a[100], n, x, y;


int work(int d) {
    int cnt = 0;
    vector<int> ans;
    for (int i = y; i > 0; i -= d) {
        ans.push_back(i);
        cnt++;
        if (cnt == n) break;
    }
    if (cnt == n) {
        if (ans[ans.size() - 1] <= x) {
            for (int i: ans) {
                cout << i << " ";
            }
            cout << "\n";
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

int judge(int d) {
    vector<int> ans;
    int cnt = 0;
    for (int i = y; i > 0; i -= d) {
        ans.push_back(i);
        cnt++;
        if (cnt == n) break;
    }
    if (cnt == n) {
        if (ans[ans.size() - 1] > x) {
            return 0;
        }
    }
    for (int i = y + d; ; i += d) {
        ans.push_back(i);
        cnt++;
        if (cnt == n) break;
    }
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 1;
}


int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        int d = y - x;
        int f = 0;
        for (int i = 1; i <= d; i++) {
            if (d % i == 0) {
                if (work(i)) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            for (int i = 1; i <= d; i++) {
                if (d % i == 0) {
                    if (judge(i)) {
                        break;
                    }
                }
            }
        } 
    }
}