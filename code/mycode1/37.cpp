#include<bits/stdc++.h>
using namespace std;

map<string, int>q;
int cnt[10][10];

int main(){
    q["elephant"] = 1;
    q["tiger"] = 2;
    q["cat"] = 3;
    q["mouse"] = 4;
    cnt[1][2] = 1;
    cnt[2][3] = 1;
    cnt[3][4] = 1;
    cnt[4][1] = 1;

    string a, b;
    cin >> a >> b;

    if(cnt[q[a]][q[b]]){
        cout <<"tiangou yiwusuoyou\n";
    }else if(cnt[q[b]][q[a]]){
        cout << "tiangou txdy\n";
    }else{
         cout <<"tiangou yiwusuoyou\n";
    }
    
}