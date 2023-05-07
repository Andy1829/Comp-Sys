#include "Assembler.h"
#include "SymbolTable.h"

#include <string>
#include <bitset>

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
    string output = "";

    for (int i = 0; i < numOfInst; i++) {
        InstructionType type = parseInstructionType(instructions[i]);
        if (type == 0) {            // A Instruction
            output += translateSymbol(parseSymbol(instructions[i]), symbolTable);
            output += "\n";
        } else if (type == 1) {
            output += "111";
            output += translateComp(parseInstructionComp(instructions[i]));
            output += translateDest(parseInstructionDest(instructions[i]));
            output += translateJump(parseInstructionJump(instructions[i]));
            output += "\n";

        }
    }

    return output;
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

    return C_INSTRUCTION;
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
Assembler::InstructionComp Assembler::parseInstructionComp(string instruction) {                // DONE 
    // Your code here:
    // for example if "0" appear at the comp field return CONST_0
    if (instruction.find("!A") != string::npos) {
        return NOT_A;
    } else
    if (instruction.find("!M") != string::npos) {
        return NOT_M;
    } else
    if (instruction.find("!D") != string::npos) {
        return NOT_D;
    } else
    if (instruction.find("-A") != string::npos) {
        return NEG_A;
    } else
    if (instruction.find("-M") != string::npos) {
        return NEG_M;
    } else
    if (instruction.find("-D") != string::npos) {
        return NEG_D;
    } else
    if (instruction.find("A+1") != string::npos) {
        return A_ADD_1;
    } else
    if (instruction.find("M+1") != string::npos) {
        return M_ADD_1;
    } else
    if (instruction.find("D+1") != string::npos) {
        return D_ADD_1;
    } else
    if (instruction.find("A-1") != string::npos) {
        return A_SUB_1;
    } else
    if (instruction.find("M-D") != string::npos) {
        return M_SUB_D;
    } else
    if (instruction.find("D&A") != string::npos) {
        return D_AND_A;
    } else
    if (instruction.find("D&M") != string::npos) {
        return D_AND_M;
    } else
    if (instruction.find("D|A") != string::npos) {
        return D_OR_A;
    } else

    // DO THE PREVIOUS CHECKS FIRST, these must be more precise.
    if (instruction.find("0") != string::npos) {
        return CONST_0;
    } else
    if (instruction.find("-1") != string::npos) {
        return CONST_NEG_1;
    } else
    if (instruction.find("1") != string::npos) {
        return CONST_1;
    } else
    if (instruction.find("=A") != string::npos || instruction.find("A;") != string::npos) {
        return VAL_A;
    } else
    if (instruction.find("=M") != string::npos || instruction.find("M;") != string::npos) {
        return VAL_M;
    } else
    if (instruction.find("=D") != string::npos || instruction.find("D;") != string::npos) {
        return VAL_D;
    } else
    if (instruction[0] == 'A') {
        return VAL_A;
    } else
    if (instruction[0] == 'M') {
        return VAL_M;
    } else
    if (instruction[0] == 'D') {
        return VAL_D;
    } 

    return NULL_COMP;
}

/**
 * Parses the symbol of the provided A/L-instruction
 * @param instruction The assembly language representation of a A/L-instruction.
 * @return A string containing either a label name (L-instruction),
 *         a variable name (A-instruction), or a constant integer value (A-instruction)
 */
string Assembler::parseSymbol(string instruction) {                                         // DONE; PROBS
    InstructionType type = parseInstructionType(instruction);
    string result = "";

    if (type == 0) {                    // A Instruction
        for (int i = 0; i < instruction.size(); i++) {
            if (instruction[i] != '@') {
                result += instruction[i];
            }
        }
        return result;

    } else if (type == 3) {             // Null Instruction
        return "";
    } else if (type == 2) {
        int startIterator = instruction.find("(");
        int endIterator = instruction.find(")");
        
        string symbolName;
        symbolName.append(startIterator, endIterator);
        return symbolName;
    }
    
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
string Assembler::translateComp(InstructionComp comp) {                                         // DONE
    switch (comp) {
        case 0:                 // CONST_0
            return "0101010";
        case 1:                 // CONST_1
            return "0111111";
        case 2:                 // CONST_NEG_1
            return "0111010";       
        case 3:                 // A
            return "0110000";
        case 4:                 // M
            return "1110000";
        case 5:                 // D
            return "0001100";
        case 6:                 // !A
            return "0110001";
        case 7:                 // !M
            return "1110001";
        case 8:                 // !D
            return "0001101";
        case 9:                 // -A
            return "0110011";       
        case 10:                // -M
            return "1110011";
        case 11:                // -D
            return "0001111";
        case 12:                // A + 1
            return "0110111";
        case 13:                // M + 1
            return "1110111";   
        case 14:                // D + 1
            return "0011111";
        case 15:                 // A - 1
            return "0110010";
        case 16:                 // M - 1
            return "1110010";       
        case 17:                 // D - 1
            return "0001110";
        case 18:                 // D + A
            return "0000010";
        case 19:                 // D + M
            return "1000010";
        case 20:                 // D - A
            return "0010011";
        case 21:                // D - M
            return "1010011";   
        case 22:                // A - D
            return "0000111";
        case 23:                 // M - D
            return "1000111";
        case 24:                 // D & A
            return "0000000";       
        case 25:                 // D & M
            return "1000000";
        case 26:                 // D | A
            return "0010101";
        case 27:                 // D | M
            return "1010101";
        
        default:                // NULL
            return "0000000";
    }
}

/**
 * Generates the binary bits for an A-instruction, parsing the value, or looking up the symbol name.
 * @param symbol A string containing either a label name, a variable name, or a constant integer value
 * @param symbolTable The symbol table for looking up label/variable names
 * @return A string containing the 15 binary bits that correspond to the given sybmol.
 */
string Assembler::translateSymbol(string symbol, SymbolTable* symbolTable) {            // DONE; PROBS
    // For A instruction:
    int decimal = stoi(symbol);
    string binary = bitset<16>(decimal).to_string();

    // string binary = bitset<16> (symbolTable->getSymbol(symbol)).to_string();
    return binary;  

}
