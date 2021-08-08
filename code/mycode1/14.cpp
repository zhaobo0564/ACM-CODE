#include<bits/stdc++.h>
using namespace std;
int n, l, r;


vector<int>g;

int main(){
    for(int i = 0; i <= sqrt(2000000000)  ; i++){

        g.push_back(i * i);
    }
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &l, &r);
        int p = upper_bound(g.begin(), g.end(), r) - g.begin();
        int sum = p - 1;
        int p1 = upper_bound(g.begin(), g.end(), l - 1) - g.begin();
        sum = sum - p1  + 1;
        printf("%d\n", sum);

    }

}