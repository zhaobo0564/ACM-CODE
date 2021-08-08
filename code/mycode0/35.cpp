#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        if(n == 1){
            printf("-1\n");
        }else if ( n== 2){
            printf("57\n");
        } 
        else {
           if(n % 2){
               for(int i = 1; i < n/2 ; i++){
                   printf("24");
               }
               printf("239\n");
           }else{
               for(int i = 1; i < n/2 ; i++){
                   printf("24");
               }
               printf("23\n");
           }
           
        }
    }
}