#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("in.txt");
    int n;
    fin >> n;
    
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
    }
    fin.close();
    
    // 1. 处理Y坐标：取中位数
    sort(y.begin(), y.end());
    int medianY = y[n / 2];  // 中位数（n为奇数时正中间，偶数时中间偏右也可以）
    long long totalSteps = 0;
    for (int i = 0; i < n; i++) {
        totalSteps += abs(y[i] - medianY);
    }
    
    // 2. 处理X坐标：先排序，再减去索引，取中位数
    sort(x.begin(), x.end());
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = x[i] - i;
    }
    sort(a.begin(), a.end());
    int medianX = a[n / 2];
    for (int i = 0; i < n; i++) {
        totalSteps += abs(a[i] - medianX);
    }
    
    cout << totalSteps << endl;
    
    return 0;
}
