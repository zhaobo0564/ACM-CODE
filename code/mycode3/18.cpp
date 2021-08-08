#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
typedef long long ll;
ll fn[N], n, sum[N];
int t;

int main(){
    cout <<LLONG_MAX << endl;
    fn[1] = 1, fn[2] = 1;
    for(int i = 3;i <= 92 ; i++){
        fn[i] = fn[i - 1] + fn[i - 2];
        
    }
    for(int i = 1; i <= 91; i++){
        sum[i] = sum[i - 1] + fn[i];
        //cout << sum[i] << " " << i << endl;
        //cout << fn[i] << endl;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
      
        int ans = 0;
        for(int i = 1; i <=90; i++){
            if(sum[i] > n){
                ans = i - 1;
                break;
            }
        }
        if(n >= sum[90]){
            ans = 90;
        }
        printf("%d\n", ans);

        
    }
}