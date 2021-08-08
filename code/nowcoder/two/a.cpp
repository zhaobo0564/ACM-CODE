/*4.17 最小费用最大流
4.17.1 SPFA 版费用流
最小费用最大流，求最大费用只需要取相反数，结果取相反数即可。
点的总数为 N，点的编号 0 ∼ N-1*/
const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge{
int to,next,cap,flow,cost;
}edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从 0∼N-1
void init(int n){
N = n;
tol = 0;
memset(head,−1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost){
edge[tol].to = v;
edge[tol].cap = cap;
edge[tol].cost = cost;
edge[tol].flow = 0;
edge[tol].next = head[u];
head[u] = tol++;
edge[tol].to = u;
edge[tol].cap = 0;
25 edge[tol].cost = −cost;
26 edge[tol].flow = 0;
27 edge[tol].next = head[v];
28 head[v] = tol++;
29 }
30 bool spfa(int s,int t){
31 queue<int>q;
32 for(int i = 0;i < N;i++){
33 dis[i] = INF;
34 vis[i] = false;
35 pre[i] = −1;
36 }
37 dis[s] = 0;
38 vis[s] = true;
39 q.push(s);
40 while(!q.empty()){
41 int u = q.front();
42 q.pop();
43 vis[u] = false;
44 for(int i = head[u]; i != −1;i = edge[i].next){
45 int v = edge[i].to;
kuangbin 169
ACM Template of kuangbin
46 if(edge[i].cap > edge[i].flow && dis[v] > dis[u] + edge
[i].cost )
47 {
48 dis[v] = dis[u] + edge[i].cost;
49 pre[v] = i;
50 if(!vis[v]){
51 vis[v] = true;
52 q.push(v);
53 }
54 }
55 }
56 }
57 if(pre[t] == −1)return false;
58 else return true;
59 }
60 //返回的是最大流，cost 存的是最小费用
61 int minCostMaxflow(int s,int t,int &cost){
62 int flow = 0;
63 cost = 0;
64 while(spfa(s,t)){
65 int Min = INF;
66 for(int i = pre[t];i != −1;i = pre[edge[i^1].to]){
67 if(Min > edge[i].cap − edge[i].flow)
68 Min = edge[i].cap − edge[i].flow;
69 }
70 for(int i = pre[t];i != −1;i = pre[edge[i^1].to]){
71 edge[i].flow += Min;
72 edge[i^1].flow −= Min;
73 cost += edge[i].cost * Min;
74 }
75 flow += Min;
76 }
77 return flow;
78 }
