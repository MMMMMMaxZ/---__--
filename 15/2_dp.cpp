#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

class HashTable2 {
private:
    int tableSize;
    vector< list<pair<int,int>> > table;  // 每个桶存 key-value 对

public:
    // 构造函数，给定表大小
    HashTable2(int size) : tableSize(size) {
        table.resize(size);
    }

    // 除留余数法哈希函数
    int hash(int key) {
        return key % tableSize;
    }

    // 插入键值对
    void insert(int key, int value) {
        int index = hash(key);
        table[index].push_back({key, value});
    }

    // 计算成功查找的平均查找长度（向下取整）
    int ASL1() {
        int totalComparisons = 0;
        int count = 0;

        for (int i = 0; i < tableSize; ++i) {
            int pos = 1;  // 该桶中第一个元素查找长度为1
            for (auto it = table[i].begin(); it != table[i].end(); ++it, ++pos) {
                totalComparisons += pos;
                count++;
            }
        }

        if (count == 0) return 0;
        return totalComparisons / count;  // 整数除法自动向下取整
    }
};

int main() {
    int n;
    cin >> n;

    // 假设哈希表大小合适（例如取一个比n大的质数，样例中直接用大一点的值）
    HashTable2 ht(n);  // 这里用10，因为key是3,7,13,17,23 对10取模均不同

    for (int i = 0; i < n; ++i) {
        int key, value;
        cin >> key >> value;
        ht.insert(key, value);
    }

    cout << ht.ASL1() << endl;
    return 0;
}
