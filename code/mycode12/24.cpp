#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 +7;
int H,M;
string h, m;

int a[10];

int work(int x) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    } else if (x == 2) {
        return 5;
    } else if (x == 5) {
        return 2;
    } else if (x == 8) {
        return 8;
    } else {
        return 1000;
    }
}

bool judge() {
    int hh = work(a[0]) * 10 + work(a[1]);
    int mm = work(a[2]) * 10 + work(a[3]);
    
    if (hh >= H || mm >= M) return false;
    for (int i = 0; i < 4; i++) {
        if (a[i] == 1 || a[i] == 2 || a[i] == 5 || a[i] == 0 || a[i] == 8) {

        } else {
            return false;
        }
    }
    return true;
}
string s;
void solve() {
    cin >> H >> M;
    cin >> s;
    a[0] = s[4] - '0';
    a[1] = s[3] - '0';
    a[3] = s[0] - '0';
    a[2] = s[1] - '0';
    while (1) {
       // cout << a[3] << a[2] << " :" << a[1] << a[0] << endl;
        if (judge()) {
            break;
        }
        int mm = a[1] * 10 + a[0];
        int hh = a[3] * 10 + a[2];
        mm++;
       // cout << "hh " << hh << " mm " << mm << endl;
        if (mm >= M) {
            a[0] = a[1] = 0;
            hh++;
            if (hh >= H) {
                hh = 0;
                a[3] = a[2] = 0;
            } else {
                a[2] = hh % 10;
                a[3] = hh / 10;
            }
        } else {
            a[0] = mm % 10;
            a[1] = mm / 10;
        }
        
    }
    cout << a[3] << a[2] << ":" << a[1] << a[0] << endl;
   
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}