#include <unity.h>
#include <local.hpp>

void test_hi()
{
    std::vector<std::string> result = getInfo(45, 10, 56);
    // TEST_ASSERT_NOT_EMPTY(result);

    for (std::string str : result)
    {
    std:
        printf(str.c_str());
    }
}

void test_state()
{
    state actual = calcState(45, 49, 56);
    TEST_ASSERT_EQUAL(GOOD, actual);

    actual = calcState(45, 99, 56);
    TEST_ASSERT_EQUAL(NORMAL, actual);

    actual = calcState(45, 100, 56);
    TEST_ASSERT_EQUAL(CRITICAL, actual);
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();
    RUN_TEST(test_hi);
    RUN_TEST(test_state);
    UNITY_END();
}