#include<bits/stdc++.h>
using namespace std;
string s[20];
int t, n, m;

bool judge(string str){
    for(int i = 1; i <= n; i++){
        int f = 0;
        for(int j = 0; j < m; j++){
            if(s[i][j] != str[j]){
                f++;
            }
            if(f > 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++){
            cin >> s[i];
        }
      

        int f = 0;
        string str = s[1];
        for(int i = 0; i < m; i++){
            str = s[1];
            for(int j = 'a'; j <= 'z'; j++){
                str[i] = j;
                if(judge(str)){
                    f = 1;
                    break;
                }
            }
            if(f)break;
        }
        if(f){
            cout << str << endl;
        }else{
            puts("-1");
        }

    }
}