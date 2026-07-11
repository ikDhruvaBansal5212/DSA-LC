class Solution {
public:
    bool DFS(int node, vector<int>&vis, vector<int>&pathvis, vector<vector<int>> &adj,vector<int>&check) {
		vis[node] = 1;
		pathvis[node] = 1;
        check[node]=0;
		
		for (auto it:adj[node]) {
			if (!vis[it]) {
				if (DFS(it, vis, pathvis, adj,check)){
                    check[node]=0;
					return true;
                }
			}
			else if (pathvis[it]) {
                check[node]=0;
				return true;
			}
		}
			
			pathvis[node] = 0;
            check[node]=1;
			return false;
		};

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
            vector<int>vis(V,0);
            vector<int>pathvis(V,0);
            vector<int>check(V,0);

            vector<int>res;

            for(int j=0;j<V;j++){
                if(!vis[j]){
                    DFS(j,vis,pathvis,graph,check);
                }
            }

            for(int i=0;i<V;i++){
                if(check[i]==1)
                    res.push_back(i);
            }
            return res;
    }
};