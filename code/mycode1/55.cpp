#include<bits/stdc++.h>
using namespace std;
int t, n;
int fn[40];

int main(){
    fn[0] = 1;
    for(int i = 1; i <= 30; i++){
        fn[i] = fn[i - 1] + pow(2, i);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int cnt = 0;
        int x = n;
        for(int i = 1; i <= 30; i++){
            if(n % fn[i] == 0){
                printf("%d\n", n / fn[i]);
                break;
            }
        }


    }

}