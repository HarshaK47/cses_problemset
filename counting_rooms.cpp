#include<bits/stdc++.h>
using namespace std;
char ar[1002][1002];
int vis[1002][1002];




void dfs(int i,int j,int n,int m){
	if(i<0 or j<0 or j>=m or i>=n){
		return;
	}
	if(ar[i][j]=='#') return ;
	
	if(vis[i][j]==0){
		vis[i][j]=1;
		
		dfs(i-1,j,n,m);
		
		dfs(i,j+1,n,m);
		
		dfs(i+1,j,n,m);
		
		dfs(i,j-1,n,m);
	}
}

int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ar[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vis[i][j]=0;
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==0 and ar[i][j]=='.'){
				count++;
				dfs(i,j,n,m);
			}
		}
	}
	cout<<count<<endl;
	
	
	
	return 0;
}
