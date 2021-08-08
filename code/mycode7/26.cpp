#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

char s[N];
int n, k;


int main() {
    scanf("%s %d", s + 1, &k);
    n = strlen(s + 1);
    int snow = 0, candy = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') {
            snow++;
        } else if (s[i] == '?') {
            candy++;
        } else {
            len++;
        }
    }

    if (snow) {
        int cnt = len - candy;
        cnt = max(0, cnt);
        if
    }


   


}