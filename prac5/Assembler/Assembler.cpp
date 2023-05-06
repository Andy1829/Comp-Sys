#include "Assembler.h"
#include "SymbolTable.h"

#include <string>

using namespace std;

/**
 * Assembler constructor
 */
Assembler::Assembler() {
    // Your code here
}

/**
 * Assembler destructor
 */
Assembler::~Assembler() {
    // Your code here
}

        /*
        TESTING:
        Compile your code by using: g++ ./*.cpp -o Assembler
        And run it: ./Assembler ./Assembler100.asm
        The translated result will be printed in your stdout terminal.
        */


/**
 * Assembler first pass; populates symbol table with label locations.
 * @param instructions An array of the assembly language instructions.
 * @param symbolTable The symbol table to populate.
 */
void Assembler::buildSymbolTable(SymbolTable* symbolTable, string instructions[], int numOfInst) {
    // Your code here
    // symbolTable->addSymbol();
}

/**
 * Assembler second pass; Translates a set of instructions to machine code.
 * @param instructions An array of the assembly language instructions to be converted to machine code.
 * @param symbolTable The symbol table to reference/update.
 * @return A string containing the generated machine code as lines of 16-bit binary instructions.
 */
string Assembler::generateMachineCode(SymbolTable* symbolTable, string instructions[], int numOfInst) {
    // Your code here
    return "";
}

/**
 * Parses the type of the provided instruction
 * @param instruction The assembly language representation of an instruction.
 * @return The type of the instruction (A_INSTRUCTION, C_INSTRUCTION, L_INSTRUCTION, NULL)
 */
Assembler::InstructionType Assembler::parseInstructionType(string instruction) {                // DONE
    if (instruction.find("(") != string::npos) {
        return L_INSTRUCTION;
    }

    if (instruction.find("@") != string::npos) {
        return A_INSTRUCTION;
    }

    if (instruction.find("=") != string::npos || instruction.find(";") != string::npos ) {
        return C_INSTRUCTION;
    }

    return NULL_INSTRUCTION;
}

/**
 * Parses the destination of the provided C-instruction
 * @param instruction The assembly language representation of a C-instruction.
 * @return The destination of the instruction (A, D, M, AM, AD, MD, AMD, NULL)
 */
Assembler::InstructionDest Assembler::parseInstructionDest(string instruction) {                // DONE
    if (instruction.find("AMD=") != string::npos) {
        return AMD;
    } else if (instruction.find("AM=") != string::npos) {
        return AM;
    } else if (instruction.find("AD=") != string::npos) {
        return AD;
    } else if (instruction.find("MD=") != string::npos) {
        return MD;
    } else if (instruction.find("A=") != string::npos) {
        return A;
    } else if (instruction.find("M=") != string::npos) {
        return M;
    } else if (instruction.find("D=") != string::npos) {
        return D;
    } else {
        return NULL_DEST;
    }
}

/**
 * Parses the jump condition of the provided C-instruction
 * @param instruction The assembly language representation of a C-instruction.
 * @return The jump condition for the instruction (JLT, JGT, JEQ, JLE, JGE, JNE, JMP, NULL)
 */
Assembler::InstructionJump Assembler::parseInstructionJump(string instruction) {                // DONE
    // Your code here:
    // for example if "JLT" appear at the comp field return enum label JLT
    if (instruction.find("JGT") != string::npos) {
        return JGT;
    }

    if (instruction.find("JEQ") != string::npos) {
        return JEQ;
    }
    
    if (instruction.find("JGE") != string::npos) {
        return JGE;
    }
    
    if (instruction.find("JLT") != string::npos) {
        return JLT;
    }
    
    if (instruction.find("JNE") != string::npos) {
        return JNE;
    }

    if (instruction.find("JLE") != string::npos) {
        return JLE;
    }

    if (instruction.find("JMP") != string::npos) {
        return JMP;
    }

    // Otherwise, return NullJump
    return NULL_JUMP;
}

/**
 * Parses the computation/op-code of the provided C-instruction
 * @param instruction The assembly language representation of a C-instruction.
 * @return The computation/op-code of the instruction (CONST_0, ... ,D_ADD_A , ... , NULL)
 */
Assembler::InstructionComp Assembler::parseInstructionComp(string instruction) {
    // Your code here:
    // for example if "0" appear at the comp field return CONST_0
    if (instruction.find("0") != string::npos) {
        return CONST_0;
    }
    return NULL_COMP;
}

/**
 * Parses the symbol of the provided A/L-instruction
 * @param instruction The assembly language representation of a A/L-instruction.
 * @return A string containing either a label name (L-instruction),
 *         a variable name (A-instruction), or a constant integer value (A-instruction)
 */
string Assembler::parseSymbol(string instruction) {
    return "";
}

/**
 * Generates the binary bits of the dest part of a C-instruction
 * @param dest The destination of the instruction
 * @return A string containing the 3 binary dest bits that correspond to the given dest value.
 */
string Assembler::translateDest(InstructionDest dest) {                                         // DONE 
    switch (dest) {
        case 0:                 // A
            return "100";

        case 1:                 // D
            return "010";

        case 2:                 // M
            return "001";       

        case 3:                 // AM
            return "101";

        case 4:                 // AD
            return "110";

        case 5:                 // MD
            return "011";

        case 6:                 // AMD
            return "111";

        default:                // NULL
            return "000";
    }
}

/**
 * Generates the binary bits of the jump part of a C-instruction
 * @param jump The jump condition for the instruction
 * @return A string containing the 3 binary jump bits that correspond to the given jump value.
 */
string Assembler::translateJump(InstructionJump jump) {                                         // DONE
    switch (jump) {
        case 0:                 // JLT
            return "100";

        case 1:                 // JGT
            return "001";

        case 2:                 // JEQ
            return "010";       

        case 3:                 // JLE
            return "110";

        case 4:                 // JGE
            return "011";

        case 5:                 // JNE
            return "101";

        case 6:                 // JMP
            return "111";

        default:                // NULL
            return "000";
    }
}

/**
 * Generates the binary bits of the computation/op-code part of a C-instruction
 * @param comp The computation/op-code for the instruction
 * @return A string containing the 7 binary computation/op-code bits that correspond to the given comp value.
 */
string Assembler::translateComp(InstructionComp comp) {
    
    
    switch (comp) {
        case 0:                 // CONST_0
            return "101010";

        case 1:                 // CONST_1
            return "111111";

        case 2:                 // CONST_NEG_1
            return "111010";       

        case 3:                 // D 
            return "001100";

        case 4:                 // A // M
            return "110000";

        case 5:                 // -D 
            return "001111";

        case 6:                 // AMD
            return "111";

        default:                // NULL
            return "000";
    }
    return "0000000";
}

/**
 * Generates the binary bits for an A-instruction, parsing the value, or looking up the symbol name.
 * @param symbol A string containing either a label name, a variable name, or a constant integer value
 * @param symbolTable The symbol table for looking up label/variable names
 * @return A string containing the 15 binary bits that correspond to the given sybmol.
 */
string Assembler::translateSymbol(string symbol, SymbolTable* symbolTable) {
    // Your code here:
    return "0000000000000000";
}
