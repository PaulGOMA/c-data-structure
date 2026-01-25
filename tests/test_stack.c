#include <stdlib.h>
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

void test_push_stack(void)
{
    Stack st = new_stack();
    int value = 10;
    st = push_stack(st, &value);

    TEST_ASSERT_FALSE(is_empty_stack(st));
    TEST_ASSERT_EQUAL_PTR(&value, (st->data));

    free(st);
}

void test_pop_stack(void)
{
    Stack st = new_stack();
    int value = 10;
    char *greeting = "hello";

    st = push_stack(st, &value);
    st = push_stack(st, greeting);

    st = pop_stack(st);

    TEST_ASSERT_EQUAL_PTR(&value, (st->data));

    free(st);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_new_stack_creation);
    RUN_TEST(test_is_empty_stack);
    RUN_TEST(test_push_stack);
    RUN_TEST(test_pop_stack);

    return UNITY_END();
}