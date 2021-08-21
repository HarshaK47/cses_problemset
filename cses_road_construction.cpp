#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int par[100003];
int maxsize=1;

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

int unioner(int &maxsize,int m,int n){
	par[m]+=par[n];
	par[n]=m;
	maxsize=max(maxsize,-par[m]);
	return maxsize;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		par[i]=-1;
	}
	int maxsize=1;
	int connected=n;
	
	int ans1[m];
	int ans2[m];
	int key=0;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a=find(a);
		b=find(b);
		int an2;
		if(a!=b){
			an2=unioner(maxsize,a,b);
			connected--;
		}
		
		
		ans1[key]=connected;
		ans2[key]=an2;
		key++;
		
	}
	
	for(int i=0;i<m;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	
	return 0;
}
