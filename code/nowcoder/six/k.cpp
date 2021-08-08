// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e6 + 7;
// typedef long long ll;
 
// int t, k, a[N];
 
// map<int, int>v;
// int vis[N];
 
// struct hjt{
//     int l, r;
//     int sum;
// }tree[20 * N];
 
// int n, q, rt[N], top = 1;
 
 
// #define m  (l + r) / 2
 
// void update(int v, int pos,int last, int &now, int l, int r){
//     now = top++; 
//     tree[now] = tree[last]; 
//     if(l == r){
//         tree[now].sum = v;
//         return;
//     }
//     if(pos <= m) update(v, pos, tree[last].l, tree[now].l, l, m);
//     else update(v, pos, tree[last].r, tree[now].r, m + 1, r);
//     tree[now].sum = tree[tree[now].l].sum + tree[tree[now].r].sum;
// }
 
// int query(int now, int ql, int qr, int l, int r){
//     if(ql <= l && qr >= r) return tree[now].sum;
//     int ans = 0;
//     if(ql <= m) ans += query(tree[now].l, ql, qr, l, m);
//     if(qr > m) ans += query(tree[now].r, ql, qr, m + 1, r);
//     return ans;
// }
 
// int main() {
//     scanf("%d", &t);
//     while (t--) {
//         top = 1;
//         v.clear();
//         scanf("%d %d", &n, &k);
//         for (int i = 0; i <= n; i++) {
//             rt[i] = 0;
//             vis[i] = 0;
//         }
//         int f = 0;
//         for (int i = 1; i <= n; i++) {
//             scanf("%d", &a[i]);
//             if (a[i] > k) {
//                 f = 1;
//             }
//         }
//         if (f) {
//             puts("NO");
//         } else {
//             if (k >= n) {
//                 int l = 1;
//                 while (l <= n &&v[a[l]] == 0) v[a[l]] = 1, l++;
//                 v.clear();
//                 int r = n;
//                while (r > 0 && v[a[r]] == 0) v[a[r]] = 1, r--;
//                 v.clear();
//                 if (l > r) {
//                     puts("YES");
//                 } else {
//                     puts("NO");
//                 }
 
//             } else {
//                 int l = 0;
//                  for(int i = 1; i <= n; i++){
//                     if(vis[a[i]] == 0){
//                         update(1, i, rt[i - 1], rt[i], 1, n);
//                         vis[a[i]] = i;
//                     }else{
//                         int temp;
//                         update(0, vis[a[i]], rt[i - 1], temp, 1, n);
//                         update(1, i, temp, rt[i], 1, n);
//                         vis[a[i]] = i;
//                     }
//                 }
//                 int flag = 0;
//                 for (int i = 0; i <= n; i++) {
//                     vis[i] = 0;
//                 }
//                 int r = n;
//                 while (r > 0 && vis[a[r]] == 0) {
//                     vis[a[r]] = 1;
//                     r--;
//                 }
//                 for (int i = 0; i <= k; i++) vis[i] = 0;
//                 a[0] = 0;
//                 while (l <= k &&vis[a[l]] == 0) {
//                     vis[a[l]] = 1;
//                     l++;
//                     int ok = 0;
//                     int pos = n + 1;
//                      for (int i = l; i <= n; i += k){
//                          ll ans = query(rt[i + k - 1], i, i + k - 1, 1, n);
//                         if (ans != k) {
//                                 ok = 1;
//                                 pos = i;
//                                 break;
//                             }
//                      }
//                     if (ok) {
//                        if (pos > r) {
//                            ok = 2;
//                        }
//                     } else {
//                         flag = 1;
//                         break;
//                     }
//                     if (ok == 2) {
//                         flag = 1;
//                         break;
//                     }
                     
//                 }
//                 if (flag) {
//                     puts("YES");
//                 } else {
//                     puts("NO");
//                 }
//             }
               
//         }
         
//     }
// }

#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

unordered_map<int, int>vis;

int le[N], a[N];

int main() {
    int t; scanf("%d", &t);
    while (t--) {

        vis.clear();
        int n, k; scanf("%d %d", &n, &k);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > k) {
                f = 1;
            }
        }
        if (f) {
            puts("NO");
        } else if (k >= n) {
            int l = 1;
            while (l <= n && vis[a[l]] == 0) vis[a[l]] = 1, l++;
            vis.clear();
            int r = n;
            while(r <= n && vis[a[r]] == 0) vis[a[r]] = 1, r--;
            if (l > r) {
                puts("YES");
            } else {
                puts("NO");
            }
        } else {
            int l = 1;
            for (int i = 1; i <= n; i++) {
                while (l <= n && vis[a[l]] == 0) {
                    vis[a[l]] = 1;
                    l++;
                }
                le[i] = l;
                vis[a[i]] = 0;
            }
            int flag = 0;
            for (int i = 1; i < le[1]; i++) {
                int ok = 0;
                for (int j = i + 1; j <= n; j += k) {
                    if (le[j] > n) {
                        break;
                    }
                    if (le[j] - j != k) {
                        ok = 1;
                        break;
                    } 
                }
                if (ok == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                puts("YES");
            } else {
                puts("NO");
            }
            
        }
    }
}