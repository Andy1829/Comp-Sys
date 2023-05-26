load Mult.vm,
output-file Mult06.out,
compare-to Mult06.cmp,
output-list sp%D1.6.1 local%D1.6.1 argument%D1.8.1 this%D1.6.1 that[4]%D1.6.1
            RAM[16]%D1.6.1 RAM[17]%D1.6.1 local[0]%D1.8.1,

set sp 256,        // stack pointer
set local 300,     // base address of the local segment
set argument 400,  // base address of the argument segment
set this 3000,     // base address of the this segment
set that 3010,     // base address of the that segment

set RAM[253] 1,
set RAM[254] 2,
set RAM[255] 3,
set RAM[256] 0,
set RAM[257] 0,
set RAM[258] 0,




set RAM[16] 10,   // static 0
set RAM[17] 20,  // static 1
set RAM[18] 30,   // static 2
set RAM[19] 40,   // static 3

set local[0] 110,  // local 0
set local[1] 120,  // local 1
set local[2] 130,  // local 2
set local[3] 140,  // local 3

set argument[0] 210,  // argument 0
set argument[1] 220,  // argument 1
set argument[2] 230;  // argument 2
set argument[3] 240;  // argument 3

set this[0] 310,  // local 0
set this[1] 320,  // local 1
set this[2] 330,  // local 2
set this[3] 340,  // local 3

set that[0] 410,  // local 0
set that[1] 420,  // local 1
set that[2] 430,  // local 2
set that[3] 440,  // local 3

set temp[0] 510,  // local 0
set temp[1] 520,  // local 1
set temp[2] 530,  // local 2
set temp[3] 540,  // local 3


set local[0] 0,  // local 0
set RAM[16] 5,  // local 1
set RAM[17] -3,  // local 2


repeat 600 {        // Change this number to cover the number of instructions in the VM test file
  vmstep;
}
output;