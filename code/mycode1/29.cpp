#include<bits/stdc++.h>
using namespace std;
string a, b;

int main(){
    cin >> a >> b;
    if(a == b){
        cout <<"-1\n";
    }else{
        int lena = a.length();
        int lenb = b.length();
        cout << max(lena, lenb) << endl;
    }
}