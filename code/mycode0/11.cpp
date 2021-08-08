#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll hp1, hp2, atk1, atk2, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld", &hp1, &hp2, &atk1, &atk2, &m);
        hp2 -= atk1;
        hp1 -= atk2;
        if(hp2 <= 0){
            printf("Yes\n");
        }else if(hp1 <= 0){
            printf("No\n");
        }else{
            atk1 -= m;
            if(atk1 <= 0){
                printf("No\n");
            }else{
                int cnt = hp2 / atk1;
                if(hp2 % atk1)cnt++;
                int cnt1 = hp1 / atk2;
                if(hp1 % atk2)cnt1++;
                if(cnt <= cnt1){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
}