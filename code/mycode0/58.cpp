#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, t;
vector<int>a, b;
char s[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", s);
        a.clear();
        b.clear();
        int pos = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '2'){
                a.push_back(1);
                b.push_back(1);
            }else if(s[i] == '1'){
                a.push_back(1);
                b.push_back(0);
                pos = i;
                break;
            }else{
                a.push_back(0);
                b.push_back(0);
            }
        }
        for(int i = pos + 1; i < n; i++){
            a.push_back(0);
            if(s[i] == '0'){
                b.push_back(0);
            }else if(s[i] == '1'){
                b.push_back(1);
            }else{
                b.push_back(2);
            }
        }
       
        for(int i = 0; i < n; i++){
            printf("%d", a[i]);
        }
        puts("");
        for(int i = 0; i < n ; i++){
            printf("%d", b[i]);
        }
        puts("");

    }
}