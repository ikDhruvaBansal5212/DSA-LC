class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; //{dist,node}
        int res = 0;
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if (cost > dist[node])
                continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int edwt = it.second;

                if (cost + edwt < dist[adjnode]) {
                    dist[adjnode] = cost + edwt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};