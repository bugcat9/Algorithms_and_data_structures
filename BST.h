#ifndef _BST_H
#define _BST_H

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 二叉搜索树
 *
 */
class BST
{
private:
    TreeNode *getMin(TreeNode *node)
    {
        // BST 最左边的就是最小的
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

public:
    TreeNode *root;

    BST() : root(nullptr)
    {
    }
    ~BST()
    {
        if (root != nullptr)
        {
            delete root;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (root == nullptr)
            return true;
        if (min != nullptr && root->val <= min->val)
            return false;
        if (max != nullptr && root->val >= max->val)
            return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == val)
        {
            return root;
        }
        else if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
    }

    /**
     * @brief 删除二叉搜索树节点
     *
     * 需要注意这里没有delete要删除的节点，可能存在内存泄漏
     *
     * @param root
     * @param key
     * @return TreeNode*
     */
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == key)
        {
            // 这两个 if 把情况 1 和 2 都正确处理了
            if (root->left == nullptr)
                return root->right;
            if (root->right == nullptr)
                return root->left;
            // 处理情况 3
            // 获得右子树最小的节点
            TreeNode *minNode = getMin(root->right);
            // 删除右子树最小的节点
            root->right = deleteNode(root->right, minNode->val);
            // 用右子树最小的节点替换 root 节点
            minNode->left = root->left;
            minNode->right = root->right;
            // 这里考虑是否删除root 后再进行赋值
            root = minNode;
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};

#endif // _BST_H