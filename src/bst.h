#ifndef _BST_H
#define _BST_H

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/**
 * @brief 二叉搜索树
 *
 */
class BST
{
private:
	TreeNode* getMin(TreeNode* node);

public:
	TreeNode* root;

	BST();
	~BST();

	bool isValidBST(TreeNode* root);

	bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max);

	TreeNode* searchBST(TreeNode* root, int val);

	/**
	 * @brief 删除二叉搜索树节点
	 *
	 * 需要注意这里没有delete要删除的节点，可能存在内存泄漏
	 *
	 * @param root
	 * @param key
	 * @return TreeNode*
	 */
	TreeNode* deleteNode(TreeNode* root, int key);

	TreeNode* insertIntoBST(TreeNode* root, int val);
};

#endif // _BST_H