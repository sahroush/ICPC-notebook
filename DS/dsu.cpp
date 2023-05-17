int par[maxn] , sz[maxn];

int getpar(int v){
	return((v == par[v])?v:par[v]=getpar(par[v]));
}

void merge(int u ,int v){
	u = getpar(u) , v = getpar(v);
	if(u == v)return;
	if(sz[u] > sz[v])swap(u , v);
	par[u]=v,sz[v]+=sz[u];	
}

void init(){
	for(int i = 0 ; i < maxn ; i ++)
		par[i] = i , sz[i] = 1;
}