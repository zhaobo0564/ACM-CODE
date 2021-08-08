#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int  n, q;
#define m (l + r) / 2

map<int, int>x;

vector<pair<int,int> >v;



bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.first > y.first;
}

int work(int x) {
    int ans = 0, sum = 0, all = 0;
    for (int i = 0; i < v.size(); i++) {
        all += v[i].second;
        if (x <= v[i].second) {
            sum = v[i].first;
            break;
        } else {
            x -= v[i].second;
        }
    }
    if (sum == 0) {
        return all;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first >= sum) {
            ans += v[i].second;
        }
    }
    return ans;
}



int main() {
    scanf("%d %d", &n, &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        x[l]++;
        x[r + 1]--;
    }
    int f = 0, last = 0, value = 0;
    for (auto it: x) {
        if (f > 0) {
            v.push_back({last, it.first - value});
            last = it.second + last;
            value = it.first;
        } else {
            last = it.second;
            value = it.first;
        }
        f++;
        
    }
    int one = n / 10;
    if (n % 10) {
        one++;
    }
    int two = n / 4;
    if (n % 4) {
        two++;
    }
    int three = n / 2;
    if (n % 2) {
        three++;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    last = 0;
    int ans = work(one);
    cout << ans - last << " ";
    last = ans;
    ans = work(two);
    cout << ans - last << " ";
    last = ans;
    ans = work(three);
    cout << ans - last << endl;
    

}