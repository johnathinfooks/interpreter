#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[])
{
    Chunk chunk;
    initChunk(&chunk);


    initVM();


    int lineNum = 25;
    int x = addConstantPool(&chunk, 23);
    int y = addConstantPool(&chunk, 32.2);
    writeChunk(&chunk, OP_CONSTANT, lineNum);
    writeChunk(&chunk, x, lineNum);
    writeChunk(&chunk, OP_CONSTANT, lineNum);
    writeChunk(&chunk, y, lineNum);
    writeChunk(&chunk, OP_RETURN, lineNum);

    interpret(&chunk);
    disassembleChunk(&chunk, "testcase");



    freeVM();


    freeChunk(&chunk);


    return 0;
}
