#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    if(x == y){
        puts("=");
    }else if(x == 1 ){
        puts(">");
    }else if(y == 1){
        puts("<");
    }
}