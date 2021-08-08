#include<bits/stdc++.h>
using namespace std;
const int N = 100007;
int a[N], n, b;
map<int, int>q;

int main(){
    scanf("%d %d", &n, &b);
    int pos = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == b){
            pos = i;
        }
    }  

    long long  ans = 0;
    int big = 0, small = 0;
    for(int i = pos + 1; i <= n; i++){
        if(a[i] > b){
            big++;
        }else{
            small++;
        }
        if(small == big){
            ans++;
        }

        q[big - small]++;
    }
    big = 0, small = 0;
    for(int i = pos -1; i; i--){
        if(a[i] > b){
            big++;
        }else{
            small++;
        }
        if(big == small){
            ans++;
        }
       // cout << "i = " <<i << " "<< q[small - big] << endl;
        ans += q[small - big];
    }
    printf("%lld\n", ans + 1);



}