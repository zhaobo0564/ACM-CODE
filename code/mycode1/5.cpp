#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
typedef long long ll;

ll a[N];

int  n, t;

int work(int x){
    int cnt = 0;
    int maxn= 0 ;
    while(x){
        if(x&1)maxn = max(maxn, cnt);
        x = x / 2;
        cnt++;
    }
    return maxn + 1;
}



int main(){
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);

        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(a[i] > a[i + 1]){
                int x = a[i] - a[i + 1];
                ans =max(ans, work(x));
                a[i + 1] = a[i];
            }
        }



        printf("%d\n", ans);


    }

}
