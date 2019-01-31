/*
 * FILE
 *     lloc.c v1.1
 * NAME
 *      Copyright 2018 Richard B. Romig
 * EMAIL
 *      rick.romig@gmail.com
 * DATE
 *      25 January 2019
 * DESCRIPTION:
 * Counts logical lines of code, skipping comments and blank lines, reporting
 * the number of logical lines of code counted.
 * LIMITATIONS
 * Target file must be a text file of C/C++ source code. Results for C source
 * code written in old style style may not be correct as they may not conform
 * to ANSI/ISO coding standards.
 *
 * In data structure declarations such as arrays or enumerated types in which
 * the data elements are delimited by commas, the elements inside the braces
 * are not counted if they are not on the same line as a brace. The first and
 * last lines (the lines with the braces) of the declaration are counted.
 *
 * if, else, for, while, do constructs without braces and only one statement
 *  ending with ';' following will be counted as one line of code.
 *
 * if ( condition )
 * 	action;
 *
 * for ( i = 1; i < 10; i++ )
 * 	if ( condition )
 * 		action;
 *
 * These will each be counted as one line of code when the first ';' at the
 * end of a line is reached.
 *
 * COMPILER INFO
 *      gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0 on Linux Mint 19.1
 *      MinGW gcc on Windows 7
 *
 * MODIFICATION HISTORY
 * 25 Jan 2019  Modified original source code from 1998 Computer Engineering
 * class project to incorporate code from FnLoC 2.2.1 project.
 * 29 Jan 2018 incorporated lstates.h and lstates.c to combine common functions
 * between lloc and fnloc for determining states of the examined lines.
 *
 * GNU Public License, Version 2
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lloc.h"
#include "lstates.h"

int main(int argc, char *argv[])
{
        FILE *fp;
        char buffer[BUF_LEN];
        STATETYPE state = NewLine;
        int loc = 0;
        int i;

        if ( argc < 2 )
	{
		fprintf(stderr, "No source code file passed.\n");
		show_usage(argv[0]);
		exit(1);
	}

	if ( (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0) )
	{
		 show_usage(argv[0]);
		 exit(1);
	}

        fp = fopen(argv[1], "r");
        if( fp == NULL )
        {
                fprintf(stderr, "Cannot open %s\n", argv[1]);
                show_usage(argv[0]);
                exit(1);
        }

        while( !feof(fp) )
        {
                if( fgets(buffer, BUF_LEN, fp) )
                {
                        for( i = 0; i < strlen(buffer); i++ )
                        {
                                switch(state)
                                {
                                case(NewLine) :
                                        state = next_new_line(buffer[i]);
                                        break;
                                case (NewLineNC) :
                                        break;
                                case(PosComment) :
                                        state = next_pos_comment(buffer[i]);
                                        break;
                                case(CppComment) :
                                        state = next_cpp_comment(buffer[i]);
                                        break;
                                case(Comment) :
                                        state = next_comment(buffer[i]);
                                        break;
                                case(PosEndComment) :
                                        state = next_pos_end_comment(buffer[i]);
                                        break;
                                case(EndComment) :
                                        state =  NewLineNC;
                                        break;
                                case(CompDir) :
                                        state = next_comp_dir(buffer[i]);
                                        break;
                                case(LineOfCode) :
                                        state = next_line_of_code(buffer[i]);
                                        break;
                                case(OpenBracket) :
                                        state = next_open_bracket(buffer[i]);
                                        break;
                                case(CloseBracket1) :
                                        state = next_close_bracket1(buffer[i]);
                                        break;
                                case(CloseBracket2) :
                                        state = next_close_bracket2(buffer[i]);
                                        break;
                                case(PosEOL) :
                                        state = next_pos_eol(buffer[i]);
                                        break;
                                case(InlineComment) :
                                        state = next_inline_comment(buffer[i]);
                                        break;
                                } /* end switch(state) */
                        }  /* end for loop */

                        if( state == NewLine )
                                loc++;
                        else if( state == NewLineNC )
                                state = NewLine;
                } /* end if(fgets) */
        } /* end while loop */

        printLoc(argv[1], loc);
        fclose(fp);
        return(0);
}

/*
 * FUNCTION
 *	void printLoc(char source[], int loc)
 * DESCRIPTION
 *	displays program output
 * PARAMETERS
 *	char source[] - character string containing the name of the source
 *			code file - argv[1]
 * RETURN VALUE
 *	None
 */
void printLoc(char source[], int loc)
{
	printf("\nLLoC 1.1\n");
	printf("Copyright 2019 Richard B. Romig\n");
	printf("Licensed under the GNU General Public License, version 2\n\n");
	printf("Lines of code for %s:\t%d\n\n", source, loc);
}
