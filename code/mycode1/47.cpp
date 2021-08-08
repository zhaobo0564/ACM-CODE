#include<bits/stdc++.h>
using namespace std;

string a,b;

int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int lena = a.length();
    int lenb = b.length();
    int len = min(lena, lenb);
    int ans = 0;
    for(int i = 0; i <len; i++){
        if(a[i] == b[i]){
            ans++;
        }else{
            break;
        }
    }
    cout << lena - ans + lenb - ans << endl;

}