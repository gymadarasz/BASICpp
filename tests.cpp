// compile and run: see in notes.txt


#include "BASIC.h"


// -----------------------------------------------
// TESTING
// -----------------------------------------------

int INC(int a) BASIC
) RETURN a + 1
) END

int TEST(int a, int b) BASIC
) IF a != b THEN BEGIN
)   PRINT "Test failed, because ", a, " is not equals to ", b
)   EXIT 1
) ENDIF
) RETURN true
) END

int TEST(int a) BASIC
) IF !a THEN BEGIN
)   PRINT "Test failed, because ", a, " is not true"
)   EXIT 1
) ENDIF
) RETURN true
) END

int TEST(string a, string b) BASIC
) IF a != b THEN BEGIN
)   PRINT "Test failed, because the two strings are not equals:"
)   PRINT "String A: ", a
)   PRINT "String B: ", b
)   EXIT 1
) ENDIF
) RETURN true
) END


SUB whiletest
) LET int I
) PRINT "WHILE tests"
) PRINT "one liner WHILE test"
) LET I = 1
) WHILE I<10 DO LET I = I + 1
) LET TEST(I, 10)
) PRINT "multi liner WHILE test"
) LET I = 1
) WHILE I<30 DO BEGIN
)   PROMPT "I=", I 
)   IF I < 28 THEN PROMPT ", "
)   LET I = I + 1
)   LET I = I + 1
)   LET I = I + 1
) ENDWHILE
) PRINTL
) LET TEST(I, 31)
) PRINT "end WHILE test"
) END

SUB gototest
) LET int I 
) PRINT "do GOTO test"
)                   PRINT "testing GOTO up/down to LABEL"
)                   LET I = 0
) LABEL label1)     PRINT "at label1.. I=", I
)                   LET I = I + 1
)                   IF I > 5 THEN GOTO label1_end
)                   GOTO label1
) LABEL label1_end) LET TEST(I, 6)
)                   PRINT "testing GOTO up/down to LINE"
)                   LET I = 0
) LINE 10)          PRINT "at line 10.. I=", I
)                   LET I = I + 1
)                   IF I > 5 THEN GOTO 20
)                   GOTO 10
) LINE 20)          LET TEST(I, 6)
)                   PRINT "testing GOTO up/down to L (L is a label)"
)                   LET I = 0
) L label2)         PRINT "at label2.. I=", I
)                   LET I = I + 1
)                   IF I > 5 THEN GOTO label2_end
)                   GOTO label2
) L label2_end)     LET TEST(I, 6)
)                   PRINT "testing GOTO up/down to L (L is a number)"
)                   LET I = 0
) L 30)             PRINT "at line 30.. I=", I
)                   LET I = I + 1
)                   IF I > 5 THEN GOTO 40
)                   GOTO 30
) L 40)             LET TEST(I, 6)
) PRINT "end GOTO test"
) END

SUB testSub
) PRINT "Test SUB"
) PRINT "Test function"
) LET int I = INC(123);
) PRINT "I=", I
) IF NOT TEST(124, I) THEN PRINT "FAIL!"
) PRINT "End subtest"
) END

SUB fortest
) PRINT "FOR-TEST"
) LET int I
) LET int steps = 20
) FOR I = 1 TO steps
)   PROMPT I
)   IF I < steps THEN PROMPT ", "
) NEXT
) PRINTL
) LET TEST(I, 21)
) PRINT "END-FOR-TEST"
) END

int selectif(int I) BASIC
) LET int R = 0
) IF I==1 THEN LET R = 111
) ELSE IF I==2 THEN LET R = 222
) ELSE IF I==3 THEN LET R = 333
) ELSE IF I==4 THEN LET R = 444
) ELSE IF I==5 THEN LET R = 555
) ELSE LET R = 99999
) RETURN R
) END

int selectifblock(int I) BASIC
) LET int R = 0
) IF I==1 THEN BEGIN
)   LET R = 111
) IFELSE IF I==2 THEN BEGIN
)   LET R = 222
) IFELSE IF I==3 THEN BEGIN
)   LET R = 333
) IFELSE IF I==4 THEN BEGIN
)   LET R = 444
) IFELSE IF I==5 THEN BEGIN
)   LET R = 555
) IFELSE BEGIN
)   LET R = 99999
) ENDIF
) RETURN R
) END

