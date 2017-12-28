#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stdlib.h>

void *allocate_memory(size_t byte_count, int generation_number);
void free_generation(int generation_number);
void free_all_generations();
void free_memory_manager();

#endif // MEMORY_MANAGER_H

