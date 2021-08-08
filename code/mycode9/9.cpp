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
                    cout << cd << " " << top << endl;
                    q.push(top++);
                }
                sum += k;
            } else {
                int cnt = n - sum;
                for (int i = 1; i <= cnt; i++) {
                    g[cd].push_back(top);
                    cout << cd << " " << top << endl;
                    q.push(top++);
                }
                break;
            }
        }
    }

    long long ans = 0;
    vector<int> A;
    int id[200000], cnt = 0;
    void dfs(int u, int fa) {
       id[u] = cnt++; 
       if (fa) {
          //  cout << A[id[u]] << " "<< A[id[fa]] << endl;
            ans += A[id[u]] ^ A[id[fa]];
        }
        
        for (int to: g[u]) {
            dfs(to, u);
        }
    }
    
    long long tree6(int k, vector<int>& a) {
        // write code here
        int n = a.size();
        bfs(1, n, k);
        A = a;
        dfs(1, 0);
        
        return ans;
        
    }
};

vector<int> aa;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		aa.push_back(x);
	}
	Solution s;
	cout << s.tree6(k, aa) << endl;
}