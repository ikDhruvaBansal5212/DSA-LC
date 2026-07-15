class Solution {
public:
    int timer=1;

    void dfs(int node,int parent,vector<int>&vis,vector<int>&tim,vector<int>&low,vector<vector<int>>&bridges,vector<vector<int>>&adj){
        vis[node]=1;
        tim[node]=low[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;

            if(vis[it]==0){
                dfs(it,node,vis,tim,low,bridges,adj);
                low[node]=min(low[node],low[it]);

                if(low[it]>tim[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>tim(n);
        vector<int>low(n);
        vector<vector<int>>bridges;
        dfs(0,-1,vis,tim,low,bridges,adj);
        return bridges;
    }
};