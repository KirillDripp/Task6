#include <gtest/gtest.h>
#include "bst.h"
#include <string>

// 1. Тест вставки та виведення дерева ін-ордер
TEST(BSTTest, InsertAndInOrder) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    testing::internal::CaptureStdout();
    BSTInOrder(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 3 4 5 7 8 10 ");
    BSTFree(root);
}

// 2. Тест функції BSTCeiling
TEST(BSTTest, Ceiling) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    Key target = 6;
    NodePtr ceilNode = BSTCeiling(root, target);
    EXPECT_EQ(ceilNode->key, 7);

    BSTFree(root);
}

// 3. Тест функції BSTRank
TEST(BSTTest, Rank) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    EXPECT_EQ(BSTRank(root, 6), 4);

    BSTFree(root);
}

// 4. Тест функції BSTSelect
TEST(BSTTest, Select) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    NodePtr node = BSTSelect(root, 3);
    EXPECT_EQ(node->key, 4);

    BSTFree(root);
}

// 5. Тест функцій BSTMin та BSTMax
TEST(BSTTest, MinMax) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    EXPECT_EQ(BSTMin(root), 1);
    EXPECT_EQ(BSTMax(root), 10);

    BSTFree(root);
}

// 6. Тест функції BSTDeleteMax
TEST(BSTTest, DeleteMax) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    root = BSTDeleteMax(root);
    EXPECT_EQ(BSTMax(root), 8);

    BSTFree(root);
}

// 7. Тест функції BSTPrintReverse
TEST(BSTTest, PrintReverse) {
    NodePtr root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 10};
    for (int i = 0; i < 7; ++i) {
        root = BSTInsert(root, values[i]);
    }

    testing::internal::CaptureStdout();
    BSTPrintReverse(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 8 7 5 4 3 1 ");

    BSTFree(root);
}

// Додати main функцію для запуску тестів
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
