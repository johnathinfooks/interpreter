#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "value.h"
#include "vm.h"

int main(int argc, const char* argv[])
{
    Chunk chunk;
    initChunk(&chunk);


    initVM();



    // TODO: documentation for this would be helpful
    interpret(&chunk);



    freeVM();


    freeChunk(&chunk);


    return 0;
}
