#include<bits/stdc++.h>
using namespace std;
int t, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        int c = min(a, b);
        int d = max(a, b);
        c += c;
        if(c >= d){
            printf("%d\n", c * c);
        }else{
            printf("%d\n", d * d);
        }
    }
}