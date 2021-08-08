#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int vis[N];
string s[N];

int cnt[N][30];



int n , m;
string a;

int main(){
    while(~scanf("%d %d", &n, &m)){
        cin >> a;
        string c ;
        int count = 1;
        for(int i = 0; i < a.length(); i++){
            c = "";
            for(int j = i; j < i + m; j++){
                if(j >= a.length())break;
                c += a[j];
            }
            s[count++] = c;
        }
        
        for(int i = 1; i < count; i++){

            for(int j = 0; j < s[j].length; j++){
                if(cnt[j][s[j] - 'a'] == 1){
                    break;
                }
                cnt[j][s[j] - 'a'] = 1;
            }
        }
        


    }
}