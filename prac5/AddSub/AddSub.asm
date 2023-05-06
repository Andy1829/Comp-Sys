// Calculates R1 + R2 - R3 and stores the result in R0.
// (R0, R1, R2, R3 refer to RAM[0], RAM[1], RAM[2], and RAM[3], respectively.)


@R1             // Selects either A = 1 or M = RAM[1]
D = M           // D = Val stored at RAM[R1]

@R2             
D = D + M       // Selects either A = 2 or M = RAM[2]

@R3
D = D - M

@R0
M = D

(END)
@END
0;JMP