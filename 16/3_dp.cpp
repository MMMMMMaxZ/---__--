#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RabinKarp {
private:
    const int base = 131;      // 哈希基数
    const int mod = 1e9 + 7;   // 模数（大质数）
    string text, pattern;
    vector<long long> pow;     // 存储base的幂次
    vector<long long> hash;    // 存储文本的前缀哈希值
    
public:
    RabinKarp(const string& t, const string& p) : text(t), pattern(p) {
        int n = text.length();
        int m = pattern.length();
        
        // 预处理base的幂次
        pow.resize(n + 1);
        pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow[i] = (pow[i-1] * base) % mod;
        }
        
        // 计算文本的前缀哈希
        hash.resize(n + 1);
        hash[0] = 0;
        for (int i = 0; i < n; i++) {
            hash[i+1] = (hash[i] * base + (text[i] - 'a' + 1)) % mod;
        }
    }
    
    // 计算子串的哈希值 [l, r]，索引从0开始
    long long getHash(int l, int r) {
        // 注意：这里加上mod再取模，防止出现负数
        return (hash[r+1] - hash[l] * pow[r-l+1] % mod + mod) % mod;
    }
    
    // 计算模式串的哈希值
    long long getPatternHash() {
        long long h = 0;
        for (char c : pattern) {
            h = (h * base + (c - 'a' + 1)) % mod;
        }
        return h;
    }
    
    // 查找所有匹配位置
    vector<int> search() {
        vector<int> matches;
        int n = text.length();
        int m = pattern.length();
        
        if (m > n) return matches;  // 模式串比文本长，无匹配
        
        long long patternHash = getPatternHash();
        
        // 滑动窗口比较
        for (int i = 0; i <= n - m; i++) {
            // 计算文本中当前窗口的哈希值
            long long textHash = getHash(i, i + m - 1);
            
            // 哈希值匹配后，再进行精确比较（防止哈希冲突）
            if (textHash == patternHash) {
                // 精确比较
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    matches.push_back(i);  // 转换为1-indexed
                }
            }
        }
        
        return matches;
    }
};

int main() {
    string text, pattern;
    cin >> text >> pattern;
    
    RabinKarp rk(text, pattern);
    vector<int> result = rk.search();
    
    if (result.empty()) {
        cout <<"None"<< endl;  // 输出空行
    } else {
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
}
