#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll;

int n;
ll a[N], fn[33];


int main(){
    fn[0] = 1;
    for(int i = 1; i <= 32; i++){
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    int f = 0;
    sort(a + 1, a + n + 1);
    a[n + 1] = LLONG_MAX;
    ll x, y, z;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 32; j++){
            ll cnt = a[i] + fn[j];
            ll cnt1 = a[i] + fn[j] + fn[j];
            int p =lower_bound(a + 1, a + n + 1, cnt) - a;
            int p1 = lower_bound(a + 1, a + n + 1, cnt1) - a;

            if(a[p] == cnt && a[p1] == cnt1){
                f = 3;
                x = a[i];
                y = cnt;
                z = cnt1;
                break;
            }else if(a[p] == cnt){
                f = 2;
                x = a[i];
                y = cnt;
             
            }else if(a[p1] == cnt1){
                f = 2;
                x = a[i];
                y = cnt1;
            }
        }
        if(f == 3)break;
    }
    if(f == 3){
        cout << f << endl;
        cout << x <<" " << y << " " << z << endl;
    }else if(f == 2){
        cout << f << endl;
        cout << x << " " << y << endl;
    }else{
        cout << 1 << endl;
        cout << a[1] << endl;

    }


   

}