#ifndef PIPE_CHUNK_H
#define PIPE_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);

/**
 * @breif Writes chunk logic. Considers line number.
 * @param chunk Chunk to be written.
 * @param byte The OpCode byte; bytecode. What action is to be done.
 * @param lineNum The line number that the chunk logic lies on.
*/
void writeChunk(Chunk* chunk, uint8_t byte, int lineNum);
void freeChunk(Chunk* chunk);

int addConstantPool(Chunk* chunk, Value value);

#endif // PIPE_CHUNK_H
