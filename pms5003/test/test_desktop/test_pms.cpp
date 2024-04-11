#include <unity.h>
#include <pms.hpp>

void test_hi() {
        TEST_ASSERT_EQUAL_STRING("333", sayHi());
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_hi);
    UNITY_END();
}
