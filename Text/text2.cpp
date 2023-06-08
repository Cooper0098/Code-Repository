#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树节点的结构体
struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 辅助函数：构建二叉搜索树
Node *buildBST(const vector<int> &postorder, int start, int end)
{
    if (start > end)
        return nullptr;

    // 创建根节点
    int rootValue = postorder[end];
    Node *root = new Node(rootValue);

    // 在后序遍历序列中找到左子树和右子树的分界点
    int divideIndex = start;
    while (divideIndex < end && postorder[divideIndex] < rootValue)
        divideIndex++;

    // 递归构建左子树和右子树
    root->left = buildBST(postorder, start, divideIndex - 1);
    root->right = buildBST(postorder, divideIndex, end - 1);

    return root;
}

// 先序遍历二叉树
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int n;
    cout << "请输入后序遍历序列的元素数量: ";
    cin >> n;

    vector<int> postorder(n);
    cout << "请输入后序遍历序列的元素: ";
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    Node *root = buildBST(postorder, 0, n - 1);

    cout << "先序遍历序列为: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
