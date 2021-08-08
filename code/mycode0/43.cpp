#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    string a = "a";
    for(int i = 1; i <= s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            if(j + i > s.length())break;
            string c = "";
            for(int k = j; k < i +j; k++){
                c += s[k];
            }
           // cout << c << endl;
            if(a < c) a = c;
        }
    }
    cout << a << endl;
   
}