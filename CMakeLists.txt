cmake_minimum_required(VERSION 3.10)

project(BSTProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Додаємо вихідні файли
set(SOURCES
    bst.c
    main.c
)

# Додаємо тестовий файл
set(TEST_SOURCES
    tests/bst_test.cpp
)

# Пошук GoogleTest
find_package(GTest REQUIRED)

# Додаємо бібліотеку тестів
add_executable(bst_test ${SOURCES} ${TEST_SOURCES})

# Лінкуємо з GoogleTest
target_link_libraries(bst_test GTest::GTest GTest::Main)

# Інструкції для запуску тестів
enable_testing()
add_test(NAME bst_test COMMAND bst_test)

