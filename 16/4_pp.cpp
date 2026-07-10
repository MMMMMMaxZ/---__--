#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListMergeSort {
private:
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
        
        if (left) tail->next = left;
        if (right) tail->next = right;
        
        return dummy.next;
    }
    
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
    
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = getMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = nullptr;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightHead);
        
        return merge(left, right);
    }
    
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    
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
	freopen("in.txt","r+",stdin);
	freopen("out.txt","w+",stdout);
    string line;
    getline(cin, line);
    
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

    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    
    LinkedListMergeSort sorter;
    ListNode* sortedHead = sorter.sortList(head);
    
    sorter.printList(sortedHead);
    return 0;
}
