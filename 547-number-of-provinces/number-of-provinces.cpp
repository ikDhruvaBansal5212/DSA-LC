class Solution {
public:
    void solve(int node,vector<vector<int>> &adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n, 0);

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1) adj[i].push_back(j);
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res++;
                solve(i,adj,vis);
            }
        }
        return res;

    }
};