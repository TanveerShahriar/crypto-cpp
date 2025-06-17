#ifndef BLOCK_H
#define BLOCK_H

#include <ctime>
#include <string>
#include <openssl/sha.h>

using namespace std;

class Block {
public:
    string data;
    time_t timestamp;
    string hash;
    string previous_hash;
    Block* next = nullptr;

    Block(string data, string previous_hash);

private:
    string calculate_hash();
};

#endif