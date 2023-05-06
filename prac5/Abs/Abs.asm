// Calculates the absolute value of R1 and stores the result in R0.
// (R0, R1 refer to RAM[0], and RAM[1], respectively.)

    // If R1 < 0, return (R1 - R1 - R1); otherwise return (R1);
    
    @R1
    // Places value at R1 into D
    D = M
    
// If condition is true (D is greater than 0)
    @IF_TRUE
    D;JGT

    // Subtracting twice; i.e Converting to +ve
    @R1
    D = D - M
    D = D - M

(IF_TRUE)
    // Code block 1; If true condition
    
    @R0
    M = D

(END)
    @END
    0;JMP
