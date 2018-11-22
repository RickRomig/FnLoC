#!/bin/bash
# loc2file - redirects fnloc lines of code data to a file
# Copyright (C) 2018  Richard Romig
# Email: rick.romig@gmail.com
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <https://www.gnu.org/licenses/>.

if  [ -z "$1" ]; then
	echo "Error: No argument. Expects C/C++ source file"
	echo "       with extension (.c or .cpp)"
	exit 1
fi

MYSCRIPT=$(basename $0)
CSOURCE=$1

# Test if file passed exists. If not, exit with error.
if [ ! -f "$CSOURCE" ]; then
	echo "Error: $CSOURCE not found."
	exit 1
fi

# Get file extension and check to see if it's valid. If not, exit with error.
EXT="${CSOURCE##*.}"
if [ "$EXT" != 'c' ] && [ "$EXT" != "cpp" ]; then
	echo "Invalid file extension!"
	exit 1
fi

# Get base filename and create filename for LOC data
BASEFILE=${CSOURCE%%.*}
LOCFILE="$BASEFILE.loc"

echo "$MYSCRIPT 2.1"
echo "Copyright 2018, Richard B. Romig"
echo "================================"
echo "Redirecting FnLoC output to $LOCFILE..."

# Process the files with fnloc
fnloc $CSOURCE | tee $LOCFILE

# Process header file if it exists
if [ -e "$BASEFILE.h" ]; then
	fnloc $BASEFILE.h | tail -n 4 | tee -a $LOCFILE
fi

echo "FnLoC data written to $LOCFILE."

exit 0
