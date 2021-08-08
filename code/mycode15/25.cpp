#include<bits/stdc++.h>
using namespace std;

char s[12];
int vis[10];

int main() {
    cin >> s;
    int cnt = 0;
    for (int i = 0; i <= 9; i++) {
        if (s[i] == 'o') cnt++;
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int z = 0; z <= 9; z++) {
                    int cat = 0;
                    if (s[i] == 'o') {
                        vis[i] = 1;
                    }
                    if (s[j] == 'o') {
                        vis[j] = 1;
                    }
                    if (s[k] == 'o') {
                        vis[k] = 1;
                    }
                    if (s[z] == 'o') {
                        vis[z] = 1;
                    }
                    for (int zz = 0; zz <= 9; zz++) {
                        if (vis[zz]) {
                            cat++;
                        }
                        vis[zz] = 0;
                    }
                    if (cat == cnt) {
                        if (s[i] == 'x' || s[j] == 'x' || s[k] == 'x' || s[z] == 'x') {

                        } else {
                            //cout << i << j << k << z << endl;
                            ans++;
                        }
                    }

                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}