cmake_minimum_required(VERSION 3.10)

project(BSTProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# ������ ������� �����
set(SOURCES
    bst.c
    main.c
)

# ������ �������� ����
set(TEST_SOURCES
    tests/bst_test.cpp
)

# ����� GoogleTest
find_package(GTest REQUIRED)

# ������ �������� �����
add_executable(bst_test ${SOURCES} ${TEST_SOURCES})

# ˳����� � GoogleTest
target_link_libraries(bst_test GTest::GTest GTest::Main)

# ���������� ��� ������� �����
enable_testing()
add_test(NAME bst_test COMMAND bst_test)

