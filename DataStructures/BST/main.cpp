#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    BST *bst = new BST();
    bst->insert(1);
    bst->insert(2);
    bst->insert(3);
    bst->insert(-1);
    bst->insert(-1);
    bst->printBST("");
    return 0;
}