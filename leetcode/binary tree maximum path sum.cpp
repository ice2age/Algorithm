#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode* l=NULL, TreeNode* r=NULL) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int max;
	int getMax(TreeNode* root) {
		int left = 0;
		int right = 0;
		if (root->left) {
			left = std::max(0, getMax(root->left));
		}

		if (root->right) 
			right = std::max(0, getMax(root->right));
		
		int m = (left > right ? left : right);
		int mx = left + right + root->val;
		if (mx > max)
			max = mx;
		return root->val + m;
	}

	int maxPathSum(TreeNode *root) {
		max = numeric_limits<int>::min();
		this->getMax(root);
		return max;
	}
};

int main() {
	Solution s;
	TreeNode root(-3);
	
	cout << s.maxPathSum(&root) << endl;
	return 0;
}