#include<bits/stdc++.h>
using namespace std;

const int N = 4e5 + 7;

char a[N];
int n, k, vis[400];

int main(){
    scanf("%d %d", &n, &k);
    scanf("%s", a);
    for(int i = 0; i < n; i++){
        vis[a[i]]++;
    }

    for(int i = 'a'; i <= 'z'; i++){
        if(k >= vis[i]){
            k -= vis[i];
            vis[i] = 0;
        }else{
            vis[i] -= k;
            k = 0;
        }
        if(k == 0)break;
    }

    stack<char>q;
   for(int i = n - 1; i >= 0; i--){
       if(vis[a[i]]){
           q.push(a[i]);
           vis[a[i]]--;
       }
   }

   while(q.size()){
       printf("%c", q.top());
       q.pop();
   }
   cout << endl;

    



}