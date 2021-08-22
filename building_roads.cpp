#include<bits/stdc++.h>
using namespace std;

int par[100002];
int vis[100002];

int find(int x){
	vector<int> vi;
	while(par[x]>0){
		vi.push_back(x);
		x=par[x];
	}
	for(int i=0;i<vi.size();i++){
		par[vi[i]]=x;
	}
	return x;
}

int unioner(int y,int z){
	par[y]+=par[z];
	par[z]=y;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		par[i]=-1;
	}
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a=find(a);
		b=find(b);
		if(a!=b){
			unioner(a,b);
		}
	}
	int count=0;
	int marker=-1;
	for(int i=1;i<=n;i++){
		if(par[i]<0){
			marker=i;
			break;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		if(par[i]<0){
			count++;
		}
	}
	
	cout<<count-1<<endl;
	
	for(int i=marker+1;i<=n;i++){
		if(par[i]<0)
		cout<<marker<<" "<<i<<endl;
	}
	
	return 0;
}
