#include <iostream>
#include <vector>
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
	vector<vector<int> > sol;
	
	bool searchSum(TreeNode* root, int sum, vector<int>& v){
		if (!root) return false;
		if (!root->left && !root->right && root->val==sum) {
    		sol.push_back(v);
    		sol[sol.size()-1].push_back(sum);
    		return true;
		}
    		
    		
    	bool ret = false;
    	if (root->left) {
    		v.push_back(root->val);
    		ret |= searchSum(root->left, sum-root->val, v);
    		v.pop_back();
    	}
    	
    	if (root->right) {
    		v.push_back(root->val);
    		ret |= searchSum(root->right, sum-root->val, v);
    		v.pop_back();
    	}
    	return ret;
	}
	
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<int> v;
    	sol.clear();
    	searchSum(root, sum, v);
    	return sol;
    }
};

int main() {
	//TreeNode root(1, new TreeNode(3), new TreeNode(3));
	TreeNode root(1);
	Solution s;
	vector<vector<int> > sol = s.pathSum(&root, 0);
	cout << sol.size() << " solutions" << endl;
	for (int i = 0; i < sol.size(); ++i){
		for (int j = 0; j < sol[i].size(); ++j){
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}