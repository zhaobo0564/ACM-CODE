#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt","w",stdout);
    printf("10\n");
    srand(time(0));
    for(int i = 1; i <= 10; i++){
        printf("100000 1000\n");
        for(int i = 1; i <= 10; i++){
            printf("%d ",i % 2 );
        }
        printf("\n");
        for(int i = 1; i <= 1000; i++){
            int l = rand()%500 ;
            int r = rand()%5000 + 500;
            printf("%d %d %d\n", i % 5,l, r);
        }
        printf("\n");
    }
}