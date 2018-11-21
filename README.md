# FnLoc - Counts Logical Lines of Code
Counts logical lines of code and functions in C and C++ source code files.

Copyright 2018, Richard Romig

### Description:

FnLoC is a program that runs from a command-line counts logical lines of
code in C and C++ source code files. The program counts lines of code in
C/C++ source code disregarding comments and blank lines. It also counts and
lists functions by name with their respective lines of code.

The program assumes that the code is written according to modern C coding
standards as illustrated in The C Programming Language, 2nd edition by
Brian W. Kernighan & Dennis M. Ritchie.

Comments and blank lines are not counted as lines of code. The programs
takes into account both C and C++ style comments.

Braces '{}' on lines by themselves are not counted as lines of code.

### Installation:

1. If you've downloaded the .deb file use gdebi or dpkg to install.
            sudo gdebi fnloc.deb
            sudo dpkg -i fnloc.deb

2. Unzip the 'fnloc-installation-files' directory by dragging it out of the
Archive Manager application onto your desktop and click on it see the
files.

3. You can install FnLoC from the provided fnloc-install.sh script by
clicking on the fnloc-install.sh file inside a file manager. Choose
"Run In Terminal" from the pop up menu. Alternately, you can choose Open
In Terminal by right-clicking anywhere within the 'fnloc-installation-files'
directory. Run the fnloc-install.sh script with this command:

            ./fnloc-install.sh

4. The fnloc-install.sh script MUST be run within 'fnloc-installation-files'
directory or it will exit with errors. It CANNOT be run directly from the
zip archive.

5. The installation script will install files to the following directories:
            fnloc to /usr/local/bin/
            loc2file to /usr/local/bin/
            fnloc.* to /usr/local/src/fnloc/
            documentation files to /usr/local/doc/fnloc

### Manual Installation:

1. FnLoc and loc2file can be copied directly to either your ~/bin, /usr/bin,
or /usr/local/bin directory.

2. Open a terminal in the unzipped 'fnloc-installation-files' directory and
run the command 'cp fnloc ~/bin/' if you already have a personal bin
directory. Or you can copy it to /usr/local/bin with 'sudo cp fnloc
/usr/local/bin/'.

3. The program is immediately available for use by opening a terminal,
navigating to your source code directory, and running the command 'fnloc'
followed by the name of your source code file, i.e., fnloc mysource.c.

### Un-installation

1. If installed from the .deb package, you can remove the software via your system's Software Center/Manager or Synaptic Package manager.

2. You can remove the software from the command line with one of the following
commands:
            sudo apt-get remove fnloc
            sudo dpkg -- remove fnloc

3. The fnloc-uninstall.sh script will remove FnLoC if it was installed with
the fnloc-install.sh script explained above. It can be run from from a
terminal anywhere within the directory structure.

4. Open the 'fnloc-installation-files' directory and click on the 'fnloc-
uninstall.sh' file and choose Run in Terminal. The script will remove all
of the assoicated files as well as the fnloc directories.

5. You can also navigate to the fnloc-uninstall.sh file from within a
terminal and run it with this command:

            ./fnloc-uninstall.sh

6. Errors reported in this script just mean it could not find all of the
FnLoC files. This usually means FnLoC was not installed with the fnloc-
install.sh and it will have to be removed manually.

### SYNTAX

1. To display the lines of code data of a C source code file run the
following command from a terminal:
        fnloc sourcefile.c
        fnloc /path/to/sourcefile.c

2. The results can be redirected to a text file with the following command:
            fnloc sourcefile.c > sourcefile.loc

3. The results can be diplayed to both the screen and redirected to a file
with the following command:
            fnloc sourcefile.c | tee sourcefile.loc

4. The included loc2file is a Bash script that will display the fnloc output
to the screen and redirect it to a text file with the extension .loc.

              log2file mysource.c
>If there is also an accompanying mysource.h file in the directory,
its LOC data will be appended to that of mysource.c.

5. To get help and view the syntax:
            fnloc -h
            fnloc --help

6. If you don't include an argument or if the program fails to open the file
passed as an argument it will also call up the help function.

### PROGRAM LIMITATIONS

1. Functions are expected to be in the following style:

        int function_name(int x, int y)
        {
            statements....
        }

        -   This is the format recommended by Linus Torvalds in 'Linux Kernel
            Coding Style' and is based on the style used by K&R in 'The C
            Programming Language, 2nd Edition'.
            (https://www.kernel.org/doc/html/v4.10/process/coding-style.html)

        -   If the opening brace '{' is on the same line as the function name
            and parameters, it will not be seen as a function. The lines of code
            will be counted but as code outside of a function.

        -   While the program will properly count function headers that are split
            over two lines, the method for capturing the function name will only
            get the portion the name on the first line. To ensure that the entire
            function name is captured, the function header should be contained on
            one line and less than 128 characters (The buffer limit is set to 128
            characters.)

2. Data structures should be in the following style:

            struct {
                int len;
                char *str;
            } data;

        -   This is the style used by Kernighan & Ritchie in The C Programming
            Language, 2nd edition.

        -   The GNU C coding standard suggests placing the opening brackets are
            at the beginning of a line. However, FNLOC will incorrectly identify
            a structure written in this style as a function.

        -   In data structure declarations such as arrays or enumerated types in
            which the data elements are delimited by commas, the elements inside
            the braces are not counted if they are not on the same line as a brace.

            Example:
                int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            is a single line of code.

                int days[12] = {
                    31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31
                };
            is seen as a two lines of code (the first and last lines).

3.  Conditional statements and for loops without braces and only one
 statement following are counted as one line of code.

            /* This will be seen as a one logical line of code */
            if ( condition )
                action;

            /* This will be seen as a one logical line of code */
            for ( i=1; i < 10; i++ )
                if (condition)
                    action;

            /* This will be seen as 4 logical lines of code - if (condition),
            action1, and action2. The else-action3 is one logical line of code. */
            if ( condition )
            {
                action1;
                action2;
            }
            else
                action3;

4. Conditional and loop statements (if, else, for, while, do, for) where an
opening brace is the first non-whtespace character on the line immediately
following are counted as a line of code.

### Feedback:

Feel free to contact me with comments and suggestions for FNLOC. Also feel free
to share any code that will help me improve this program.

Rick's Tech Stuff: https://ricktech.wordpress.com

Email: rick.romig@gmail.com

Twitter: @ludditegeek

Richard Romig

11 September 2018

### DISCLAIMER

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL I BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS AND SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
