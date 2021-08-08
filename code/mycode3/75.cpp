#include<bits/stdc++.h>
using namespace std;

string a, b;

int main(){
    cin >> a;
    cin >> b;
    if(a.length() > b.length()){
        puts(">");
    }else if(a.length() < b.length()){
        puts("<");
    }else{
        int f = 0;
        for(int i = 0; i < a.length(); i++){
            if(a[i] > b[i]){
                f = 1;
                break;
            }else if(a[i] < b[i]){
                f = 2;
                break;
            }
        }
        if(f == 1){
            puts(">");
        }else if(f == 2){
            puts("<");
        }else{
            puts("=");
        }
    }
}