void iftest () BASIC 
) PRINT "IF-TESTS..."
) LET int I = 4
) LET int R = 0
) IF I == 2 THEN LET R = 1
) LET TEST(R, 0) // R did not changed because I is not 2
) IF NOT (I == 2) THEN LET R = 2
) LET TEST(R, 2) // R changed to 2 because I is not 2
) PRINT "testing if blocks"
) LET R = 0
) IF I == 4 THEN BEGIN
)   LET R++
)   LET R++
)   LET R++
) ENDIF
) LET R++ // one extra to see if smthng wrong..
) LET TEST(R, 4) // R now should be 3 because all the if block proceed after the BEGIN
) PRINT "inline else test"
) LET R = 0
) IF true THEN PRINT "[...]" ) ELSE LET R = 1
) LET TEST(R, 0)
) IF false THEN PRINT "[...]" ) ELSE LET R = 1
) LET TEST(R, 1)
) PRINT "else block test"
) LET R = 0
) IF true THEN PRINT "[...]" ) ELSE BEGIN
)   LET R = R + 1
)   LET R = R + 1
)   LET R = R + 1
) ENDIF
) LET TEST(R, 0)
) IF false THEN PRINT "[...]" ) ELSE BEGIN
)   LET R = R + 1
)   LET R = R + 1
)   LET R = R + 1
) ENDIF
) LET TEST(R, 3)
) LET R = 0
) IF true THEN BEGIN
)   PRINT "[...]" 
) IFELSE BEGIN
)   LET R = R + 1
)   LET R = R + 1
)   LET R = R + 1
) ENDIF
) LET TEST(R, 0)
) IF false THEN BEGIN
)   PRINT "[...]" 
) IFELSE BEGIN
)   LET R = R + 1
)   LET R = R + 1
)   LET R = R + 1
) ENDIF
) LET TEST(R, 3)
) PRINT "test else-if"
) LET TEST(selectif(1), 111)
) LET TEST(selectif(2), 222)
) LET TEST(selectif(3), 333)
) LET TEST(selectif(4), 444)
) LET TEST(selectif(5), 555)
) LET TEST(selectif(6), 99999)
) LET TEST(selectifblock(1), 111)
) LET TEST(selectifblock(2), 222)
) LET TEST(selectifblock(3), 333)
) LET TEST(selectifblock(4), 444)
) LET TEST(selectifblock(5), 555)
) LET TEST(selectifblock(6), 99999)
) PRINT "paranoid nesting tests"
) LET R = 0
) IF (true) THEN BEGIN
)   IF (false) THEN LET TEST(false) ) ELSE IF(true) THEN BEGIN
)     IF (false) THEN LET TEST(false) ) ELSE BEGIN
)       LET TEST(true) 
)       LET R = 1 // <-- !!! we should go here
)     ENDIF
)   IFELSE LET TEST(false)
) IFELSE IF(true) THEN BEGIN
)   LET TEST(false) // can not reach this
) ENDIF
) LET TEST(R, 1)
) PRINT "END-IF-TESTS"
) END


SUB subtest
) PRINT "FOO1"
) END

SUB logictest
) PRINT "some logic test..."
) LET TEST(true == false, false)
) LET TEST(NOT true, false)
) LET TEST(NOT false, true)
) LET TEST(false AND false, false)
) LET TEST(true AND false, false)
) LET TEST(false AND true, false)
) LET TEST(true AND true, true)
) LET TEST(false OR false, false)
) LET TEST(true OR false, true)
) LET TEST(false OR true, true)
) LET TEST(true OR true, true)
) END

SUB forsteptest
) PRINT "SFOR..STEP tests"
) LET int I
) LET int J = 0
) SFOR I = 1 TO 10 STEP 2
) LET J = J + 1
) NEXT
) LET TEST(J, 5)
) END

SUB inputtest
) LET int I
) LET string S
) PRINT "INPUT tests"
) PRINT "Test for a simple input (number)"
) PROMPT "Type the number 23: "
) INPUT I
) PRINT "You typed: ", I
) LET TEST(I, 23)
) PRINT "Test for a simple input (string)"
) PROMPT "Type a string 'asd': "
) INPUT S
) PRINT "You typed: ", S
) LET TEST(S, string("asd"))
) PRINT "Test for a prompted input (number)"
) INPUT I, "Type the number 23: "
) PRINT "You typed: ", I
) LET TEST(I, 23)
) PRINT "Test for a prompted input (string)"
) INPUT S, "Type a string 'asd': "
) PRINT "You typed: ", S
) LET TEST(S, string("asd"))
) END

SUB nortest
) PRINT "NOR tests"
// ) LET TEST(NOR(false), true)
) LET TEST(NOR(false, false), true)
// ) LET TEST(NOR(false, false, false), true)
// ) LET TEST(NOR(true), false)
) LET TEST(NOR(true, false), false)
// ) LET TEST(NOR(true, false, false), false)
// ) LET TEST(NOR(true), false)
) LET TEST(NOR(true, true), false)
// ) LET TEST(NOR(true, true, false), false)
// ) LET TEST(NOR(true), false)
) LET TEST(NOR(true, true), false)
// ) LET TEST(NOR(true, true, true), false)
// ) LET TEST(NOR(true), false)
// ) LET TEST(NOR(false, true), false)
// ) LET TEST(NOR(false, true, true), false)
// ) LET TEST(NOR(true, false), false)
// ) LET TEST(NOR(true, false, true), false)
// ) LET TEST(NOR(false, false, true), false)
) END

int main () BASIC
) PRINT "CMACRO-BASIC tests"
) GOSUB testSub
) GOSUB subtest
) GOSUB iftest
) GOSUB fortest
) GOSUB gototest
) GOSUB whiletest
) GOSUB logictest
) GOSUB forsteptest
) GOSUB inputtest
) GOSUB nortest
) PRINT "Tests finished - OK"
) RETURN 0
) END
