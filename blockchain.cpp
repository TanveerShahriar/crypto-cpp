#include <ctime>
#include <iostream>
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
        this->hash = calculate_hash();
        this->previous_hash = previous_hash;
    }

    string calculate_hash() {
        return "hash";
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