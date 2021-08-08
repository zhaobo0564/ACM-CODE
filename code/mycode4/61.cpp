#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100];
int n, t;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", (a + 1));
        stack<char>q;
        for(int i = 1; i <= n; i++){
            if(q.size() == 0){
                q.push(a[i]);
            }else if(q.top()  == '(' && a[i] == ')'){
                q.pop();
            }else{
                q.push(a[i]);
            }
        }
        int ans = q.size();
        printf("%d\n", ans / 2);
        while(q.size())q.pop();
    }
}