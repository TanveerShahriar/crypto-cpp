#include <ctime>
#include <iostream>
#include <openssl/sha.h>
#include <string>

using namespace std;

class Block {

public:
    string data;
    time_t timestamp;
    string hash;
    string previous_hash;
    Block* next = nullptr;

    Block(string data, string previous_hash) {
        this->data = data;
        this->timestamp = time(0);
        this->previous_hash = previous_hash;
        this->hash = calculate_hash();
    }

private:
    string calculate_hash() {
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
};

class Blockchain {

public:
    Block *head;

    Blockchain() {
        head = new Block("Genesis Block", "0");
    }

    void add_block(string data) {
        Block* new_block = new Block(data, head->hash);
        new_block->next = head;
        head = new_block;
    }

    void print_blockchain() {
        Block* current = head;
        while (current != nullptr) {
            cout << "Block Data: " << current->data << endl;
            cout << "Timestamp: " << current->timestamp << endl;

            struct tm *timeinfo = localtime(&current->timestamp);  // Convert to local time

            std::cout << "Converted time: " 
                << (timeinfo->tm_year + 1900) << "-"  
                << (timeinfo->tm_mon + 1) << "-"    
                << timeinfo->tm_mday << " "         
                << timeinfo->tm_hour << ":"          
                << timeinfo->tm_min << ":"          
                << timeinfo->tm_sec << std::endl; 

            cout << "Hash: " << current->hash << endl;
            cout << "Previous Hash: " << current->previous_hash << endl;
            cout << "-----------------------------" << endl;
            current = current->next;
        }
    }
};

int main() {
    Blockchain my_blockchain;
    my_blockchain.add_block("First");
    my_blockchain.add_block("Second");
    my_blockchain.add_block("Third");

    my_blockchain.print_blockchain();

    return 0;
}