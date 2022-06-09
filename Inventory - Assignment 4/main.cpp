#include "parser.h"

int main() {
    Parser parser;
    parser.parseInventory("data4movies.txt");
    parser.parseCustomers("data4customers.txt");
    parser.parseTransactions("data4commands.txt");
    return 0;
}