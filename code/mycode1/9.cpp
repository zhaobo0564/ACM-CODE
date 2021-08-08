#include<bits/stdc++.h>
using namespace std;
const int N = 2007;

char str[N];
int t, n, a, b;
char s[]= "abcdefghijkmlnopqrstuvwxyz";

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        vector<char>v;
        queue<char>q;
        for(int i = 0; i < b; i++){
            v.push_back(s[i]);
            q.push(s[i]);
        }

        for(int i = 1; i <= a - b; i++){
            v.push_back(s[b - 1]);
            q.push(s[b - 1]);
        }

        for(int i = a + 1; i <= n; i++){
            v.push_back(q.front());
            q.push(q.front());
            q.pop();
        }
        for(char it : v){
            printf("%c", it);
        }
        puts("");
        v.clear();
        while(q.size())q.pop();
       

    }

}