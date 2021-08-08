#include<bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        queue<int>v;
        while(n){
            v.push(n % 10);
            n = n / 10;
        }
        vector<int>q;
        int cnt = 1;
        while(v.size()){
            if(v.front() ){
                q.push_back(v.front() * cnt);
            }
            v.pop();
            cnt *= 10;
        }
        cout << q.size() << endl;
        for(int i: q){
            cout << i << " ";
        }
        puts("");

    }
}