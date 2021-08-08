#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param k int整型 表示完全k叉树的叉数k
     * @param a int整型vector 表示这棵完全k叉树的Dfs遍历序列的结点编号
     * @return long长整型
     */
    
    long long fn[200000];
    vector<int> g[200000];
    void bfs(int d, int n, int k) {
        queue<int> q;  
        q.push(1);
        int top = 2;
        int sum = 1;
        while (q.size()) {
            int cd = q.front();
            q.pop();
            if (sum + k <= n) {
                for (int i = 1; i <= k; i++) {
                    g[cd].push_back(top);
                    q.push(top++);
                }
                sum += k;
            } else {
                int cnt = n - sum;
                for (int i = 1; i <= cnt; i++) {
                    g[cd].push_back(top);
                    q.push(top++);
                }
                break;
            }
        }
    }
    int id = 0;
    long long ans = 0;
    vector<int> A;
    void dfs(int u, int fa, int fid) {
        if (fa) {
            ans += A[fid] ^ A[id];
        }
        id++;
        for (int to: g[u]) {
            dfs(to, u, id - 1);
        }
    }
    
    long long tree6(int k, vector<int>& a) {
        // write code here
        int n = a.size();
        bfs(1, n, k);
        A = a;
        dfs(1, 0, 0);
        
        return ans;
        
    }
};

vector<int> a;

int main() {
	int n, k;
	puts("AA");
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a.push_back(x);
	}
	Solution s;
	cout << s.tree6(k, a) << endl;
}