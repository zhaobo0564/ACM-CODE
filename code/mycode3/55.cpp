// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// int n;
// ll a[300];
// int ans;
// ll fn[60];

// struct node{
// 	int u,v;
// 	node(){}
// 	node(int u,int v){
// 		this->u=u;
// 		this->v=v;
// 	}
// 	bool operator <(const node n)const{	
// 		return v>n.v;
// 	}
// }; 

// priority_queue<node>q;
// int bfs(){
//     q.push({1, 0});
//     while(q.size()){
//         node cd = q.top();
//         q.pop();
//         //cout << cd.u << " " <<cd.v << endl;
//         if(cd.u == n){
//             return cd.v;
//         }
//         if(a[cd.u + 1] - a[cd.u] == 1){
//             q.push(node(cd.u + 1, cd.v + 1));
//         }
//         for(int i = 1; i < min(31, cd.u); i++){
//             int c = lower_bound(a + 1, a + n + 1, a[cd.u - i] + fn[i]) - a;
//             if(a[c] > a[cd.u - i] + fn[i]){
//                 c--;
//             }
//             if(c <= cd.u)continue;
//             q.push(node(c, cd.v + i + 1));
//         }
//     }
//     return -1;
// }

// int main(){
//     fn[0] = 1;
//     for(int i = 1; i <=  40; i++){
//         fn[i] = fn[i - 1] * 2;
//     }
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++){
//         scanf("%lld", &a[i]);
//     }
//     a[n + 1] = INT_MAX;
//     printf("%d\n", bfs());
// }

#include<bits/stdc++.h>
using namespace std;


