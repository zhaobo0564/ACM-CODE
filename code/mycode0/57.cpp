#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, n;
long long fn[N], k;

int main(){
    scanf("%d", &t);
    for(int i = 1; i <= 1e5; i++){
        fn[i] = fn[i - 1] + i;
    }
    while(t--){
        scanf("%d %lld", &n, &k);
        int b1 = 0, b2 = 0;
        int p = lower_bound(fn + 1, fn + n + 1, k) - fn;
     //   cout << "p=" << p << " "<<fn[p]<< endl;
        b1 = n - p ;
        b2 = fn[p] - k;
        b2 = b1 + b2 + 1;
       // cout << b1 << " " << b2 << endl;
        for(int i = 1; i <= n; i++){
            if(i == b1){
                printf("b");
            }else if( i == b2){
                printf("b");
            }else{
                printf("a");
            }
        }
        puts("");



    }
}