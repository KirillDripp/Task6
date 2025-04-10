#include <stdio.h>
#include "bst.h"

int main() {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};

    // Вставка значень у дерево
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    // Виведення дерева ін-ордером
    printf("BST in-order: ");
    BSTInOrder(root);
    printf("\n");

    // Очищення пам'яті
    BSTFree(root);
    return 0;
}

