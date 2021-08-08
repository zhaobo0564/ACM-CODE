#include<bits/stdc++.h>
using namespace std;
string a[400];


int main(){
    int n; scanf("%d", &n);

    if(n == 1){
        cout << 1 << endl << 1 << endl;
    }else if(n == 2){
        cout << 2 << endl << 0 << endl<< 11 << endl;
    }else{
        cout << n - 1 << endl;

        vector<char>q;
        q.push_back('0');
        q.push_back('0');
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <q.size(); j++){
                cout << q[j];
            }
            cout << endl;
            q.pop_back();
            q.push_back('1');
            q.push_back('0');
        }

        
    }
}