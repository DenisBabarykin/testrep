#include <CUnit/CUnit.h>
#include "../../src/memory_manager.h"

void allocation_test()
{
    void *last_mem = allocate_memory(100, 0);

    CU_ASSERT_NOT_EQUAL(last_mem, NULL);
    free_all_generations();
}

void free_generation_usual_test()
{
    int count0 = 100;
    int count1 = 50;
    for (int i = 0; i < count0; i++)
    {
        void *mem = allocate_memory(100, 0);
    }

    for (int i = 0; i < count1; i++)
    {
        void *mem = allocate_memory(100, 1);
    }


    int freed_generation_zero_count = free_generation(0);
    CU_ASSERT_EQUAL(freed_generation_zero_count, count0);

    int freed_generation_one_count = free_generation(1);
    CU_ASSERT_EQUAL(freed_generation_one_count, count1);
}

void free_generation_zero_test()
{
    int freed_generation_zero_count = free_generation(0);
    CU_ASSERT_EQUAL(freed_generation_zero_count, 0);

    int freed_generation_one_count = free_generation(1);
    CU_ASSERT_EQUAL(freed_generation_one_count, 0);
}

void free_all_generations_usual_test()
{
    int count0 = 100;
    int count1 = 50;
    for (int i = 0; i < count0; i++)
    {
        void *mem = allocate_memory(100, 0);
    }

    for (int i = 0; i < count1; i++)
    {
        void *mem = allocate_memory(100, 1);
    }


    int freed_mem_regions_count = free_all_generations();
    CU_ASSERT_EQUAL(freed_mem_regions_count, count0 + count1);
}

void free_all_generations_zero_test()
{
    int freed_mem_regions_count = free_all_generations();
    CU_ASSERT_EQUAL(freed_mem_regions_count, 0);
}
