#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int cnt = n;
        vector<int>v;
        while (cnt) {
            if (cnt >= 4) {
                v.push_back(8);
                cnt -= 4;
            } else {
                v.push_back(8);
                break;
            }
        }
        for (int i = 1; i <= n - (int)v.size(); i++) {
            printf("9");
        }
        reverse(v.begin(), v.end());
        for (int i: v) {
            printf("%d", i);
        }
        puts("");
    }
}