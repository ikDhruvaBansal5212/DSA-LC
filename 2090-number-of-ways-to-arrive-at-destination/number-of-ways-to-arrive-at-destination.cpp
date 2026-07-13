class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            adj[u].push_back({v, wt}); 
            adj[v].push_back({u, wt});
        }

        vector<long long>dist(n,LLONG_MAX);
        dist[0]=0;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;        
        pq.push({0,0});

        const int MOD = 1e9 + 7;
        vector<long long> ways(n, 0);
        ways[0] = 1;

        while(!pq.empty()){
            int node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();
            if (cost > dist[node])
                continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int edwt = it.second;

                if (cost + edwt < dist[adjnode]) {
                    dist[adjnode] = cost + edwt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if (cost + edwt == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};