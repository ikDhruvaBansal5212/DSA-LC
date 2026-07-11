class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>col(V,-1);
         for(int i=0;i<V;i++){    
            if(col[i]!=-1) continue;
            queue<int>q;
            q.push(i);
            col[i]=0;

            while(!q.empty()){
                int node=q.front();
                q.pop();
                int color=col[node];
                int new_color;
                if(color==0) new_color=1;
                if(color==1) new_color=0;

                for(auto it:graph[node]){
                    if(col[it]==-1){
                        col[it]=new_color;
                        q.push(it);
                    }
                    else{
                        if(col[it]==color) return false;
                    }
                }
            }
        }
        return true;
    }
};