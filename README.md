# FnLoC - Counts Logical Lines of Code
Counts logical lines of code and functions in C and C++ source code files.

Copyright 2018, Richard Romig

### Description:
FnLoC is a program that runs from a command-line which counts logical lines of code in C and C++ source code files disregarding comments and blank lines. It also counts and lists functions by name displaying their respective lines of code.

The program assumes that the code is written according to modern C coding standards as illustrated in The C Programming Language, 2nd edition by Brian W. Kernighan & Dennis M. Ritchie.

Comments and blank lines are not counted as lines of code. The programs takes into account both C and C++ style comments /* .... */ and // .....

Lines containing only opening or closing braces ({}) are not counted as lines of code.

### Installation:

1. In Debian-based distributions (Ubuntu, Mint, etc.) FnLoC can be installed from the .deb package using gdebi or dpkg.

        sudo gdebi fnloc.deb
        sudo dpkg -i fnloc.deb

2. The FnLoC files will be installed to the following directories:

        fnloc to /usr/local/bin/
        loc2file to /usr/local/bin/
        fnloc.* to /usr/local/src/fnloc/ # fnloc.c, fnloc.h, fnloc.loc
        documentation files to /usr/local/doc/fnloc/

3. For other Linux distributions, download the fnloc-installation-files.tar.gz file, unzip it, and run fnloc-install.sh from a terminal. Further instructions are contained in that archive.

4. Windows users need to download FnLoC_Win.zip and run FnLoC-install.bat. See the included README.txt for more information.

### Un-installation

1. If installed from fnloc.deb, you can remove the software via your system's Software Center/Manager or the Synaptic Package manager. You can remove the software from the command line with one of the following commands:

            sudo apt-get remove fnloc
            sudo dpkg -- remove fnloc

2. If installed using the fnloc-install.sh installation script, use the fnloc-uninstall.sh script found in the archive file.

3. If installed using FnLoC-install.bat in Windows, uninstall with FnLoC-uninstall.bat. See the included README.txt for more information.

4. FnLoC can be removed manually by deleting the installed files.

### Syntax

1. To display the lines of code data of a C source code file run the following command from a terminal:

 * If you are in same directory as the targeted source code file:

                fnloc sourcefile.c

 * Or include the path to your source code:

                fnloc /path/to/sourcefile.c

 * The results can be redirected to a text file with the following command:

                fnloc sourcefile.c > sourcefile.loc

 * The results can be diplayed to both the screen and redirected to a file with the following command:

                fnloc sourcefile.c | tee sourcefile.loc

 * The included loc2file is a Bash script that will display the FnLoC output to the screen while redirecting it to a text file with the extension .loc. If there is also an accompanying header file of the same name in the directory, its LOC data will be appended to that of mysource.c.

                log2file mysource.c

 * To get help and view the syntax:

                fnloc -h
                fnloc --help

 * If you don't include an argument or if the program fails to open the file passed as an argument it will also call up the help function.

### Program Limitations

1. Functions are expected to be in the following style:

        int function_name(int x, int y)
        {
            statements....
        }

 * This is the format recommended by Linus Torvalds in [Linux Kernel Coding Style](https://www.kernel.org/doc/html/v4.10/process/coding-style.html) and is based on the style used by K&R in 'The C Programming Language, 2nd Edition'.

 * If the opening brace '{' is on the same line as the function name and parameters, it will not be seen as a function. The lines of code will be counted but as code outside of a function.

 * The program will properly count and display function headers that are split over two lines. Function headers should be limited to one or two lines of less than 128 characters each. The buffer limit is set to 128 characters. However, restraining function headers to a single line and 80 characters or less is a good practice.

2. Data structures should be in the following style:

        struct {
           int len;
           char *str;
        } data;

 * This is the style used by Kernighan & Ritchie in The C Programming Language, 2nd edition.

 * The GNU C coding standard suggests placing the opening brackets are at the beginning of a line. However, FnLoC will incorrectly identify a structure written in this style as a function.

 * In data structure declarations such as arrays or enumerated types in which the data elements are delimited by commas, the elements inside the braces are not counted if they are not on the same line as a brace.

          int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            /* counted as a single line of code. */

         int days[12] = { 31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };
            /* counted as two lines of code */            

         int days[12] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31 };
            /* also counted as two lines of code (the first and last lines) */

3. Conditional statements, for loops and while loops without braces and only one statement following are counted as one line of code.

        if ( condition )
                action;
        /* This is seen as a one logical line of code */

        for ( i=1; i < 10; i++ )
                if (condition)
                    action;
        /* This is seen as a one logical line of code */

        while ( condition )
                action;
        /* This is seen as a one logical line of code */

        do
                action;
        while ( condition );
        /* This is seen as two logical lines of code */

        if ( condition )
        {
            action1;
            action2;
        }
        else
            action3;
        /* This is seen as 4 logical lines of code: (1) if ( condition ), (2) action1,
           (3) action2, (4) else-action3 */

4. Conditional and loop statements (if, else, for, while, do-while) where the opening brace is the first non-whtespace character on the line immediately following are counted as a line of code. Conditional statements and loop constructs can have the opening brace at either the end of the line or on the following line as long as it is not the very first character of the line (buffer[0]).

        while ( condition )
        {
                action1;
                action2;
        }

        while ( condition ) {
                action1;
                action2;
        }

### Feedback:

Feel free to contact me with comments and suggestions for FnLoC. Also feel free to share any code or ideas that will help me improve this program. I can be reached through my blog, Twitter, and email.

>[GitHub](https://github.com/RickRomig/FnLoC)
>
>[Rick's Tech Stuff](https://ricktech.wordpress.com)
>
>[Twitter (@ludditegeek)](https://twitter.com/ludditegeek)
>
>Email: <rick.romig@gmail.com> or <rb_romig@twc.com>

Richard Romig
11 January 2019

### DISCLAIMER

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS AND SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
