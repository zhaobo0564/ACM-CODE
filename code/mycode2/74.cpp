#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
    
    while(~scanf("%lld", &n)){
        if(n <= 1){
            printf("%lld\n", n);
            continue;
        }
        if(n < 10){
            printf("1%lld\n", n);
            continue;
        }
        vector<int>g;
        for(int i = 9; i >1; i--){
            if(n % i == 0){
                g.push_back(i);
                n = n / i;
                i++;
            }
        }
        if(n > 9){
            puts("-1");
        }else{
            if(n > 1)g.push_back(n);
            reverse(g.begin(), g.end());
           for(int i: g){
                printf("%d", i);
            }
            puts("");
        }
       
    }
    
}