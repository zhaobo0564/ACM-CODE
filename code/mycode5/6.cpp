#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x, y;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d",&n, &x, &y);
        int z = x + y;
        z -= n;
        if(z <= 0) z = 1;
        else z++;
        printf("%d ", min(z, n));
        z = x + y;
        z = z - 1;
        printf("%d\n", min(z, n));

    }
}