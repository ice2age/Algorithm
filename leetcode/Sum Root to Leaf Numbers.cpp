#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
	void traverse(TreeNode* root, int cur) {
		if (!root) return;
		cur = 10 * cur + root->val;
		if (!root->left && !root->right)
			sum += cur;
		if (root->left)
			traverse(root->left, cur);
		if (root->right)
			traverse(root->right, cur);
	}

	int sumNumbers(TreeNode *root) {
		sum = 0;
		traverse(root, 0);
		return sum;
	}
private:
	int sum;
};

int main(void)
{
	TreeNode l1(4, NULL, NULL);			//     1
	TreeNode r1(5, NULL, NULL);			//   2   3
	TreeNode left(2, &l1, &r1);			// 4   5
	TreeNode right(3, NULL, NULL);
	TreeNode root(1, &left, &right);  
	Solution s;
	cout << s.sumNumbers(&root) << endl;

	return 0;
}