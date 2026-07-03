#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        // Build the adjacency list: adj[u] = {{v, cost}, ...}
        vector<vector<pair<int, int>>> adj(n);
        int max_cost = 0;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            max_cost = max(max_cost, cost);
        }
        
        // Helper lambda to check if a valid path exists where all edge costs >= min_allowed_cost
        auto isValid = [&](int min_allowed_cost) -> bool {
            // min-heap priority queue storing {current_total_cost, current_node}
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            vector<long long> dist(n, -1);
            
            pq.push({0, 0});
            dist[0] = 0;
            
            while (!pq.empty()) {
                auto [curr_cost, u] = pq.top();
                pq.pop();
                
                if (curr_cost > dist[u]) continue;
                if (u == n - 1) return curr_cost <= k;
                
                for (const auto& [v, edge_cost] : adj[u]) {
                    // Skip edges that drop below our binary search threshold
                    if (edge_cost < min_allowed_cost) continue;
                    
                    // Skip offline destination nodes (except the destination node n-1)
                    if (!online[v] && v != n - 1) continue;
                    
                    long long next_cost = curr_cost + edge_cost;
                    if (next_cost <= k && (dist[v] == -1 || next_cost < dist[v])) {
                        dist[v] = next_cost;
                        pq.push({next_cost, v});
                    }
                }
            }
            
            return dist[n - 1] != -1 && dist[n - 1] <= k;
        };
        
        // Binary search for the maximum possible minimum edge cost
        int low = 0, high = max_cost;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                ans = mid;        // mid is possible, record it
                low = mid + 1;    // try to find a larger minimum edge cost
            } else {
                high = mid - 1;   // mid is too restrictive, try smaller values
            }
        }
        
        return ans;
    }
};