class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& e: edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n,vector<int>(k+1,INF));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();
            
          
            if (d > dist[u][count]) continue;
           
            if (u == n - 1) return d;
            
            for (const auto& [v, w] : adj[u]) {
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                
                
                if (next_count <= k) {
                    int next_dist = d + w;
                    
                    if (next_dist < dist[v][next_count]) {
                        dist[v][next_count] = next_dist;
                        pq.push({next_dist, v, next_count});
                    }
                }
            }
        }
        return -1;
    }
};