#include <iostream>
#include <string>
using namespace std;

class UnionFind {
private:
    int* parent;  // 父节点数组
    int* rank;    // 秩（树的高度）
    int* size;    // 集合大小
    int n;        // 元素数量
    
public:
    // 构造函数
    UnionFind(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        size = new int[n];
        
        // 初始化：每个元素自成一个集合
        for (int i = 0; i < n; i++) {
            parent[i] = i;    // 自己是自己的父节点
            rank[i] = 0;      // 初始秩为0
            size[i] = 1;      // 初始集合大小为1
        }
    }
    
    // 析构函数
    ~UnionFind() {
        delete[] parent;
        delete[] rank;
        delete[] size;
    }
    
    // 查找操作（带路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            // 路径压缩：递归找到根节点，并将路径上的节点直接指向根
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // 合并操作（按秩合并）
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // 如果已经在同一个集合，不需要合并
        if (rootX == rootY) {
            return;
        }
        
        // 按秩合并：将秩小的树合并到秩大的树下
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            // 秩相等时，任选一个作为根，并增加秩
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
    }
    
    // 查询：返回代表元素和集合大小
    pair<int, int> query(int x) {
        int root = find(x);
        return {root, size[root]};
    }
    
    // 判断两个元素是否在同一个集合
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n);
    
    string op;
    int x, y;
    
    for (int i = 0; i < m; i++) {
        cin >> op;
        
        if (op == "union") {
            cin >> x >> y;
            uf.unionSets(x, y);
        } else if (op == "query") {
            cin >> x;
            pair<int, int> result = uf.query(x);
            cout << result.first << " " << result.second << endl;
        } else if (op == "same") {
            cin >> x >> y;
            if (uf.same(x, y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}
