/*
 * FILE
 *      lloc.h -- header file for lloc.c v1.1
 * NAME
 *      Copyright (C) 2019  Richard Romig
 * EMAIL
 *      rick.romig@gmail.com
 * DATE
 *      25 January 2019
 * DESCRIPTION:
 *      Header file for lloc.c
 *      Declares constants, global variables, enumberated types and functions.
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
#ifndef LLOC_H
#define LLOC_H

/* Maximum buffer length */
#define BUF_LEN 128

/* display function */
void printLoc(char source[], int loc);

#endif
