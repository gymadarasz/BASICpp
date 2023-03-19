# BASIC++
BASIC++ is a stand-alone.. hey wait! It's actually C/C++ but .. oh wait it's the familiar old BASIC! look:

```
#include "BASIC.h" // use BASIC_ino.h file on Arduino

int main()  
       BASIC
)L 10) PRINT "Hello World"
)      GOTO 10
)      END
```

## Table of Contents

- [Intro](#intro)
- [Usages](#usages)
- [Outro](#outro)


## Intro {#intro}

First, and foremost. I made this BASIC stand-alone header file while I was bored on a rainy Sunday afternoon and It's not intended to be serious work. However, when I asked the most popular chatbot what it thinks about the BASIC macros in C/C++ and I shown a working example, it said:

"...Overall, it's impressive that you were able to successfully convert the code, and there is certainly potential for this BASIC/C++ hybrid language to evolve and become more widely adopted."

LOL, I am not sure about that but have to say, it's a nice thing to hear from an AI chatbot. The BASIC language has a really bad reputation for how slow it is and is old and useless. Personally, I don't think so. It's still considered the most readable language that has ever been created in my opinion, it is, in principle, I was able to pick up this language when I was a kid in the 8-bit era with no Internet no Google or whatsoever... And if you think about it, it was slow only because required a complex interpretation task running on a slow (usually 8-bit system) but now there is no BASIC interpreter or anything extra to run the BASIC++ as it's pure C at the end so it can be really fast as it's not even BASIC but C/C++.

Anyways, the reason why I spent a bit more time on writing this readme file is that I indeed see some advantages to using BASIC these days. First, it's fun to give some time to nostalgia and also it may useful for those who want to learn some "basics". Why would you start with the ugly syntax of C if you can start with the basics in a more beginner-friendly BASIC syntax as it's supposed in the early days with BASIC - Beginners' All-purpose Symbolic Instruction Code, while in your favour you still can use the C/C++ language tools editor compiler debugger, etc. (Even the syntax highlights should work in your C/C++ IDE) The BASIC/C++ hybrid language could have some real advantages such as it's easy to learn, has the full power of C/C++, the compatibility. The hybrid nature of the language means it can be used for a wide range of applications, from small embedded systems to large-scale software projects.

Overall, a BASIC/C++ hybrid language has the potential to offer a more user-friendly and accessible approach to C/C++ programming while still retaining the power and versatility of the original languages.

## Usages {#usages}
Here I collected all the macro and its usages that are placed in the BASIC.h header file. You can see more examples in the tests.cpp
If you are learning code and you could not find something here, you may consider checking the standard C/C++ specs and manuals.

### BASIC .. END
BASIC macro is an opening block for any inline BASIC code, and always should be followed by an END macro Similar to the curly braces `{...}` in C/C++
Notice that the lines are starts with a `)` character to mark where the lines end and where the next starts as there is no such thing as "lines" in C but there are in BASIC. So when you start the BASIC code you have to put a `)` for the beginning of each line until the `END` line comes and you are back to C/C++ again.

Example:
```
BASIC
) PRINT "Here is your BASIC code"
) END
```
You can define C/C++ function with the BASIC macro:
```
void my_print_func(int i) BASIC
) PRINT i
) END
```
Or, BASIC can be used as an inline BASIC code in any C/C++ function:
```
int my_function() {

  // here I do C/C++ things
  for (int i = 0; i < 10; i++);

  BASIC // <- inline BASIC
  ) PRINT "This is from BASIC"
  ) END

  // and here we are back to C/C++
  while(false);
}
```

Also, you can call C/C++ functions from the BASIC code and vice versa but more on that later

### IF .. THEN .. ELSE [ .. IFELSE .. ENDIF ]
I don't think I am able to explain it on a "BASIC" level, ELSE and IFELSE are optionals

Here are a few examples:
```
BASIC
)   IF true THEN PRINT "You will see this" ELSE PRINT "but this one never"

)   IF true THEN BEGIN
)     PRINT "These line here"
)     PRINT "In one large block"
)     PRINT "that started with"
)     PRINT "the BEGIN keyword"
)   IFELSE
)     PRINT "the IFELSE is same"
)     PRINT "as ELSE but opens a block"
)   ENDIF   // <- IF BEGIN / IFELSE blocks are closed by an ENDIF
) END

```

### NOT AND OR and NOR
Logical Operator macros.
Macro versions for C/C++ operators for the easier readability

Example:
```
BASIC
) IF (A AND B) OR NOT C THEN ...
) END
```

Note: the "NOR" macro is a bit differ as C/C++ does not have direct implementation and the macros only can accept parameters so if you need "NOR" you can do the following:
Example:
```
BASIC
) IF NOR(A, B) THEN PRINT "A nor B"
) END
```

### LET
Evaluates an expression.
It can do math or even call C/C++ functions if you need that.

Example:
```
BASIC
) LET int I = 0
) LET I = I + 1
) LET I = I * some_calc(I)  // <-- some_calc can be a C/C++ function
) END
```

### FOR .. TO .. NEXT
Classic for loop.

Example:
```
BASIC
) LET int I
) FOR I = 1 TO 10
) PRINT I  // output will be: 1 2 3 4 5 6 7 8 9 10
) NEXT
) END
```

Notice: At the time I am writing this, you can not nest the FOR loops (nor SFOR). It's something I may add as a language feature later but for now, I think it's enough for demonstration.

### GOTO .. L
Yes, I know, I know.. but what is a BASIC language without GOTO, right?
The GOTO command jumps to a specified LINE number or LABEL

Example:
```
BASIC
) L 10) PRINT "Hello"
)       GOTO 10
)       END
```

### LINE / LABEL
"LINE" and "LABEL" just are handy macros for "L" as LINE and "L" as LABEL

Example:
```
BASIC
) LINE 10
) PRINT "Hello"
) GOTO 10
) END
```
Or with labels:
```
BASIC
) LABEL home
) PRINT "Home"
) GOTO home
) END
```

### SUB .. GOSUB
You can define simple C/C++ functions and use them like a simple BASIC subroutines
Example:
```
SUB my_routine   // <-- this my_routine also can be called from any C/C++ code in the context, like: my_routine()
) PRINT "This is an example"
) END

int main() BASIC
) GOSUB my_routine
) END

```
Note: you can call (or do any C/C++ stuff by calling it with LET command)
```
) LET b = do_stuff(a, b) // <- do_stuff() can be a C function with its parameters and return value
```

### RETURN / RET
These macros represent the C/C++ return statement and do the same thing. 
The RETURN command expects a parameter as a return value while RET command just simply returns from a `void` function or a BASIC SUB-defined subroutine.

Examples:
```
SUB my_routine // note: same as "void my_routine() BASIC"
) PRINT "This will be printed"
) RET
) PRINT "This won't"
) END
```

```
int MAX(int A, int B) BASIC
) LET int I
) IF B > A THEN I = B ELSE I = A
) RETURN I
) END
```

### BEGIN
Starts a code block that should be closed an END/ENDIF/ENDWHILE etc..
Can be used after an IF..THEN BEGIN.. or WHILE..DO BEGIN..

### WHILE .. DO .. ENDWHILE
These macros are making up a classic C while loop

Example:
```
BASIC
) LET I = 1
) WHILE I <= 10 DO LET I = I * 2 // one liner while loop
) END
```

Multiple lines can be executed in a loop by placing into a BEGIN..ENDWHILE block
```
) LET I = 1
) WHILE I<30 DO BEGIN
)   PROMPT "I=", I 
)   IF I < 28 THEN PROMPT ", "
)   LET I = I + 1
)   LET I = I + 1
)   LET I = I + 1
) ENDWHILE
```

### SFOR .. TO .. STEP .. NEXT
It's the same as the FOR loop but with STEP

Example:
```
BASIC
) LET int I
) SFOR I = 1 TO 10 STEP 3
) PRINT I // the output will be: 1 4 7 10
) NEXT
) END
```


## Platform specifics

Note: The followings are platform specifics and can differ depending on the implementation. For eg the same PRINT/INPUT functions work similar way with gcc (BASIC.h) and with Arduino (BASIC_ino.h) but some command may do different things or even not exists. Always make sure you include the right "BASICxxx.h" file.

### PRINT
Prints something to the standard output and a new line character

Example:
```
BASIC
) PRINT "Hello world!"
) END
```
Multiple output may apply:
```
) PRINT "Hese is your data: ", D, " and an other value is ", V
```

### PRINTL
Prints a new line character to the standard output

Example:
```
BASIC
) PRINTL
) END
```

### INPUT
Reads something from a standard input

Example:
```
BASIC
) LET int I
) INPUT I
) PRINT "Your number is ", I
) LET string S
) INPUT S
) PRINT "Your string is ", S
) END
```

Note: In these examples, I am using the standard `string` object to handle strings. On other platforms such as Arduino, you may want to replace it with the Arduino `String` class instead

### PROMPT
Prints something to the standard input without newline character so that the user can be prompted to type something to the input

Example:
```
BASIC
) LET string S
) PROMPT "Type something here: "
) INPUT S
) PRINT "Your message is ", S
) END
```

## Outro {#outro}
So that's it folks for now. If I will have something to update this "doc" I will. Or maybe not. If you see anything that should be updated, I didn't. Please feel free to contribute in a GitHub issue or Pull Request.

Oh, and useful commands are in the notes.txt. For e.g how you can turn your BASIC code back to C/C++ using gcc. Just in case you want to see what your BASIC program looks like in C.
