// Finds the smallest element in the array of length R2 whose first element is at RAM[R1] and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// R1 = Address of first element in array
// R2 = Length of array

// Selecting first element of the array:
    @R1
    A = M               // Sets value of A to RAM[1] = 20
    D = M               // Grabs value of RAM[A] into D = RAM[20]

    // @R0
    // M = D

    @currentMin         // Position: RAM[16]
    M = D               // Tracks val of first element == 2


    @iterator           // Defines iterator var
    M = 1
    
// Run some sort of loop for each value of the index
(LOOP)
    // IF LOOP 
    @R1
    D = M               // D = 20

    @iterator           // Position: RAM[17]
    D = D + M           // RAM Index + Iterator (D = 20->23)
    
    A = D               // A = 20->23
    D = M               // Sets D to val at current index   // D = Ram[20->23]
    
    
    @currentMin         
    D = D - M           // D = Ram[20->23] - currentMin
    @VAL_IS_SMALLER
    D;JGT               // If

    @currentMin
    D = D + M
    M = D

(VAL_IS_SMALLER)

    // Repeats the if statement on each element of the array until we have run out of options

    @R2             // If we have not yet broken the loop, iterate downwards 
    D = M           // Sets D to 
    
    @iterator
    D = D - M       // Checks that we have not exceeded length of array

    @END            // Selects required jump line
    D;JEQ           // Breaks loop if M < 0

    @iterator
    M = M + 1


    @LOOP
    0;JMP       // Jumps unconditionally; repeats UNTIL loop is broken [refer to after @END]

(END)

    @currentMin
    D = M

    // @R0
    // M = D

    @END
    0;JMP


