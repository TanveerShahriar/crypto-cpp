#include "../include/Blockchain.h"
#include <iostream>
#include <ctime>

Blockchain::Blockchain() {
    head = new Block("Genesis Block", "0");
}

void Blockchain::add_block(string data) {
    Block* new_block = new Block(data, head->hash);
    new_block->next = head;
    head = new_block;
}

void Blockchain::print_blockchain() {
    Block* current = head;
    while (current != nullptr) {
        cout << "Block Data: " << current->data << endl;
        cout << "Timestamp: " << current->timestamp << endl;

        struct tm *timeinfo = localtime(&current->timestamp); 

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