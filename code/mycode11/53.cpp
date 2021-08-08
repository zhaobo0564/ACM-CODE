#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

char s[N];

int a[3 * N];

int change(char x) {
    return x - 'a' + 1;
}

char work(int x) {
    x--;
    return x + 'a';
}

vector<char> ans;


int main() {
    int top = 1;
  ///  printf("l\n");
    scanf("%s", (s + 1));
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int cnt = change(s[i]);
        cout << cnt;
        if (cnt <= 9) {
            a[top++] = cnt;
        } else {
            a[top++] = cnt;
        }
    }
    cout << endl;
    int ok = 0;
    for (int i = 2; i < top; i++) {
        int cnt = 0;
        if (a[i] > 9) {
            cnt = a[i - 1] * 100 + a[i];
        } else {
            cnt = a[i - 1] * 10 + a[i];
        }
        if (cnt <= 26) {
            
            ok = i;
            break;
        }
    }

    if (ok == 0) {
        for (int i = 1; i < top; i++) {
            int cnt = a[i];
            if (a[i] > 10 && a[i] != 20) {
                ok = i;
                break;
            }
            
        }
        if (ok == 0) {
            puts("-1");
            return 0;
        } else {
            for (int i = 1; i < top; i++) {
                if (i == ok) {
                    // printf("%c%c", work(a[i] / 10), work(a[i] % 10));
                    ans.push_back(work(a[i] / 10));
                    ans.push_back(work(a[i] % 10));
                } else {
                    ans.push_back(work(a[i]));
                }
            }
        }
    } else {
        cout << ok << endl;
        a[ok - 1] = a[ok - 1] * 10 + a[ok];
        for (int i = 1; i < top; i++) {
            if (i == ok) continue;
            ans.push_back(work(a[i]));
        }
    }
    if (ans.size() > 2000000) {
        puts("-1");
    } else {
        for(char i: ans) {
            cout << change(i);
           // printf("%c", i);
        }
        puts("");
    }
}