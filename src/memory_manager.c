#include <stdlib.h>
#include <sys/queue.h>
#include <stdio.h>
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
    static struct memory_list list = { NULL };

    return &list;
}

void *allocate_memory(size_t byte_count, int generation_number)
{
    struct memory_list *list = get_memory_list();

    void *allocated_memory = malloc(byte_count);
    struct mem_entry *entry = malloc(sizeof(struct mem_entry));
    if (!allocated_memory || !entry)
    {
        printf("\nPANIC!!! MEMORY ALLOCTION FAILED\n");                 // panic!!!
        exit(1);
    }

    entry->allocated_memory = allocated_memory;
    entry->generation_number = generation_number;
    LIST_INSERT_HEAD(list, entry, pointers);

    return allocated_memory;
}

int free_generation(int generation_number)
{
    struct memory_list *list = get_memory_list();

    int freed_mem_regions = 0;
    struct mem_entry *entry;
    struct mem_entry *entry_to_free = NULL;
    LIST_FOREACH(entry, list, pointers)
    {
        if (entry->generation_number == generation_number)
        {
            if (entry_to_free)
            {
                free(entry_to_free); // have to free entry only on next iteration to not crash LIST_FOREACH work
                entry_to_free = NULL;
            }

            LIST_REMOVE(entry, pointers);
            free(entry->allocated_memory);
            freed_mem_regions++;

            entry_to_free = entry;
        }
    }

    if (entry_to_free)
    {
        free(entry_to_free);
        entry_to_free = NULL;
    }

    return freed_mem_regions;
}

int free_all_generations()
{
    struct memory_list *list = get_memory_list();

    int freed_mem_regions = 0;
    struct mem_entry *entry;

    while (!LIST_EMPTY(list))
    {
        entry = LIST_FIRST(list);
        LIST_REMOVE(entry, pointers);
        free(entry->allocated_memory);
        free(entry);
        freed_mem_regions++;
    }

    return freed_mem_regions;
}
