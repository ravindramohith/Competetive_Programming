#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

bool BST::insert(int data)
{
    if (this->root == NULL)
    {
        this->root = new TreeNode(data);
        return true;
    }
    else
    {
        TreeNode *node = this->root;
        while (node != NULL)
        {
            if (data < node->data)
            {
                if (node->left == NULL)
                {
                    node->left = new TreeNode(data);
                    return true;
                }
                else
                    node = node->left;
            }
            else if (data > node->data)
            {
                if (node->right == NULL)
                {
                    node->right = new TreeNode(data);
                    return true;
                }
                else
                    node = node->right;
            }
            else
                return false;
        }
    }
    return false;
}

int BST::findMin()
{
    TreeNode *current = this->root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int BST::findMax()
{
    TreeNode *current = this->root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

TreeNode *BST::find(int data)
{
    TreeNode *current = this->root;
    while (current != NULL)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            return current;
        }
    }
    return NULL;
}

bool BST::isPresent(int data)
{
    TreeNode *current = this->root;
    while (current != NULL)
    {
        if (data == current->data)
        {
            return true;
        }
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}

void BST::printBST(const string &prefix, bool isLeft)
{
    if (root != nullptr)
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "|__");

        // print the value of the node
        cout << root->data << endl;
        TreeNode *curr = root;
        root = root->left;
        // enter the next tree level - left and right branch
        printBST(prefix + (isLeft ? "│   " : "    "), true);
        root = curr->right;
        printBST(prefix + (isLeft ? "│   " : "    "), false);
        root = curr;
    }
}
