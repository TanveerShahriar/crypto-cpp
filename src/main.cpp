#include "../include/Blockchain.h"

int main() {
    Blockchain my_blockchain;
    my_blockchain.add_block("First");
    my_blockchain.add_block("Second");
    my_blockchain.add_block("Third");

    my_blockchain.print_blockchain();

    return 0;
}