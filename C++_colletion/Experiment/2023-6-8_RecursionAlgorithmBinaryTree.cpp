#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode
{
    
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 先序遍历二叉树，并输出节点值
void preorderTraversal(TreeNode *root, vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }

    result.push_back(root->val);            // 输出当前节点的值
    preorderTraversal(root->left, result);  // 递归遍历左子树
    preorderTraversal(root->right, result); // 递归遍历右子树
}

// 遍历二叉树，找到所有叶子节点
void findLeafNodes(TreeNode *root, vector<int> &leafNodes)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        leafNodes.push_back(root->val); // 当前节点是叶子节点
        return;
    }

    findLeafNodes(root->left, leafNodes);  // 递归遍历左子树
    findLeafNodes(root->right, leafNodes); // 递归遍历右子树
}

int main()
{
    // 构建二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 先序遍历并输出结果
    vector<int> preorderResult;
    preorderTraversal(root, preorderResult);
    cout << "先序遍历序列：";
    for (int val : preorderResult)
    {
        cout << val << " ";
    }
    cout << endl;

    // 查找叶子节点并输出结果
    vector<int> leafNodes;
    findLeafNodes(root, leafNodes);
    cout << "叶子节点：";
    for (int val : leafNodes)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
