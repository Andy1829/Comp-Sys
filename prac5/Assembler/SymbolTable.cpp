#include "SymbolTable.h"

#include <string>

/**
 * Symbol Table constructor
 */
SymbolTable::SymbolTable() {
    table = {
        {"R0", 0},
        {"R1", 1},
        {"R2", 2},
        {"R3", 3},
        {"R4", 4},
        {"R5", 5},
        {"R6", 6},
        {"R7", 7},
        {"R8", 8},
        {"R9", 9},
        {"R10", 10},
        {"R11", 11},
        {"R12", 12},
        {"R13", 13},
        {"R14", 14},
        {"R15", 15},
        
        {"SP", 0},
        {"LCL", 1},
        {"ARG", 2},
        {"THIS", 3},
        {"THAT", 4},
        
        {"SCREEN", 16384},
        {"KBD", 24576}
    };
}

/**
 * Symbol Table destructor
 */
SymbolTable::~SymbolTable() {

}

/**
 * Adds a symbol to the symbol table
 * @param symbol The name of the symbol
 * @param value The address for the symbol
 */
void SymbolTable::addSymbol(string symbol, uint16_t value) {
    table.insert(pair<string, int> (symbol, value));

}

/**
 * Gets a symbol from the symbol table
 * @param symbol The name of the symbol
 * @return The address for the symbol or -1 if the symbol isn't in the table
 */
int SymbolTable::getSymbol(string symbol) {
    if (table.find(symbol) != table.end()) {
        return table.find(symbol)->second;

    } else {
        return -1;
    }
}