#include<bits/stdc++.h>
using namespace std;
int t, a, b;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        int c = max(a, b);
        int d = min(a, b);
        printf("%d\n", 2 * c + d);
    }
}