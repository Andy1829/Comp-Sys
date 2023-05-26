#include <string>

#include "VMTranslator.h"

using namespace std;

/**
 * VMTranslator constructor
 */
VMTranslator::VMTranslator() {
    // Your code here
}

/**
 * VMTranslator destructor
 */
VMTranslator::~VMTranslator() {
    // Your code here
}

/** Generate Hack Assembly code for a VM push operation */
string VMTranslator::vm_push(string segment, int offset){           // DONE 
    string output;
    
    if (segment == "argument") {                    // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");

        output.append("@ARG\n");
        output.append("A=M+D\n");

        output.append("D=M\n");

    } else if (segment == "constant") {             // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=A\n");

    } else if (segment == "static") {               // DONE; CHECKED
        output.append("@");
        output.append((to_string(offset + 16)));
        output.append("\n");

        output.append("D=M\n");

    } else if (segment == "local") {                // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");
        
        output.append("@LCL\n");
        output.append("A=M+D\n");

        output.append("D=M\n");

    } else if (segment == "this") {                 // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");

        output.append("@THIS\n");
        output.append("A=M+D\n");

        output.append("D=M\n");

    } else if (segment == "that") {                 // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");

        output.append("@THAT\n");
        output.append("A=M+D\n");

        output.append("D=M\n");

    } else if (segment == "temp") {                 // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");
        
        output.append("@5\n");        
        output.append("A=A+D\n");
        
        output.append("D=M\n");

    } else if (segment == "pointer") {              // DONE; CHECKED
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");
        
        output.append("@3\n");        
        output.append("A=A+D\n");
        
        output.append("D=M\n");
    
    }

    output.append("@SP\n");                 // Iterates pointer upwards
    output.append("A=M\n");
    output.append("M=D\n");               // Sets value at pointer
    output.append("@SP\n");
    output.append("M=M+1\n");
    
    return output;
}

/** Generate Hack Assembly code for a VM pop operation */
string VMTranslator::vm_pop(string segment, int offset){    
    string output;
    
    if (segment == "static") {
        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset + 16));
        output.append("\n");

        output.append("M=D\n");
   
    } else {
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=A\n");

        if (segment == "argument") {
            output.append("@ARG\n");
            output.append("D=M+D\n");

        } else if (segment == "local") {
            output.append("@LCL\n");
            output.append("D=M+D\n");

        } else if (segment == "this") {
            output.append("@THIS\n");
            output.append("D=M+D\n");

        } else if (segment == "that") {
            output.append("@THAT\n");
            output.append("D=M+D\n");

        } else if (segment == "pointer") {
            output.append("@3\n");
            output.append("D=A+D\n");
            
        } else if (segment == "temp") {
            output.append("@5\n");
            output.append("D=A+D\n");

        }

        output.append("@R13\n");
        output.append("M=D\n");

        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=M\n");
        
        output.append("@R13\n");            
        output.append("A=M\n");
        output.append("M=D\n");


    }

    // if (segment == "argument") {                    // DONE
    //     output.append("@ARG\n");
    //     output.append("D=M\n");
        
    //     output.append("@R");
    //     output.append(to_string(offset));
    //     output.append("\n");
        
    //     output.append("D=D+A\n");

    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=D+M\n");
    //     output.append("A=D-M\n");
    //     output.append("M=D-A\n");
        
    // } else if (segment == "local") {                // DONE
    //     output.append("@LCL\n");
    //     output.append("D=M\n");
        
    //     output.append("@R");
    //     output.append(to_string(offset));
    //     output.append("\n");
        
    //     output.append("D=D+A\n");

    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=D+M\n");
    //     output.append("A=D-M\n");
    //     output.append("M=D-A\n");
        
    // } else if (segment == "static" ) {              // DONE; CHECKED
    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=M\n");

    //     output.append("@");
    //     output.append(to_string(offset + 16));
    //     output.append("\n");

    //     output.append("M=D\n");
   
    // } else if (segment == "pointer") {              // DONE
    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=M\n");

    //     output.append("@");
    //     output.append(to_string(offset));
    //     output.append("\n");

    //     output.append("M=D\n");
   
    // } else if (segment == "temp") {             // DONE (same functionality as pointer I think)
    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=M\n");

    //     output.append("@R");
    //     output.append(to_string(offset));
    //     output.append("\n");

    //     output.append("M=D\n");
        
    // } else if (segment == "this") {             // DONE
    //     output.append("@THIS\n");
    //     output.append("D=M\n");

    //     output.append("@");
    //     output.append(to_string(offset));
    //     output.append("\n");

    //     output.append("D=D+A\n");

    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=D+M\n");
    //     output.append("A=D-M\n");
    //     output.append("M=D-A\n");

    // } else if (segment == "that") {             // DONE
    //     output.append("@THAT\n");
    //     output.append("D=M\n");

    //     output.append("@");
    //     output.append(to_string(offset));
    //     output.append("\n");

    //     output.append("D=D+A\n");

    //     output.append("@SP\n");
    //     output.append("AM=M-1\n");
    //     output.append("D=D+M\n");
    //     output.append("A=D-M\n");
    //     output.append("M=D-A\n");

    // }
    return output;
}




/** Generate Hack Assembly code for a VM add operation */
string VMTranslator::vm_add(){
    return "";
}

