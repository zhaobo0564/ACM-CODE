#include<bits/stdc++.h>
using namespace std;

struct node{
    int data, id;
    double  t;
}p[1000];

bool cmp(node a, node b){
    if(a.data == b.data){
        if(a.t == b.t){
            return a.id < b.id;
        }
        return a.t > b.t;
    }
    return a.data > b.data;
}

int main(){
    int top = 1;
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int a, b;
        double t;
       
        scanf("%d %d %lf", &a, &b, &t); 
        //int cn = t * 10;
        if(t >= 38.0){
            p[top].data = a;
            p[top].id = b;
            p[top++].t = t;
        }

    }

    sort(p + 1, p + top, cmp);
    cout << top - 1 << endl;
    for(int i = 1; i < top; i++){
        cout << p[i].data << ' ' << p[i].id << " ";
        printf("%.1lf\n", p[i].t);
    }
}