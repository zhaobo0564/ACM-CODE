#include<bits/stdc++.h>
using namespace std;

const int N = 120007;
typedef long long ll;
 ll a[N], n;
 ll fn[N];

 map<ll, int>q;

int main(){
    fn[0] = 1;
    for(int i = 1; i<= 32; i++){
        fn[i] = fn[i - 1] * 2;
    }

    scanf("%lld", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        q[a[i]]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        q[a[i]]--;
        int cnt = 0;
        ll x = a[i];
        while(x){
            x = x / 2;
            cnt++;
        }
        int f = 0;
        for(int j = 32; j >= cnt; j--){
            ll cat = fn[j] - a[i];
            if(q[cat]){
                f = 1;
                break;
            }
        }
        if(f == 0){
            //cout <<a[i] << endl;
            ans++;
        }
        q[a[i]]++;


    }
    printf("%d\n", ans);

}