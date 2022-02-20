#include <bits/stdc++.h>
using namespace std;
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
vector<vector<int>> dict;
vector<vector<int>> visited;
void dfs(vector<vector<int>>& dict,int x, int y,int &ret, int last){
    for(int i=0;i<4; i++){
        int newx = x+dirs[i][0], newy = y+dirs[i][1];
        if(newx<0||newy<0||newx>=n||newy>=n||dict[newx][newy]==last||visited[newx][newy]==0)continue;
        visited[newx][newy] = 0;
        ret++;
        dfs(dict, newx,newy,ret,dict[newx][newy]);
    }
}
int main () {
	cin>>n>>m;
    dict = vector<vector<int>>(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for (int j = 0; j < n; j++)
        {
            dict[i][j] = s[j];
        }
        
    }
    while(m--){
        int a,b, ret = 0;
        visited = vector<vector<int>>(n,vector<int>(n,1));
        cin>>a>>b;
        a--;b--;
        dfs(dict,a,b,ret,!dict[a][b]);
        cout<<ret<<endl;
    }
	return 0;
}