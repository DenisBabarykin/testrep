#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stdlib.h>

void *allocate_memory(size_t byte_count, int generation_number);
int free_generation(int generation_number);
int free_all_generations();

#endif // MEMORY_MANAGER_H

