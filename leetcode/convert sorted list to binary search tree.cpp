#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(int* num, int n) {
    	if (n == 0) return NULL;
        TreeNode* root = new TreeNode(num[n/2]);
        if (n == 1) return root;
        
        root->left = buildTree(num, n/2);
        root->right = buildTree(num+n/2+1, n-n/2-1);
        return root;
	}
    TreeNode *sortedArrayToBST(vector<int> &num) {
       return buildTree(&num[0], num.size());
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> vec;
        while (head != NULL){
        	vec.push_back(head->val);
        	head = head->next;
        }
        return sortedArrayToBST(vec);
    }
};

void inorder(TreeNode* tree) {
	if (!tree) return;
	inorder(tree->left);
	cout << tree->val << " ";
	inorder(tree->right);
}

int main() {
	ListNode list(0);
	ListNode* cur = &list;
	for (int i = 1; i < 10; ++i) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	
	Solution s;
	TreeNode* tree = s.sortedListToBST(&list);
	inorder(tree);
	
	return 0;
}