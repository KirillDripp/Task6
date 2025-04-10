#ifndef BST_H
#define BST_H

typedef int Key;  // Визначення типу Key
typedef struct Node {
    Key key;
    struct Node* left;
    struct Node* right;
} Node, *NodePtr;

// Декларації функцій
NodePtr BSTInsert(NodePtr root, Key key);
void BSTInOrder(NodePtr root);
NodePtr BSTCeiling(NodePtr root, Key key);
int BSTRank(NodePtr root, Key key);
NodePtr BSTSelect(NodePtr root, int rank);
Key BSTMin(NodePtr root);
Key BSTMax(NodePtr root);
NodePtr BSTDeleteMax(NodePtr root);
void BSTFree(NodePtr root);
void BSTPrintReverse(NodePtr root);

#endif // BST_H

