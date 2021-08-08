#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int t, n, k;
int a[N];
int c[N];
int vis[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 1; i <= n / 2; i++){
            c[min(a[i] + 1, a[n - i + 1] + 1)]++;
            c[max(a[i] + k, a[n - i + 1] + k) + 1]--;
            vis[a[i] + a[n - i + 1]]++;
        }
        for(int i = 1; i <= 2*k; i++){
            c[i] += c[i - 1];
        }
        int ans = INT_MAX, toal = n / 2;
        for(int i = 2 * k; i > 1; i--){
            int cat = c[i];
            cat += (toal - c[i]) * 2;
           // cout << "p=" << p << endl;
            cat -= vis[i];
        
            ans = min(ans, cat);
            
        }
        printf("%d\n", ans);
        for(int i = 1; i <= 2 * k; i++)c[i] =vis[i]= 0;

    }
}