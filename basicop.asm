        ; Assembly Program: Basic Operations (Addition and Subtraction)
        ; Objective: Add and subtract two numbers stored in memory and output the results.

        ; Load NUM1 into register R0 for addition operation
        LOAD R0, NUM1         ; R0 = NUM1 (load the first number, e.g., 5, into R0)
        
        ; Add NUM2 to the value in R0
        ADD R0, NUM2          ; R0 = R0 + NUM2 (add the second number, e.g., 3, to R0; R0 now holds 8)
        
        ; Store the result of addition (SUM) in memory
        STORE R0, SUM         ; SUM = R0 (store the result of NUM1 + NUM2 in SUM)

        ; Reset R0 for the subtraction operation by loading NUM1 again
        LOAD R0, NUM1         ; R0 = NUM1 (reload the first number, 5, into R0)
        
        ; Subtract NUM2 from R0
        SUB R0, NUM2          ; R0 = R0 - NUM2 (subtract the second number from R0; R0 now holds 2)
        
        ; Store the result of subtraction (DIFF) in memory
        STORE R0, DIFF        ; DIFF = R0 (store the result of NUM1 - NUM2 in DIFF)

        ; Output the result of the addition (SUM)
        LOAD R0, SUM          ; R0 = SUM (load the addition result, 8, from SUM into R0)
        OUT R0                ; Output R0 (display the value of SUM, which is 8)

        ; Output the result of the subtraction (DIFF)
        LOAD R0, DIFF         ; R0 = DIFF (load the subtraction result, 2, from DIFF into R0)
        OUT R0                ; Output R0 (display the value of DIFF, which is 2)

        ; End the program
        HLT                   ; Halt the execution (program stops)

; Data Section
; Initialize memory locations for input numbers, sum, and difference
NUM1    .DATA 5             ; First number (5) to be used in addition and subtraction
NUM2    .DATA 3             ; Second number (3) to be used in addition and subtraction
SUM     .DATA 0             ; Placeholder for the result of NUM1 + NUM2 (initialized to 0)
DIFF    .DATA 0             ; Placeholder for the result of NUM1 - NUM2 (initialized to 0)
