#include<bits/stdc++.h>
using namespace std;

int a[1007], n;

int main(){
    int even = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2 == 0){
            even++;
        }
    }
    if(even == 0){
        int f = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] >1){
                f++;
            }
        }
        if(f){
            puts("Alice");
        }else{
            puts("Bob");
        }
    }else if(even % 2 == 0){
        puts("Alice");
    }else{
        puts("Bob");
    }
}