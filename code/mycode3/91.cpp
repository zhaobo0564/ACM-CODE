#include<bits/stdc++.h>
using namespace std;

int t;
string s;

int main(){
    scanf("%d", &t);
    while(t--){
        cin >> s;
        cout << s[0];
        for(int i = 1; i < s.length() - 1; i += 2){
            cout << s[i];
        }
        cout << s[s.length() - 1] << endl;
    }
}