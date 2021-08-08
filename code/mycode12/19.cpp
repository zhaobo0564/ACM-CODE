#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
string s, t;

struct node {
    char v;
    int nxt, last;
}e[2 * N];

int top = 1, head = 1;

int main() {
    ios::sync_with_stdio(0);
    cin >> s >> t;
    int now = top;
    e[top].last = -1;
    e[top].nxt = -1;
    e[top].v = s[0];
    top++;
    for (int i = 1; i < s.length(); i++) {
        if (t[i - 1] == 'L') {
            int la = e[now].last;
       //     cout << "la = " << la << endl;
            if (la == -1) {
                e[top].last = -1;
                head = top;
                e[top].nxt = now;
                e[now].last = top;
                e[top].v = s[i];
                now = top;
                top++;
            } else {
              //  cout << e[la].v << endl;
                e[la].nxt = top;
                e[top].last = la;
                e[now].last = top;
                e[top].nxt = now;
                e[top].v = s[i];
                now = top;
                top++;
            }
        } else {
            e[top].last = now;
            e[top].nxt = e[now].nxt;
            e[e[top].nxt].last = top;
            e[now].nxt = top;
            e[top].v = s[i];
            now = top;
            top++;
            
        }
    }
    while (head != -1) {
        printf("%c", e[head].v);
        head = e[head].nxt;
    }
    puts("");
    
}