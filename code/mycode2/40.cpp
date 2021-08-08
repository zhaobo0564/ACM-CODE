#include<bits/stdc++.h>
using namespace std;
char s[10000];
int vis[300];

int main(){

    

    fgetc( stdin)
    cout << s << endl;
    int maxn = 0;
    char aa;
    for(int i = 'a'; i <= 'z'; i++){
        if(maxn < vis[i]){
            maxn = vis[i];
            aa = char(i);
         }
    }
    cout << aa << endl;

}
  