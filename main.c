#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[])
{
    Chunk chunk;

    initChunk(&chunk);

    for (int i = 2; i < 20; i++) {
        writeChunk(&chunk, OP_CONSTANT);
        writeChunk(&chunk, addConstantPool(&chunk, i * i));
    }

    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "test");
    freeChunk(&chunk);

    return 0;
}
