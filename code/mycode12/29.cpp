#include<bits/stdc++.h>
using namespace std;

int n, m;
stack<int> q;
string ans[20];
int main() {
    while (~scanf("%d", &n)) {
        string a, b;
        cin >> a >> b;
        
        while (q.size()) q.pop();
        int l = 0, top = 1;
        for (int i = 0; i < n; i++) {
            if (q.size() == 0) {
                q.push(a[i]);
                ans[top++] = "in";
            } else {
                if (q.top() == b[l]) {
                    ans[top++] = "out";
                    q.pop();
                    i--;
                    l++;
                } else {
                    ans[top++] = "in";
                    q.push(a[i]);
                }
            }
        }
        while (q.size()) {
            if (q.top() == b[l]) {
                q.pop();
                ans[top++] = "out";
                l++;
            } else {
                break;
            }
        }
        if (q.size() == 0) {
            puts("Yes.");
            for (int i = 1; i < top; i++) {
                cout << ans[i] << endl;
            }
            puts("FINISH");
        } else {
            puts("No.");
            puts("FINISH");
        }


      
    }
}