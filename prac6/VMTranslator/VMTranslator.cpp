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
    
    if (segment == "argument") {                    // DONE
        output.append("@ARG\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("A=D+A\n");
        output.append("D=M\n");

    } else if (segment == "local") {                // DONE
        output.append("@LCL\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("A=D+A\n");
        output.append("D=M\n");

    } else if (segment == "static") {               // DONE, but have to figure out how to translate variable NAME into an integer...
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=M\n");

    } else if (segment == "constant") {             // DONE
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=A\n");

    } else if (segment == "this") {                 // DONE
        output.append("@THIS\n");
        output.append("D=M\n");
        
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("A=D+A\n");
        output.append("D=M\n");

    } else if (segment == "that") {                 // DONE
        output.append("@THAT\n");
        output.append("D=M\n");
        
        output.append("@");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("A=D+A\n");
        output.append("D=M\n");

    } else if (segment == "temp") {                 // DONE
        output.append("@R");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=M\n");

    } else if (segment == "pointer") {              // Same functionality (?)
        output.append("@R");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=M\n");
    
    }

    output.append("@SP\n");                 // Iterates pointer upwards
    output.append("AM=M+1\n");
    output.append("A=A-1\n");               // Sets value at pointer
    output.append("M=D\n");
    
    return output;
}

/** Generate Hack Assembly code for a VM pop operation */
string VMTranslator::vm_pop(string segment, int offset){    
    string output;
    
    if (segment == "argument") {                    // DONE
        output.append("@ARG\n");
        output.append("D=M\n");
        
        output.append("@R");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=D+A\n");

        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=D+M\n");
        output.append("A=D-M\n");
        output.append("M=D-A\n");
        
    } else if (segment == "local") {                // DONE
        output.append("@LCL\n");
        output.append("D=M\n");
        
        output.append("@R");
        output.append(to_string(offset));
        output.append("\n");
        
        output.append("D=D+A\n");

        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=D+M\n");
        output.append("A=D-M\n");
        output.append("M=D-A\n");
        
    } else if (segment == "static" ) {              // DONE
        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("M=D\n");
   
    } else if (segment == "pointer") {              // DONE
        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("M=D\n");
   
    } else if (segment == "temp") {             // DONE (same functionality as pointer I think)
        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=M\n");

        output.append("@R");
        output.append(to_string(offset));
        output.append("\n");

        output.append("M=D\n");
        
    } else if (segment == "this") {             // DONE
        output.append("@THIS\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=D+A\n");

        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=D+M\n");
        output.append("A=D-M\n");
        output.append("M=D-A\n");

    } else if (segment == "that") {             // DONE
        output.append("@THAT\n");
        output.append("D=M\n");

        output.append("@");
        output.append(to_string(offset));
        output.append("\n");

        output.append("D=D+A\n");

        output.append("@SP\n");
        output.append("AM=M-1\n");
        output.append("D=D+M\n");
        output.append("A=D-M\n");
        output.append("M=D-A\n");

    }
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
    return "";
}

/** Generate Hack Assembly code for a VM goto operation */
string VMTranslator::vm_goto(string label){
    return "";
}

/** Generate Hack Assembly code for a VM if-goto operation */
string VMTranslator::vm_if(string label){
    return "";
}




/** Generate Hack Assembly code for a VM function operation */
string VMTranslator::vm_function(string function_name, int n_vars){
    return "";
}

/** Generate Hack Assembly code for a VM call operation */
string VMTranslator::vm_call(string function_name, int n_args){
    return "";
}

/** Generate Hack Assembly code for a VM return operation */
string VMTranslator::vm_return(){
    return "";
}