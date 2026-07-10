#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListMergeSort {
private:
    // 归并两个有序链表
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        
        // 连接剩余部分
        if (left) tail->next = left;
        if (right) tail->next = right;
        
        return dummy.next;
    }
    
    // 找到链表的中间节点（快慢指针）
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // 二路归并排序
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // 找到中间节点
        ListNode* mid = getMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;  // 断开链表
        
        // 递归排序左右两部分
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightHead);
        
        // 归并两个有序链表
        return merge(left, right);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
    // 打印链表
    void printList(ListNode* head) {
        if (!head) {
            cout << endl;
            return;
        }
        
        ListNode* cur = head;
        bool first = true;
        while (cur) {
            if (!first) cout << " ";
            cout << cur->val;
            first = false;
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    // 读取一行输入
    string line;
    getline(cin, line);
    
    // 解析整数
    vector<int> nums;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    
    if (nums.empty()) {
        cout << endl;
        return 0;
    }
    
    // 创建链表
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    
    // 归并排序
    LinkedListMergeSort sorter;
    ListNode* sortedHead = sorter.sortList(head);
    
    // 输出结果
    sorter.printList(sortedHead);
    
    // 释放内存（可选）
    cur = sortedHead;
    while (cur) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    
    return 0;
}
