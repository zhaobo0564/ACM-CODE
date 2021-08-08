#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
typedef long long ll;
ll sum[N];

void init(){
    int top = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = i ; j < N; j += i){
            if(i * i <= j){
                sum[j] += i;
                if(j / i != i){
                    sum[j] += (j / i);
                }
            }
        }
    }

}

int main(){
    init();
    int q;
    scanf("%d", &q);
    for(int i = 1; i < N; i++){
        sum[i] = sum[i - 1] + sum[i];
    }
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", sum[r] - sum[l - 1]);
    }
}