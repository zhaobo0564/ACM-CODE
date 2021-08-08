#include<bits/stdc++.h>
using namespace std;
stack <char>q;
string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(!q.empty() && q.top() == s[i]){
            q.pop();
           // i++;
        }else{
            q.push(s[i]);
        }
    }
    stack<char>p;
    if(q.size() == 0){
        puts("0");
        return 0;
    }
    while(q.size()){
        p.push(q.top());
        q.pop();
    }
    while(p.size()){
        printf("%c", p.top());
        p.pop();
    }
    puts("");
}