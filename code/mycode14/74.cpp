#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e7 + 7;
const ll mod = 1e9 + 7;
int sum[N], ans[N];
int n, m1, m2, top = 1;

bool flag[N];

double f;

int solve(int l, int r) {
    int L = 1, R = top - 1, res = -1;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (ans[mid] > r) {
            res = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    if (res - 1 <= 0 || ans[res - 1] < l) {
        return sum[l];
    } else {
        return sum[ans[res - 1]];
    }
}


int main() {
   scanf("%d %d %d", &n, &m1, &m2);
   while (m1--) {
       int x, y, v;
       scanf("%d %d %d", &x, &y, &v);
       sum[x] += 1ll*v;
       sum[y + 1] -= 1ll*v;
   }
   int res = 1e9;
   
   for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1];
       if (sum[i] < 0) {
           flag[i] = 1;
       } else if (sum[i] > 0) {
           flag[i] = 0;
       } else {
           res = min(res, i);
       } 
       
   }
   sum[0] = 1;
   
   for (int i = 1; i <= n; i++) {
       ll su = sum[i - 1], su1 = sum[i];
       sum[i] = (su * su1) % mod;
       if (i < res) {
          flag[i] = flag[i - 1] ^ flag[i]; 
          
          if (flag[i] == 0) {
              ans[top++] = i;
          }
       }
   }
   ans[top++] = n + 1;
   while (m2--) {
       int l, r; scanf("%d %d", &l, &r);
       if (l >= res) {
           puts("0");
       } else if (l <= res && r >= res) {

           printf("%d\n", max(solve(l, r), 0));
       } else {
           printf("%d\n", solve(l, r));
       }
       

   }

}