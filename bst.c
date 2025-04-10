#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

// Вставка елемента в дерево
NodePtr BSTInsert(NodePtr root, int key) {
    if (root == NULL) {
        root = (NodePtr)malloc(sizeof(Node));
        root->key = key;
        root->left = root->right = NULL;
    } else if (key < root->key) {
        root->left = BSTInsert(root->left, key);
    } else {
        root->right = BSTInsert(root->right, key);
    }
    return root;
}

// Виведення елементів дерева ін-ордер
void BSTInOrder(NodePtr root) {
    if (root != NULL) {
        BSTInOrder(root->left);
        printf("%d ", root->key);
        BSTInOrder(root->right);
    }
}

// Знаходження наступного найменшого елемента, що більший або рівний заданому ключу
NodePtr BSTCeiling(NodePtr root, int key) {
    NodePtr ceil = NULL;
    while (root != NULL) {
        if (key == root->key) {
            return root;
        } else if (key < root->key) {
            ceil = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ceil;
}

// Метод для підрахування кількості елементів, що менші за заданий ключ
int BSTRank(NodePtr root, int key) {
    int rank = 0;
    while (root != NULL) {
        if (key < root->key) {
            root = root->left;
        } else if (key > root->key) {
            rank += (root->left ? 1 : 0) + 1; // Ліві піддерева + сам елемент
            root = root->right;
        } else {
            rank += (root->left ? 1 : 0);
            break;
        }
    }
    return rank;
}

// Фунцкція, яка повинна повернути k-й за величиною елемент у дереві
NodePtr BSTSelect(NodePtr root, int rank) {
    if (root == NULL) return NULL;
    int leftSize = root->left ? 1 : 0; // Розмір лівого піддерева
    if (rank == leftSize) {
        return root;
    } else if (rank < leftSize) {
        return BSTSelect(root->left, rank);
    } else {
        return BSTSelect(root->right, rank - leftSize - 1);
    }
}

// Повертаємо найменший елемент у дереві
int BSTMin(NodePtr root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->key;
}

// Повертаємо найбільший елемент у дереві
int BSTMax(NodePtr root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}

// Видалення максимального елемента з дерева
NodePtr BSTDeleteMax(NodePtr root) {
    if (root->right == NULL) {
        NodePtr leftChild = root->left;
        free(root);
        return leftChild;
    }
    root->right = BSTDeleteMax(root->right);
    return root;
}

// Виведення елементів дерева в зворотньому порядку
void BSTPrintReverse(NodePtr root) {
    if (root != NULL) {
        BSTPrintReverse(root->right);
        printf("%d ", root->key);
        BSTPrintReverse(root->left);
    }
}

// Очищення пам'яті
void BSTFree(NodePtr root) {
    if (root != NULL) {
        BSTFree(root->left);
        BSTFree(root->right);
        free(root);
    }
}