/** Generate Hack Assembly code for a VM sub operation */
string VMTranslator::vm_sub(){
    return "";
}

/** Generate Hack Assembly code for a VM neg operation */
string VMTranslator::vm_neg(){                          // DONE
    string output;
    
    output.append("@SP\n");
    output.append("A=M-1\n");               // Selects topmost element
    output.append("M=-M\n");                // Negates
    
    return output;
}




/** Generate Hack Assembly code for a VM eq operation */
string VMTranslator::vm_eq(){
    return "";
}

/** Generate Hack Assembly code for a VM gt operation */
string VMTranslator::vm_gt(){
    return "";
}

/** Generate Hack Assembly code for a VM lt operation */
string VMTranslator::vm_lt(){
    return "";
}

/** Generate Hack Assembly code for a VM and operation */
string VMTranslator::vm_and(){
    string output;

    output.append("@SP\n");
    output.append("AM=M-1\n");              // Selects topmost element
    output.append("D=M\n");                 // Grabs value into D 

    output.append("@SP\n");
    output.append("A=M-1\n");               // Selects next element
    output.append("M=D&M\n");               // Replaces current element with bitwise AND  
    
    return output;
}

/** Generate Hack Assembly code for a VM or operation */
string VMTranslator::vm_or(){
    string output;

    output.append("@SP\n");
    output.append("AM=M-1\n");              // Selects topmost element
    output.append("D=M\n");                 // Grabs value into D 

    output.append("@SP\n");
    output.append("A=M-1\n");               // Selects next element
    output.append("M=D|M\n");               // Replaces current element with bitwise AND  
    
    return output;
}

/** Generate Hack Assembly code for a VM not operation */
string VMTranslator::vm_not(){
        string output;
    
    output.append("@SP\n");
    output.append("A=M-1\n");               // Selects topmost element
    output.append("M=!M\n");                // Inverts 
    
    return output;
}




/** Generate Hack Assembly code for a VM label operation */
string VMTranslator::vm_label(string label){
    // string output = "(" + label + ")";
    
    // return output;

    return "(" + label + ")";
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label){
    // string output;

    // output.append("@" + label + "\n");
    // output.append("0;JMP");
    
    // return output;

    return "@" + label + "\n0;JMP";
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label){
    // string output;
    
    // output.append("@SP\n");
    // output.append("AM=M-1\n");
    // output.append("D=M\n");             // Pops top element into D 

    // output.append("@" + label + "\n");
    // output.append("D;JNE");           // Jumps if D != 0
    
    // return output;

    return "@SP\nAM=M-1\nD=M\n@" + label + "\nD;JNE";
}




/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars){
    string output;

    output.append("(" + function_name + ")");
    for (int n = 0; n < n_vars; n++){
        output.append("\n@0");
        output.append("\nD=A");
        output.append("\n@SP");
        output.append("\nAm=M+1");
        output.append("\nA=A-1");
        output.append("\nM=D");
    }

    return output;
}

/** Generate Hack Assembly code for a VM call operation */
string VMTranslator::vm_call(string function_name, int n_args){
    string output;

    // Return address
    output.append("@endFunc\nD=A\n@SP\nAM=M+1\nA=A-1\nM=D\n");
    
    // Local
    output.append("@LCL\nD=M\n@SP\nAM=M+1\nA=A-1\nM=D\n");
    
    // Argument
    output.append("@ARG\nD=M\n@SP\nAM=M+1\nA=A-1\nM=D\n");

    // This
    output.append("@THIS\nD=M\n@SP\nAM=M+1\nA=A-1\nM=D\n");

    // That
    output.append("@THAT\nD=M\n@SP\nAM=M+1\nA=A-1\nM=D\n");


    // Argument
    output.append("@SP\nD=M\n@" + to_string(n_args + 5) + 
    "\nD=D-A\n@ARG\nM=D\n");

    // Argument
    output.append("@SP\nD=M\n@LCL\nM=D\n");
    output.append("@" + function_name + "\n0;JMP\n");

    // Closing label
    output.append("(endFunc)");

    return output;
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return(){
    string output;

    output.append("@LCL\n");
    output.append("D=M\n");
    output.append("@5\n");
    output.append("A=D-A\n");
    output.append("D=M\n");

    output.append("@R13\n");
    output.append("M=D\n");
    output.append("@SP\n");
    output.append("A=M-1\n");
    output.append("D=M\n");
    
    output.append("@ARG\n");
    output.append("A=M\n");
    output.append("M=D\n");
    output.append("D=A+1\n");
    output.append("@SP\n");
    output.append("M=D\n");
    
    output.append("@LCL\n");
    output.append("AM=M-1\n");
    output.append("D=M\n");
    output.append("@THAT\n");
    output.append("M=D\n");

    output.append("@LCL\n");
    output.append("AM=M-1\n");
    output.append("D=M\n");
    output.append("@THIS\n");
    output.append("M=D\n");

    output.append("@LCL\n");
    output.append("AM=M-1\n");
    output.append("D=M\n");
    output.append("@ARG\n");
    output.append("M=D\n");

    output.append("@LCL\n");
    output.append("A=M-1\n");
    output.append("D=M\n");
    output.append("@LCL\n");
    output.append("M=D\n");

    output.append("@R13\n");
    output.append("A=M\n");
    output.append("0;JMP");
    
    return output;
}