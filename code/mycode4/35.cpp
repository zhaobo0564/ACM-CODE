#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], lmax[N], lmin[N];
stack<int>q;

int ans[N], block[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
       if(a[i] >= a[i - 1]){
           q.push(i);
       }else{
           while(q.size()){
               lmin[q.top()] = i;
               q.pop();
           }
           q.push(i);
       }
    }

    while(!q.empty()) lmin[q.top()] = n + 1, q.pop();

    a[0] = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(a[i] < a[i - 1]){
            q.push(i);
        }else{
            while(q.size()){
                lmax[q.top()] = i;
                q.pop();
            }
            q.push(i);
        }
    }    //cout << "**"<< endl;
    while(!q.empty()) lmax[q.top()] = n + 1, q.pop();
    ans[1] = 0;
    for(int i = 2; i <= n; i++){
        int res = 0;
        int j = 1;
        int bl = 0;
        while(j + i <= n){
    
            if(lmin[j] > lmax[j]){
                int lm = lmin[j];
                if(lm >= j + i){
                    j = lm;
                    bl++;
                }else{
                    int cn = lm - j;
                    cn = i - cn;
                    res += cn;
                    j += i;
                    bl++;
                }
            }else{
                int la = lmax[j];
                if(la >= j + i){
                    j = la;
                    bl++;
                }else{
                    int cn = la - j;
                    cn = i - cn;
                    res += cn;
                    j += i;
                    bl++;
                }
            }
            
        }
        if(j <= n){
            if(lmin[j] > lmax[j]){
                int l = n - j + 1;
                int lm = lmin[j];
                if(lm > n){
                    bl++;
                }else{
                    int cnt = lm - j;
                    res += (l - cnt);
                    bl++;
                }
            }else{
                int l = n - j + 1;
                int la = lmax[j];
                if(la > n){
                    bl++;
                }else{
                    int cnt = la - j;
                    res += (l - cnt);
                    bl++;
                }
            }
        }
        ans[i] = res;
        block[i] = bl;
            
    }
    int Q; scanf("%d", &Q);
    while(Q--){
        int x; scanf("%d", &x);
    
        printf("%d %d\n", block[x], ans[x]);
    }

    

    
}