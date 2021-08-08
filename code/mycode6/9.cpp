long long ans[50007], maxn[50007][20], minn[50007][20], Log[50007];

void init(){
	Log[1] = 0;//预处理log函数 
	for(int i = 2;i <= n+1;i++) Log[i] = Log[i/2]+1;
	for(int i = 1;i <= n;i++) maxn[i][0] = minn[i][0] = ans[i];
	for(int j = 1; (1<<j) <= n;j++){	//涉及到位运算多加括号! 
		for(int i = 1;i + (1<<(j-1)) <= n;i++){
			maxn[i][j] = max(maxn[i][j-1], maxn[i+(1<<(j-1))][j-1]);
            minn[i][j] = min(minn[i][j-1], minn[i+(1<<(j-1))][j-1]);
    	}
	}
}
long long ask_mx(int l,int r){
	int k = Log[r-l+1];
    ll mx = max(maxn[l][k],maxn[r-(1<<k)+1][k]);
	
	return mx;
}

long long  ask_min(int l, int r){
    int k = Log[r-l+1];
	ll mi = min(minn[l][k],minn[r-(1<<k)+1][k]);
	
	return mi;
}length