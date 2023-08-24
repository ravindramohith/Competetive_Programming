#include <bits/stdc++.h>
using namespace std;

// Binary search tree time complexity
// ╔═══════════╦══════════╦════════════╗
// ║ Algorithm ║ Average  ║ Worst Case ║
// ╠═══════════╬══════════╬════════════╣
// ║ Space     ║ O(n)     ║ O(n)       ║
// ║ Search    ║ O(log n) ║ O(n)       ║
// ║ Insert    ║ O(log n) ║ O(n)       ║
// ║ Delete    ║ O(log n) ║ O(n)       ║
// ╚═══════════╩══════════╩════════════╝

class TreeNode
{
public:
    TreeNode *left;
    int data;
    TreeNode *right;
    TreeNode(int data, TreeNode *left = nullptr, TreeNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BST
{
private:
    TreeNode *root;

public:
    BST() { root = nullptr; }
    TreeNode *getRoot() { return root; }
    bool insert(int data);
    int findMin();
    int findMax();
    TreeNode *find(int data);
    bool isPresent(int data);
    void printBST(const string &prefix, bool isLeft = false);
    // void iInsert(int data);
    // void Inorder(TreeNode *p);
    // TreeNode *iSearch(int data);
    // TreeNode *rInsert(TreeNode *p, int data);
    // TreeNode *rSearch(TreeNode *p, int data);
    // TreeNode *Delete(TreeNode *p, int data);
    // int Height(TreeNode *p);
    // TreeNode *InPre(TreeNode *p);
    // TreeNode *InSucc(TreeNode *p);
};
