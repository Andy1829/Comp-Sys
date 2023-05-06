// This file is based on part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: Mult.asm

// Multiplies R1 and R2 and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)


// Repurposing Abs.asm code to convert RAM[1] to +ve

// If R1 < 0, return (-R1); otherwise return (R1);
    @R1
    // Places value at R1 into D
    D = M
    
// If condition is true (D is greater than 0)
    @IF_PTV
    D;JGT

    // Subtracting twice; i.e Converting to +ve
    @R1
    D = D - M
    D = D - M

(IF_PTV)
    @temp           // Stores absolute value of RAM[1] to use as an iterator
    M = D

// --------------------------------------------------------------------------------------
// We now need to create a while loop (while iterator < @temp)
// For each RAM[1], we add a copy of RAM[2] => RAM[1] * RAM{2}
    @temp_sum
    M = 0

(LOOP)
    @temp
    M = M - 1       // If we have not yet broken the loop, iterate downwards 
    D = M           // Sets D to current iterator

    @END            // Selects required jump line
    D;JLT       // Breaks loop if M < 0

// Code Block; adds RAM[2] repeatedly, RAM[1] times. Collects value into @temp_sum
    @R2
    D = M       // Grabs val of RAM[2] into D

    @temp_sum
    M = M + D

    @LOOP
    0;JMP       // Jumps unconditionally; repeats UNTIL loop is broken [refer to after @END]

(END)

// ----------------------------------------------------------------------------------------
// If statement to check if RAM[1] was initially negative
    @R1
    D = M           // Sets D = RAM[1]

// If condition is true (D is greater than 0)
    @IF_TRUE_NGT
    D;JGT           // Jumps if D > 0

    @temp_sum
    D = M           // Places temp_sum into D

    // Inverts 
    D = !D
    D = D + 1

    @temp_sum
    M = D


(IF_TRUE_NGT)


// ---------------------------
// Places saved data into correct location
    @temp_sum
    D = M

    @R0
    M = D

    @END
    0;JMP
