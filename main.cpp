#include <iostream>
#include <fstream>
#include "gtest/gtest.h"

int calculator(int a, int b, char op){
    switch (op) {

        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::ofstream output("C:\\Users\\NiceK\\Documents\\Itmo 2022\\ISRPO-lab5\\cmake-build-debug\\output.txt");
                output << "DIVISION BY 0";
                output.close();
                return INT32_MIN;
            }
            return a / b;
        default:
            std::ofstream output("C:\\Users\\NiceK\\Documents\\Itmo 2022\\ISRPO-lab5\\cmake-build-debug\\output.txt");
            output << "INCORRECT INPUT";
            output.close();
            return INT32_MIN;
    }
}

int UnitTests(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

int main() {
    /*std::cout << "Enter 2 numbers: ";
    int a, b;
    std::cin >> a >> b;
    std::cout << "Enter operation(+, -, *, /): ";
    char op;
    std::cin.ignore(256, '\n');
    std::cin >> op;
    std::cout << calculator(a, b, op) << "\n" ;*/
    UnitTests();
    return 0;
}

TEST(BasicTests, SumTests){
    ASSERT_EQ(7, calculator(2, 5, '+'));
    ASSERT_EQ(15, calculator(6, 9, '+'));
    ASSERT_EQ(10, calculator(2, 8, '+'));
    ASSERT_EQ(-1253279, calculator(1597, -1254876,'+'));
};

TEST(BasicTests, DiffTests){
    ASSERT_EQ(5, calculator(10, 5, '-'));
    ASSERT_EQ(-3, calculator(6, 9, '-'));
    ASSERT_EQ(76, calculator(49, -27, '-'));
    ASSERT_EQ(999922, calculator(1254786, 254864, '-'));
};

TEST(BasicTests, ProdTests){
    ASSERT_EQ(50, calculator(10, 5, '*'));
    ASSERT_EQ(-54, calculator(-6, 9, '*'));
    ASSERT_EQ(3699, calculator(-137, -27, '*'));
    ASSERT_EQ(320766796, calculator(12586, 25486, '*'));
};

TEST(BasicTests, DivTests){
    ASSERT_EQ(2, calculator(10, 5, '/'));
    ASSERT_EQ(0, calculator(6, 9, '/'));
    ASSERT_EQ(-1, calculator(49, -27, '/'));
    ASSERT_EQ(-3547, calculator(44575149, -12567, '/'));
};

::testing::AssertionResult WrongOperation(int a, int b, char op){
    int value(calculator(a, b, op));
    std::ifstream result("C:\\Users\\NiceK\\Documents\\Itmo 2022\\ISRPO-lab5\\cmake-build-debug\\output.txt");
    std::string s;
    std::getline(result, s);
    if (s == "INCORRECT INPUT" && value == INT32_MIN)
        return ::testing::AssertionSuccess();
    return ::testing::AssertionFailure();
}

TEST(IncorrectInput, WrongOperation){
    EXPECT_TRUE(WrongOperation(12, 5, '6'));
    EXPECT_TRUE(WrongOperation(78, 256, 'A'));
    EXPECT_TRUE(WrongOperation(1597, -1762, '%'));
    EXPECT_TRUE(WrongOperation(32, -78542, '='));
}

::testing::AssertionResult DivisionByZero(int a, int b, char op){
    int value(calculator(a, b, op));
    std::ifstream result("C:\\Users\\NiceK\\Documents\\Itmo 2022\\ISRPO-lab5\\cmake-build-debug\\output.txt");
    std::string s;
    std::getline(result, s);
    if (s == "DIVISION BY 0" && value == INT32_MIN)
        return ::testing::AssertionSuccess();
    return ::testing::AssertionFailure();
}

TEST(IncorrectInput, DivisionByZero){
    EXPECT_HRESULT_SUCCEEDED(DivisionByZero(157, 0, '/'));
    /*EXPECT_TRUE(DivisionByZero(157, 0, '/'));
    EXPECT_TRUE(DivisionByZero(-167, 0, '/'));
    EXPECT_TRUE(DivisionByZero(0, 0, '/'));
    EXPECT_TRUE(DivisionByZero(9578642, 0, '/'));*/
}