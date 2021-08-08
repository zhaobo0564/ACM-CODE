#include<bits/stdc++.h>
using namespace std;
string a, b;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> a >> b) {
        if(a.length() == b.length()) {
            if(a > b) {
                puts(">");
            }else if (a == b) {
                puts("=");
            }else {
                puts("<");
            }
        }else{
            string c = a;
            while(a.length() <= 200000) a += a;
            c = b;
            while(b.length() <= 200000) b += b;
            int f = 0;
            for (int i = 0; i < 200000; i++) {
                if (a[i] > b[i]) {
                    f = 1;
                    break;
                } else if (a[i] < b[i]) {
                    f = 2;
                    break;
                }
            }
            if (f == 0) puts("=");
            else if (f == 1) puts(">");
            else if (f == 2) puts("<");
        }
        
    }
}