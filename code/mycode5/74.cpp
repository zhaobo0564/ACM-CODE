#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int t, n;
long long x, y;

vector<int>a, b;

int main() {
    //freopen("output.txt", "w", stdout); 
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld %lld", &n, &x, &y);

        if (n > x * y || x + y > n + 1) {
            puts("NO");
        } else {
            int now = n;
            a.clear();
            b.clear();
            for (int i = 1; i <= y; i++) {
                b.push_back(now);
                now--;
            }
            int cnt = n - y;
            int cat = 1;
            while (1) {
                //cout << "**\n";
                //cout << cnt - y + cat + 1 << endl;
                if (cnt - y + cat + 1 > x) {
                    vector<int> v;
                    for (int i = 1; i <= y; i++) {
                        v.push_back(now);
                        now--;
                    }
                    reverse(v.begin(), v.end());
                    for (int i: v) {
                        a.push_back(i);
                    }
                    cnt -= y;
                    cat++;
                } else {
                    x -= cat;
                    if (x == 0) break;
                    int cn = (cnt - (x - 1));
                    vector<int> v;
                    for (int i = 1; i <= cn; i++) {
                        v.push_back(now);
                        now--;
                    }
                    reverse(v.begin(), v.end());
                    for (int i: v) {
                        a.push_back(i);
                    }
                    while(now) {
                        a.push_back(now);
                        now--;
                    }
                    break;

                }

            }
            reverse(a.begin(), a.end());
            for (int i: b) {
                a.push_back(i);
            }
            printf("YES\n%d", a[0]);
            for (int i = 1; i < a.size(); i++) {
                printf(" %d", a[i]);
            }
            puts("");


        }
    }
}