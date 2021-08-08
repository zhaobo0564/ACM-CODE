#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
    scanf("%d %d %d", &a, &b, &c);
    if(a == 0 && b == 0){
        puts("non");
    }else if(a == 0 && c == 0){
        puts("non");
    }else if(b == 0 && c == 0){
        puts("non");
    }else if(a == 0){
        if(-c * b > 0){
            puts("1 2");
        }else{
            puts("3 4");
        }
    }else if(b == 0){
        if(-c * a > 0){
            puts("1 4");
        }else{
            puts("2 3");
        }
    }else{
        if(-a * b > 0 && (-c * b) > 0){
            puts("1 2 3");
        }else if(-a * b > 0 && c == 0){
            puts("1 3");
        }else if(-a * b > 0 && (-c * b) < 0){
            puts("1 3 4");
        }else if(-a * b < 0 && (-c * b) > 0){
            puts("1 2 4");
        }else if(-a * b < 0 && c == 0){
            puts("2 4");
        }else if(-a * b < 0 && (-c * b) < 0){
            puts("2 3 4");
        }

    }
}