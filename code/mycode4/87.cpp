#include<bits/stdc++.h>
using namespace std;

void work(string a, string b){
    for(int i = 0; i < a.length(); i++){
        int f = 0;
        int pos;
        char s = a[i];
        for(int j = a.length() - 1; j > i; j--){
            if(s > a[j]){
               s = a[j];
               pos = j;
               f = 1;
            }
        }
        if(f){
            swap(a[i], a[pos]);
            break;
        }
    }
    if(a < b){
        cout << a << endl;
    }else{
        cout <<"---" << endl;
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        string a, b;
        cin >> a >> b;
        work(a, b);
    }
}