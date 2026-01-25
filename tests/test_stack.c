#include "unity.h"
#include "stack.h"

void setUp(void){}
void tearDown(void){}

void test_new_stack_creation(void)
{
    Stack st = new_stack();
    TEST_ASSERT_NULL(st);
}

void test_is_empty_stack(void)
{
    Stack st = new_stack();
    TEST_ASSERT_TRUE(is_empty_stack(st));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_new_stack_creation);
    RUN_TEST(test_is_empty_stack);

    return UNITY_END();
}