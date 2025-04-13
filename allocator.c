#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PR_LENGTH 10

int MEMORY_SIZE = 128;

typedef struct Memblock {
    int start;
    int end;
    int size;
    int allocated;
    char process[PR_LENGTH];
    struct Memblock *next;
} Memblock;


Memblock* create_block(int start, int size, int allocated, const char* process) {
    Memblock* block = (Memblock*)malloc(sizeof(Memblock));
    block->start = start;
    block->end = start + size - 1;
    block->size = size;
    block->allocated = allocated;
    strncpy(block->process, process, PR_LENGTH);
    block->next = NULL;
    return block;
}

Memblock *memory = NULL;

void initialize_memory(){
    memory = create_block(0, MEMORY_SIZE, 0, "FREE");
}

void release_memory(process){
    Memblock* curr = memory;
    while (strcmp(memory -> process, process) != 0){
        
    }

}

int main(int argc, char*argv[]) {

    //0B < Memory size < 1MB
    MEMORY_SIZE = atoi(argv[1]);
    if (MEMORY_SIZE < 0 || MEMORY_SIZE > 1048576){
        printf("\nInvalid memory length, defaulting to 128 bytes");
        MEMORY_SIZE = 128;
    }

    initialize_memory();

    char command[20], process[PR_LENGTH], strategy[2];
    int size;

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "RQ") == 0) {
            scanf("%s %d %s", process, &size, strategy);
            allocate_memory(process, size, strategy);
        } else if (strcmp(command, "RL") == 0) {
            scanf("%s", process);
            release_memory(process);
        } else if (strcmp(command, "C") == 0) {
            compact_memory();
        } else if (strcmp(command, "STAT") == 0) {
            print_status();
        } else if (strcmp(command, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}