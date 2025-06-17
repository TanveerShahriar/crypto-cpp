#include "../include/Block.h"
#include <ctime>
#include <openssl/sha.h>

Block::Block(string data, string previous_hash) {
    this->data = data;
    this->timestamp = time(0);
    this->previous_hash = previous_hash;
    this->hash = calculate_hash();
}

string Block::calculate_hash() {
    string to_hash = data + previous_hash;
    unsigned char hash_bytes[SHA256_DIGEST_LENGTH];

    SHA256(reinterpret_cast<const unsigned char*>(to_hash.c_str()), to_hash.size(), hash_bytes);

    char hex_str[SHA256_DIGEST_LENGTH * 2 + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(hex_str + (i * 2), "%02x", hash_bytes[i]);
    }
    hex_str[SHA256_DIGEST_LENGTH * 2] = '\0';

    return string(hex_str);
}