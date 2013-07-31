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
	vector<TreeNode*> generate(int l, int r) {
    	vector<TreeNode*> ret;
    	if (l > r){
    		ret.push_back(NULL);
    		return ret;
    	}
    	
    	for (int i = l; i <= r; ++i){
    		vector<TreeNode*> left = generate(l, i-1);
    		vector<TreeNode*> right = generate(i+1, r);
    		for (int j = 0; j < left.size(); ++j){
    			for (int k = 0; k < right.size(); ++k){
    				TreeNode* tree = new TreeNode(i);
    				tree->left = left[j];
    				tree->right = right[k];
    				ret.push_back(tree);
    			}
    		}
    	}
    	return ret;
	}
	
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};

void inorder(TreeNode* tree) {
	if (!tree) return;
	inorder(tree->left);
	cout << tree->val << " ";
	inorder(tree->right);
}

int main() {
	Solution s;
	int n;
	while (cin >> n){
		vector<TreeNode *> v = s.generateTrees(n);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); ++i){
			inorder(v[i]);
			cout << endl;
		}
	}
	return 0;
}