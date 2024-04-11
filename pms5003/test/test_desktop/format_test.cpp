#include <unity.h>
#include <local.hpp>

void test_hi()
{
    std::vector<std::string> result = getInfo(45, 10, 56);
    // TEST_ASSERT_NOT_EMPTY(result);

    for (std::string str : result)
    {
        std:printf(str.c_str());
    }
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_hi);
    UNITY_END();
}