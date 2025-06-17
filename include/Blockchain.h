#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

class Blockchain {
public:
    Block* head;

    Blockchain();
    void add_block(string data);
    void print_blockchain();
};

#endif
