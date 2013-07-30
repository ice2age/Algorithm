#include <iostream>
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
	bool balanced;
	int height(TreeNode* root) {
    	if (!root) return 0;
    	int l = height(root->left);
    	int r = height(root->right);
    	if (abs(l-r) > 1)
    		balanced = false;
    	
    	return max(l, r) + 1;
	}
	
    bool isBalanced(TreeNode *root) {
    	if (!root)
    		return true;
    	balanced = true;
    	height(root);
    	return balanced;
    }
};

int main() {
	return 0;
}