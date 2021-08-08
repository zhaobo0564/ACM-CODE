#include<bits/stdc++.h>
using namespace std;

int a[4];

int main(){
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    int sum = a[0] + a[1] + a[2] + a[3];
    int minn = INT_MAX;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j)continue;
            minn = min(minn, abs(sum - (a[i] + a[j]) - (a[i] + a[j])));

        }
    }
    cout << minn << endl;


}