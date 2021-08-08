#include<bits/stdc++.h>
using namespace std;

int vis[20];
vector<int>b, e;

int main() {
    int f = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vis[i]);
        if (vis[i] % 2 ) f++;
    }
    if (f > 1) {
        puts("-1");
        return 0;
    }
    f = -1;
    int i = 1;
    int pos = -1;
    for (int i = 1; i < 10; i++) {
        
        if (vis[i] % 2 == 0 && vis[i]) {
            for (int j = 1; j <= vis[i] / 2; j++) {
                b.push_back(i);
                e.push_back(i);
                vis[i] -= 2;
                break;
            }
            pos = i;
            break;
        } else if (vis[i] % 2 && vis[i] > 1) {
            f = i;
            for (int j = 1; j <= vis[i] / 2; j++) {
                b.push_back(i);
                e.push_back(i);
                vis[i] -= 2;
                break;
            }
            pos = i;
            break;
        }
    }
  
    for (int i = 0; i < 10; i++) {
       // if (i == pos) continue;
        if (vis[i] % 2 == 0 ) {
            for (int j = 1; j <= vis[i] / 2; j++) {
                b.push_back(i);
                e.push_back(i);
            }
        } else {
            f = i;
            for (int j = 1; j <= vis[i] / 2; j++) {
                b.push_back(i);
                e.push_back(i);
            }
        }
    }
    reverse(e.begin(), e.end());
    if (b.size()) {
        if (b[0] == 0) {
            puts("-1");
            return 0;
        }
    }
    if (f >= 0) {
        for (int i: b) {
            cout << i ;
        }
        cout << f ;
        for (int i: e) {
            cout << i ;
        }
        cout << endl;
    } else {
        for (int i: b) {
            cout << i ;
        }
        for (int i: e) {
            cout << i ;
        }
        cout << endl;
    }
}