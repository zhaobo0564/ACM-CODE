#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

string s;

vector<pair<char, int> >v;

int main() {
    cin >> s;
    int cnt = 1;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            v.push_back({s[i], cnt});
            cnt = 1;
        }
    }
    v.push_back({s[s.length() - 1], cnt});
    if (v.size() <= 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    while (1) {
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 || i + 1 == v.size()) {
                v[i].second--;
            } else {
                v[i].second -= 2;
            }
        }
        ans++;
        vector<pair<char, int> > v1;
        for (int i = 0; i < v.size(); i++) {
            if (i == 0 || i + 1 == v.size()) {
                if (v[i].second <= 0) continue;
                v1.push_back(v[i]);
            } else {
                if (v[i].second <= 0) {
                    if (i + 1 < v.size() && v1.size() && v1[v1.size() - 1].first == v[i + 1].first && v[i + 1].second > 0) {
                         v1[v1.size() - 1].second += v[i + 1].second;
                         i++;
                    } 
                    continue;
                } else {
                    v1.push_back(v[i]);
                }
            }
        }
        // for (auto it: v1) {
        //     cout << it.first << " " << it.second << endl;
        // }
        if (v1.size() <= 1) break;
        v = v1;
    }
    cout << ans << endl;
}