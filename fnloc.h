/*
 * FILE
 *      fnloc.h -- header file for fnloc.c version 2.3
 * NAME
 *      Copyright (C) 2019  Richard Romig
 * EMAIL
 *      rick.romig@gmail.com
 * DATE
 *      6 September 2018
 * DESCRIPTION:
 * 	Header file for fnloc.c
 * 	Declares constants, global variables, enumberated types and functions.
 *
 * MODIFICATION HISTORY
 *      Separated common data and functions used in fnloc and lloc and put them
 *      into lstates.h and lstates.c
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

#ifndef FNLOC_H
#define FNLOC_H

/* Maximum buffer length */
#define BUF_LEN 128

/* linked list data structures */
struct fn_data {
	char name1[BUF_LEN];
	char name2[BUF_LEN];
	int loc;
	struct fn_data *next;
};

typedef struct fn_data node;

node *head;
node *last;

/* Function states */
typedef enum { NotFunction, PosFunction, IsFunction } FNSTATETYPE;

/* functions for the list */
void insert_at_end(char fn_name1[], char fn_name2[], int fn_loc);
node *free_list(node *head);

/* display functions */
void print_intro(char source[]);
void print_fn_data(char source[], int fn_count, int prg_loc);
void print_summary(int fn_count, int total_fn_loc, int prg_loc);

#endif
