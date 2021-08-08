#include <bits/stdc++.h>
using namespace std;
int t, n, a[1007];

stack<int> q;
int main () {
    scanf("%d", &t);
    while (t--) { 
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        while(!q.empty())q.pop();
        int f = 0;
        int x, y, z;
        for (int i = 1; i <= n; i++) {
            while(!q.empty() && a[q.top()] > a[i]) {
                if(q.size() >= 2) {
                    z = i;
                    y = q.top();
                    q.pop();
                    x = q.top();
                    f = 1;
                    break;
                }
                q.pop();
            }
            q.push(i);
            if(f == 1) break;
        }
        if(f == 1) {
            puts("YES");
            printf("%d %d %d\n", x, y, z);
        }else {
            puts("NO");
        }
    }   
}