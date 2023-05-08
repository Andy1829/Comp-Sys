// Finds the smallest element in the array of length R2 whose first element is at RAM[R1] and stores the result in R0.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// R1 = Address of first element in array
// R2 = Length of array

// IN TERMS OF C++ CODE
// int currMin = arr[0];
// int length = 4           // REFERING TO VAL STORED IN R1

// for (int i = 0; i < 4; i++) 
//     if (arr[i] < currMin) {
//        currMin = arr[i];
//     }
// }




// Selecting first element of the array:
    // This correctly implements first line; int currMin = arr[0]
    @R1
    A = M               // Sets value of A to RAM[1] = 20
    D = M               // Grabs value of RAM[A] into D = RAM[20]

    // @R0
    // M = D

    @currentMin         // Position: RAM[16]
    M = D               // Tracks val of first element == 2

    @iterator           // Defines iterator var = 1
    M = 1
    
// Run some sort of loop for each value of the index
(LOOP)
    // IF LOOP 
    @R1                 // A = 1; M = 20
    D = M               // D = 20

    @iterator           // Position: RAM[17] = 1
    D = D + M           // RAM Index + Iterator (D = 20->23)
    
    // D currently stores the index that we are looking at:
    A = D               // A = 21 -> 23
    D = M               // Sets D to val of the current index that we are looking at   // D = RAM[21 -> 23]
    
    @currentMin         
    D = D - M           // D = RAM[20 -> 23] - currentMin       

    @CURR_VAL_IS_SMALLER
    D;JLT

    // Repeats the if statement on each element of the array until we have run out of options
    @R2             // If we have not yet broken the loop, iterate downwards 
    D = M           // Sets D to 4
    
    @iterator
    M = M + 1

    @iterator
    D = D - M       // Checks that we have not exceeded length of array

    @END            // Selects required jump line
    D;JEQ           // Breaks loop if M = 0


    @LOOP
    0;JMP       // Jumps unconditionally; repeats UNTIL loop is broken [refer to after @END]

//-----------------------------------------------------------------------------

(CURR_VAL_IS_SMALLER)
    @R1                 // A = 1; M = 20
    D = M               // D = 20

    @iterator           // Position: RAM[17] = 1
    D = D + M           // RAM Index + Iterator (D = 20->23)
    
    // D currently stores the index that we are looking at:
    A = D               // A = 21 -> 23
    D = M               // Sets D to val of the current index that we are looking at   // D = RAM[21 -> 23]
    
    @currentMin
    M = D

    // @iterator
    // M = M + 1

    @LOOP
    0;JMP


//---------------------------------------

(END)
    @currentMin
    D = M

    @R0
    M = D

    @END
    0;JMP


// I HAVE A SLIGHT IDEA WITH HOW TO APPROACH THIS !!!!!!!!!!
// FOR THE CONDITIONS INSIDE THE LOOP, HAVE MULTIPLE JUMP CONDITIONS WITH THEIR POSITION AFTER THE MAIN LOOP STRUCTURE. 
// ONCE THE LOOP IS COMPLETELY FINISHED (ALL ITERATIONS HAVE BEEN RUN) JUMP TO ORIGINAL LOCATION AFTER THE EXTRA JUMP CONDITIONS
