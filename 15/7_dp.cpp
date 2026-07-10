#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Stick {
    int w, l;  // 重量，长度（注意顺序！）
};

bool cmp(const Stick& a, const Stick& b) {
    if (a.w != b.w) return a.w < b.w;
    return a.l < b.l;
}

int main() {
    int n;
    cin >> n;
    
    vector<Stick> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i].w >> sticks[i].l;  // 先重量后长度
    }
    
    sort(sticks.begin(), sticks.end(), cmp);
    
    vector<int> lastLengths;  // 每个子序列最后一个长度
    
    for (int i = 0; i < n; i++) {
        int l = sticks[i].l;
        
        // 找第一个 > l 的位置，替换它（使末尾尽可能小）
        auto it = upper_bound(lastLengths.begin(), lastLengths.end(), l);
        
        if (it == lastLengths.end()) {
            lastLengths.push_back(l);
        } else {
            *it = l;
        }
    }
    
    cout << lastLengths.size() << endl;
    
    return 0;
}
