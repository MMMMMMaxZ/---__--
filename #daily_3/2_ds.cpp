#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> graph(n);  // 节点从0开始
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        indegree[v]++;
        outdegree[u]++;
    }
    
    // 拓扑排序
    queue<int> q;
    vector<int> topo;
    vector<int> indegCopy = indegree;
    vector<int> dist(n, 0);
    
    // 将所有入度为0的节点入队
    for (int i = 0; i < n; i++) {
        if (indegCopy[i] == 0) {
            q.push(i);
        }
    }
    
    // 如果没有入度为0的节点，说明有环
    if (q.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    // 拓扑排序 + 计算最长路径
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            
            // 更新最长路径
            dist[v] = max(dist[v], dist[u] + w);
            
            indegCopy[v]--;
            if (indegCopy[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // 检查是否有环
    if ((int)topo.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    // 找到所有出度为0的节点（汇点），取最大值
    int maxDist = 0;
    for (int i = 0; i < n; i++) {
        if (outdegree[i] == 0) {
            maxDist = max(maxDist, dist[i]);
        }
    }
    
    cout << maxDist << endl;
    
    return 0;
}
