#include<bits/stdc++.h>
using namespace std;

int t, n;
char s[1000];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int f = 0;
         gets(s);
        for (int i = 1; i <= n; i++) {
            cin.getline(s, 999);
           // cout <<s << endl;
            int len = strlen(s);
            //cout << i << endl;
            for (int j = 0; j < len; j++) {
                if (s[j] == '2') {
                    f++;
                    break;
                }
            }
        }
        printf("%.7lf\n",(double)f / (double)n );
    }
}