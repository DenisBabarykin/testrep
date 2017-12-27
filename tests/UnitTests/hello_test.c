#include <CUnit/CUnit.h>
#include "../../src/hello.h"

void test_true()
{
    CU_ASSERT_EQUAL(TestReturnFive(), 5);
}

void test_false()
{
    CU_ASSERT_NOT_EQUAL(TestReturnFive(), 6);
}
