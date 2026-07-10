#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

class TreeNode {
public:
    int left;   // 左孩子索引
    int right;  // 右孩子索引
    TreeNode() : left(-1), right(-1) {}
};

class BinaryTree {
private:
    vector<TreeNode> nodes;
    int root;
    int diameter;
    
    // 后续遍历DFS，返回节点深度，同时更新直径
    int dfs(int nodeIdx) {
        if (nodeIdx == -1) return 0;
        
        int leftDepth = dfs(nodes[nodeIdx].left);
        int rightDepth = dfs(nodes[nodeIdx].right);
        
        // 经过当前节点的最长路径 = 左子树深度 + 右子树深度
        diameter = max(diameter, leftDepth + rightDepth);
        
        // 返回当前节点的深度
        return max(leftDepth, rightDepth) + 1;
    }
    
public:
    BinaryTree(int n) {
        nodes.resize(n);
        root = -1;
        diameter = 0;
    }
    
    void setChildren(int idx, int leftIdx, int rightIdx) {
        nodes[idx].left = leftIdx;
        nodes[idx].right = rightIdx;
    }
    
    void setRoot(int r) {
        root = r;
    }
    
    int getDiameter() {
        if (root == -1) return 0;
        dfs(root);
        return diameter;
    }
};

int main() {
    int N;
    cin >> N;
    
    BinaryTree tree(N);
    
    // 存储节点值到索引的映射
    vector<int> valueToIndex(10000, -1);  // 假设节点值范围在0-9999
    
    // 临时存储输入信息
    vector<int> parentVals(N);
    vector<int> leftVals(N);
    vector<int> rightVals(N);
    
    // 第一遍读取：建立值到索引的映射
    for (int i = 0; i < N; i++) {
        int parentVal;
        string leftStr, rightStr;
        
        cin >> parentVal >> leftStr >> rightStr;
        
        parentVals[i] = parentVal;
        valueToIndex[parentVal] = i;
        
        if (leftStr != "#") {
            leftVals[i] = stoi(leftStr);
        } else {
            leftVals[i] = -1;
        }
        
        if (rightStr != "#") {
            rightVals[i] = stoi(rightStr);
        } else {
            rightVals[i] = -1;
        }
    }
    
    // 第二遍处理：将孩子的值转换为索引
    for (int i = 0; i < N; i++) {
        int leftIdx = -1, rightIdx = -1;
        
        if (leftVals[i] != -1) {
            leftIdx = valueToIndex[leftVals[i]];
        }
        
        if (rightVals[i] != -1) {
            rightIdx = valueToIndex[rightVals[i]];
        }
        
        tree.setChildren(i, leftIdx, rightIdx);
        
        // 第一个节点是根节点
        if (i == 0) {
            tree.setRoot(i);
        }
    }
    
    // 计算并输出直径
    cout << tree.getDiameter() << endl;
    
    return 0;
}
