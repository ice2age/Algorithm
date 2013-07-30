#include <iostream>
using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l = NULL, TreeNode* r = NULL) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
    	if (!root) return false;
    	if (!root->left && !root->right && root->val==sum)
    		return true;
    	
    	bool ret = false;
    	if (root->left)
    		ret |= hasPathSum(root->left, sum-root->val);
    	if (root->right)
    		ret |= hasPathSum(root->right, sum-root->val);
    	return ret;
    }
};

int main() {
	TreeNode root(1, new TreeNode(2), new TreeNode(3));
	Solution s;
	cout << s.hasPathSum(&root, 5);
	
	return 0;
}