#include<bits/stdc++.h>
using namespace std;

struct node{
    int x, y;
}p[100000];

node d[100000];
int n, m, k;

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &d[i].x, &d[i].y);
    }
    cout << m + n - 2 + n * m << endl;
    for(int j = 1; j < m; j++){
        cout << "L";
    }
    for(int i = 1; i < n; i++){
        cout <<"D";
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            if(i % 2){
                cout <<"R";
            }else{
                cout << "L";
            }
        }
        cout <<"U";
    }
    cout << endl;

}