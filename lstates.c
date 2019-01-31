/*
 * FILE
 *     lloc.c
 * NAME
 *      Copyright 2018 Richard B. Romig
 * EMAIL
 *      rick.romig@gmail.com
 * DATE
 *      29 January 2019
 * DESCRIPTION:
 *      Definitions for functions that are commonn to fnloc and lloc to
 *      determine states of lines being examined.
 * COMPILER INFO
 *      gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0 on Linux Mint 19.1
 *      MinGW gcc on Windows 7
 * MODIFICATION HISTORY
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * 29 January 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lstates.h"

/*
 * FUNCTION
 *	STATETYPE next_new_line(char ch)
 * DESCRIPTION
 *	Determines the next state if in NewLine state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_new_line(char ch)
{
        STATETYPE st;

        if(ch == '\n' )
                st = NewLineNC;
        else if( isspace(ch) )
                st = NewLine;
        else
                switch (ch)
                {
                        case '/':
                                st = PosComment;
                                break;
                        case '#':
                                st = CompDir;
                                break;
                        case '{':
                                st = OpenBracket;
                                break;
                        case '}':
                                st = CloseBracket1;
                                break;
                        default:
                                st = LineOfCode;
                                break;
                }

    return st;
}

/*
 * FUNCTION
 *	STATETYPE next_pos_comment(char ch)
 * DESCRIPTION
 *	Determines the next state if in PosComment state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_pos_comment(char ch)
{
        STATETYPE st;

        switch (ch)
        {
                case '/':
                        st = CppComment;
                        break;
                case '*':
                        st = Comment;
                        break;
                default:
                        st = NewLineNC;
                        break;
        }

    return st;
}

/*
 * FUNCTION
 *	STATETYPE next_cpp_comment(char ch)
 * DESCRIPTION
 *	Determines the next stat if in CppComment state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_cpp_comment(char ch)
{
        STATETYPE st;

        if( ch == '\n' )
                st = NewLineNC;
        else
                st = CppComment;

        return st;
}

/*
 * FUNCTION
 *	STATETYPE next_comment(char ch)
 * DESCRIPTION
 *	Determines the next state if in Comment state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_comment(char ch)
{
	STATETYPE st;

	if ( ch == '*' )
		st = PosEndComment;
	else
		st = Comment;

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_pos_end_comment(char ch)
 * DESCRIPTION
 *	Determines the next state if in PosEndComment state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_pos_end_comment(char ch)
{
	STATETYPE st;

	switch (ch)
	{
		case '/':
			st = EndComment;
			break;
		case '*':
			st = PosEndComment;
			break;
		default:
			st = Comment;
			break;
	}

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_comp_dir(char ch)
 * DESCRIPTION
 *	Determines the next state if in CompDir state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_comp_dir(char ch)
{
	STATETYPE st;

	if (ch == '\n')
		st = NewLine;
	else
		st = CompDir;

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_line_of_code(char ch)
 * DESCRIPTION
 *	Determines the next state if in LineOfCode state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 * MODIFICATION HISTORY
 *	09-03-18 Removed case ',' and case ':'
 */
STATETYPE next_line_of_code(char ch)
{
	STATETYPE st;

	switch (ch)
	{
		case '}':
			st = CloseBracket2;
			break;
		case '{':
		case ';':
			st = PosEOL;
			break;
		default:
			st = LineOfCode;
			break;
	}

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_open_bracket(char ch)
 * DESCRIPTION
 *	Determines the next state if in OpenBracket state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_open_bracket(char ch)
{
	STATETYPE st;

	switch (ch)
	{
		case '\n':
			st = NewLine;
			break;
		case '}':
			st = CloseBracket2;
			break;
		default:
			st = LineOfCode;
			break;
	}

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_close_bracket1(char ch)
 * DESCRIPTION
 *	Determines the next state if in CloseBracket1 state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_close_bracket1(char ch)
{
	STATETYPE st;

	if ( ch == '\n' )
		st = NewLineNC;
	else
		st = CloseBracket2;

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_close_bracket2(char ch)
 * DESCRIPTION
 *	Determines the next state if in CloseBracket2 state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_close_bracket2(char ch)
{
	STATETYPE st;

	if ( ch == ';' )
		st = PosEOL;
	else
		st = LineOfCode;

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_pos_eol(char ch)
 * DESCRIPTION
 *	Determines the next state if in PosEOL state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_pos_eol(char ch)
{
	STATETYPE st;

	switch (ch)
	{
		case '\n':
			st = NewLine;
			break;
		case ' ':
		case '\t':
			st = PosEOL;
			break;
		case '/':
			st = InlineComment;
			break;
		default:
			st = LineOfCode;
			break;
	}

	return st;
}

/*
 * FUNCTION
 *	STATETYPE next_inline_comment(char ch)
 * DESCRIPTION
 *	Determines the next state if in InlineComment state.
 * PARAMETERS
 *	char ch - a character from the buffer containing the line of
 * 		  code being examined.
 * RETURN VALUE
 *	Returns the new state.
 * SIDE EFFECTS
 *	None known
 * LIMITATIONS
 *	None known
 */
STATETYPE next_inline_comment(char ch)
{
	STATETYPE st;

	if ( ch == '\n' )
		st = NewLine;
	else
		st = InlineComment;

	return st;
}

/* FUNCTION
 *	void show_usage(char p_name[])
 * DESCRIPTION
 * 	Displays program usage information if no arguments are passed, file
 * 	cannot be opened or -h or --help is passed.
 * PARAMETERS
 *	char p_name[] - the name of this program (argv[0])
 * RETURN VALUE
 * 	none
 * SIDE EFFECTS
 *	none
 * LIMITATIONS
 * 	none
*/
void show_usage(char p_name[])
{
 	printf("\tUsage: %s filename\n", p_name);
 	printf("\tWhere filename is a C or C++ source code or header file.\n");
 	printf("\tSee README for information regarding style requirements\n");
 	printf("\tand limitations.\n\n");
}
