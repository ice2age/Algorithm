#include <iostream>
#include <vector>
using namespace std;


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
};

void inorder(TreeNode* tree) {
	if (!tree) return;
	inorder(tree->left);
	cout << tree->val << " ";
	inorder(tree->right);
}

int main() {
	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	
	Solution s;
	TreeNode* tree = s.sortedArrayToBST(v);
	inorder(tree);
	
	return 0;
}