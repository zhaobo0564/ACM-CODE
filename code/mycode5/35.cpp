#include <bits/stdc++.h>
using namespace std;

int t, n;

string a, b;

vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n;
        cin >> a >> b;
        int l = 0, r = n - 1;
        int rr = n;
        int f = 0;
        while (r >= 0) {
            if (f == 0) {
                if (a[l]  == b[r] ) {
                    ans.push_back(0);
                    ans.push_back(r);
                } else {
                    ans.push_back(r);
                }
            } else {
                if (a[rr] != b[r] ) { 
                    ans.push_back(0);
                    ans.push_back(r);
                } else {
                    ans.push_back(r);
                }
            }
            r--;
            if (f == 0) {
                f = 1;
                rr--;
            } else {
                l++;
                f = 0;
            }
        }

        printf("%d\n", (int)ans.size());
        for (int i: ans) {
            printf("%d ", i + 1);
        }
        puts("");



    }
}

