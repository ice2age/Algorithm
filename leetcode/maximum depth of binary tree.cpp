#include <iostream>
#include <queue>
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
	void searchDepth(TreeNode* root, int depth, int& max) {
		if (!root) {
			if (depth > max)
				max = depth;
			return;
		}
		
		searchDepth(root->left, depth+1, max);
		searchDepth(root->right, depth+1, max);
	}
	
	int maxDepth(TreeNode *root) {
		int max = 0;
		searchDepth(root, 0, max);
		return max;
    }
};

int main() {
	TreeNode root(1, new TreeNode(2), new TreeNode(3, NULL, new TreeNode(4)));
	Solution s;
	cout << s.minDepth(&root) << endl;
	cout << s.maxDepth(&root) << endl;

	return 0;
}