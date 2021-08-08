#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int>g;
int main(){
    scanf("%d", &t);
    while(t--){
        g.clear();
        scanf("%d", &n);
        if(n % 2 && n != 1){
            puts("Ashishgup");
        }else if(n == 1){
            puts("FastestFinger");
        }else if(n == 2){
             puts("Ashishgup");
        }else{
            for(int i = 2; i * i <= n; i++){
                if(n % i == 0){
                    g.push_back(i);
                    if(n / i != i){
                        g.push_back(n / i);
                    }
                }
            }
            int f = 0;
            for(int i : g){
                if(i % 2){
                    if((n / i) % 2 == 0 && (n / i) != 2){
                        f = 1;
                        break;
                    }
                }
            }
            if(f){
                puts("Ashishgup");
            }else{
                puts("FastestFinger");
            }
        }
    }
}