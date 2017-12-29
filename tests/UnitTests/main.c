#include <stdio.h>
#include <memory_manager_test.h>
#include <CUnit/Basic.h>

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main(void)
{
    CU_pSuite mem_manager_suite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    mem_manager_suite = CU_add_suite("Memory manager test suite", init_suite, clean_suite);
    if (!mem_manager_suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (!CU_add_test(mem_manager_suite, "allocation_test", allocation_test) ||
            !CU_add_test(mem_manager_suite, "free_generation_usual_test", free_generation_usual_test) ||
            !CU_add_test(mem_manager_suite, "free_generation_zero_test", free_generation_zero_test) ||
            !CU_add_test(mem_manager_suite, "free_all_generations_usual_test", free_all_generations_usual_test) ||
            !CU_add_test(mem_manager_suite, "free_all_generations_zero_test", free_all_generations_zero_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");
    /*
    // Run all tests using the automated interface
    CU_automated_run_tests();
    CU_list_tests_to_file();

    // Run all tests using the console interface
    CU_console_run_tests();
    */
    /* Clean up registry and return */
    CU_cleanup_registry();
    return CU_get_error();
}

