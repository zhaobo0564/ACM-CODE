#include<bits/stdc++.h>
using namespace std;

string s;
int t;


bool work(string x){
    int len = x.length() / 2;
    int cnt = x.length() - 1;
    for(int i = 0; i < len ;i++){
        if(x[i] != x[cnt - i]){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d", &t);
    while(t--){
        cin>>s;
        int len = s.length() - 1;
        int pos = 0;
        for(int i = 0; i <s.length(); i++){
            if(s[i] != s[len - i]){
                pos = i - 1;
                break;
            }
        }
        int l = pos + 1, r = len - pos - 1;
        int ans = 0;
        string b = "", cnt = "";
        for(int i = l; i <= r; i++){
            b += s[i];
            if(work(b)){
                cnt = b;
            }
        } 
        b = "";
        string cnt1 = "";
        for(int i = r; i >= l; i--){
            b += s[i];
            if(work(b)){
                cnt1 = b;
            }
        }
        string cnt2 = "";
        b = "";
        for(int i = 0; i <= len; i++){
            b += s[i];
            if(work(b)){
                cnt2 = b;
            }
        }
        string cnt3 = "";
        b = "";
        for(int i = len; i >= 0; i--){
            b += s[i];
            if(work(b)){
                cnt3 = b;
            }
        }
        ans = cnt.length() + (pos + 1) * 2;
        int ans1 = cnt1.length() + (pos + 1) * 2;
        int ans2 = cnt2.length();
        int ans3 = cnt3.length();
        int cn = 0;
        if(len - pos == pos){
            cn++;
        }
        if(ans >= ans1 && ans >= ans2 && ans >= ans3){
            for(int i = 0; i <= pos; i++){
                cout << s[i];
            }
            cout << cnt;
            for(int i = len - pos + cn; i <= len; i++){
                cout << s[i];
            }
            cout << endl;
        }else if(ans1 >= ans2 && ans1 >= ans && ans1 >= ans3){
            for(int i = 0; i <= pos; i++){
                cout << s[i];
            }
            cout << cnt1;
            for(int i = len - pos + cn; i <= len; i++){
                cout << s[i];
            }
            cout << endl;
        }else if(ans2 >= ans && ans2 >= ans1 && ans2 >= ans3){
            cout << cnt2 << endl;
        }else{
            cout << cnt3 << endl;
        }
    }
}