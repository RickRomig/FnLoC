# Changelog
#### April 25, 2018
**DEB package**
* Changed name of .deb package to a more descriptive name that includes the version number and the system architecture.

#### April 4, 2019
**loc2file**
* Created read-only variables. One to hold the version number and the other to hold the copyright information.

#### January 29, 2019
**FnLoC 2.3 & LLoC 1.1**

* Moved common enumerated type and function declarations and common function code relating to determining the states of a line of code being examined into lstates.h and lstates.c. Modified the make file accordingly.

#### January 28, 2019
**FnLoC 2.2.2 & LLoC 1.0**

* Created a simple makefile to compile both programs and tested it in Linux.

#### January 26, 2019
**fnloc 2.2.2 & loc2file 2.2**

* Updated loc2file script to incorporate LLoC for processing header files and allowing the use of .cc and .hh file extensions.
* In fnloc updated print_intro() with current version number and in print_summary() removed the second newline character from the last printf() statement.

#### January 25, 2019
**FnLoC & LLoC**

* Cleaned up some of the FnLoC source code (pretty printing).
* Updated the orginal 1998 loc.c source code so that the line parsing Code matched that of the current FnLoC code. Added functions to display prgram results and to display syntax. Gave it Version 1.0.

#### November 19, 2018
**FnLoC 2.2.1**

* Added code and changed the data structure used in the linked list to allow for a second line in a function header.
* If the function state is PosFunction, included a switch statement to handle the cases where buffer[0] is '{', '}' or white space.
* Modified the functions to insert function data into the linked list and to print function data to reflect changes in the data structure.

#### October 6, 2018
**FnLoC**

* Created a simple deb package, eliminating the need for installation and de-installation script for Debian-based Linux distributions.

#### September 11, 2018
**loc2file**

* Modified loc2file script to accept only source code files ending with .c or .cpp extensions and to display the output to the screen as it is redirected to the file. If there is a header (.h) file with the same base name, it will also be processed and appended without the output header.
* Modified the install script to reflect changes in file names.
* Modified the un-install script to add verbosity to the rm commands.

#### September 10, 2018
**FnLoC v2.2**

* Implemented a singly linked list to replace the stack so that the functions are listed in the order in which they appear in the target source code.
* Simplified the data structures holding the function names and counts. Instead of a data structure in the main program, used simple variables to temporarily hold the function data to be inserted into the list. Added code to initialize variables and reset fn_name and fn_loc after they'd been added to the list.
* Split the print_data() function to display the program output into three separate functions based on their intended purpose:
```
void print_intro(char source[])
void print_fn_data(char source[], int fn_count, int prg_loc)
void print_summary(int fn_count, int total_fn_loc, int prg_loc)
```
* Changed main() to incorpate the functions that handle the linked list.
* In main(), renamed some of the counting variables to be more meaningful.
* Changed the if condition that set the PosFunction state to disregard the current function state and base the change in state on the presence of an alpha character in the first position of the buffer string.
```
if ( fn_state == NotFunction && isalpha(buffer[0]) ) is now
if ( isalpha(buffer[0]) )
```
* The Linux gcc compiler gave a warning about the NewLineNC state not being handled in switch (state) so I added a case statement for it that does nothing since NewLineNC is a transitory state that is handled outside of the switch (state).
```
case (NewLineNC) :
        break;
```
#### September 4, 2018
**fnloc.c v2.1.2**

* Fixed the problem with splitting function headers to fit within a 80 character line by changing conditional statement in the main function:
 * Old line:
```
if ( fn_state == PosFunction && buffer[0] != '{' )
```
 * New line:
```
if ( fn_state == PosFunction && buffer[0] == '}' )
```
* Previously, the line changed the function state from PosFunction to NotFunction if the first character of the next line was not '{'. By changing the condition, the state remains in PosFunction until '{' or '}' is encountered as the first character of a line, changing the state to IsFunction or NotFunction, respectively.
* Tested on test cases containing split-line function headers and LOC counts were correct. Although split-line function headers were counted correctly, the function name captured and passed to the data structure was only what was contained on the first line.
* Moved declarations for macros, data structures, and functions to fnloc.h and successfully compiled. Successfully tested against test source files.

#### September 3, 2018
**fnloc.c v2.1.1**

* Created test source code files to test how the program counts lines of code and functions under different conditions such as when lines of code are split to fit with in 80 character margins. Aside from function headers, splitting code lines does not affect loc counts. A split function header results in the function not being properly identified and processed as a function. The code within the function is still counted but as non-function code. The function header itself is not counted.
* Removed the case ',': condition form next_line_of_code(). Lines within array and some enumerated type declarations were being needlessly counted and split lines of could may have been counted as two lines.
* Removed the case ':': condition. Decided that case 'x': followed by an action, should be counted like other conditional statements.
* Updated README with more detailed information on program limitations and reformatted the text to make it more readable.
* Created 'loc2file' Bash script to redirect program output to a text file with the extension .loc.
* Updated fnloc-install.sh and fnloc-uninstall.sh to include the loc2file script.

#### September 1, 2018
 **fnloc.c v2.1**

* Modified the print_data() function. If the program contains no functions, as in the case of a header file, it will display that the program contains no functions followed by the total LOC count.

#### August 2018
**fnloc.c**

* Compiled in Windows 7 with MinGW gcc.
* Modified print_data function to include in the summary, the number of lines of code found outside of functions.
* Added code to properly close the file being read and free the memory allocated to the stack.
* Removed char \*get_function_name(char line[]) function and modified the line that had called the function to use strcpy() to pass the entire line containing the function header to the stack. Changed the size of the fn_name[] element of the stack to match the length of the line buffer.
* Added void show_usage(char p_name[]) to display program syntax and help information. Added code in main() to call the function if argc < 2, file to be read could not be opened, or if the user entered -h or --help as arguments in place of the source code file.
* Fixed STATETYPE next_line_of_code(char ch) so that if an open brace is encountered at the end of a line of code the state will change from LineOfCode to PosEOL, thus ensuring the line will be counted as a line of code.
* Added case ',', case ':' to next_line_of_code() so lines in data structures and arrays are counted correctly. Counts case 'x': as a line of code.

#### July 2018
**fnloc.c**

* Re-entered the original FnLoC code and compiled with GCC on Linux Mint 18.3.

#### April 1998
**fnloc.c**

* Modified print_data() function to include total lines of code in functions in the summary.

#### 12 April 1998
**fnloc.c**

* Added functionality to loc.c to identify and count functions and store function names and function lines of code in a stack.
* Displayed function names with respective line of code counts and a summary of total number of functions and total number of program lines of code.
* Written for CEG 463 class at Wright State University

#### April 1998
**loc.c**

* Counted lines of code in C source code, skipping comments and blank lines, and displayed a summary of total lines of code.
* Written for CEG 463 class at Wright State University
