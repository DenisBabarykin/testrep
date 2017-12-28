#include <stdlib.h>
#include <sys/queue.h>
#include "memory_manager.h"

struct mem_entry
{
    void *allocated_memory;
    int generation_number;
    LIST_ENTRY(mem_entry) pointers;
};

LIST_HEAD(memory_list, mem_entry);

struct memory_list *get_memory_list()
{
    static struct memory_list list = (struct memory_list) { NULL };

    return &list;
}

void *allocate_memory(size_t byte_count, int generation_number)
{

}

void free_generation(int generation_number)
{

}
