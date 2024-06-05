#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <unordered_map> // 使用哈希表
#include <stack>         // 使用栈
#include <string>        // 使用字符串
#include <utility>
using namespace std;
typedef long long ll;       // 定义long long类型的简写为ll
typedef long double ld;     // 定义long double类型的简写为ld
typedef pair<int, int> pii; // 定义pair<int, int>类型的简写为pii
typedef pair<ll, ll> pll;   // 定义pair<ll, ll>类型的简写为pll
typedef vector<int> vi;     // 定义vector<int>类型的简写为vi
//--------------------------------模板--------------------------------//

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 
//--------------------------------模板--------------------------------// 二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        } // 节点为0 返回0
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
};

int main() 
{
     // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution; // 创建一个 Solution 类的实例
    int diameter = solution.diameterOfBinaryTree(root); // 计算二叉树的直径
    cout << "The diameter of the binary tree is: " << diameter << endl; // 输出结果
    
    

    // 释放二叉树的内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root; 
    return 0;

   
}