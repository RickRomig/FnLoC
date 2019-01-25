#!/bin/bash
# fnloc-uninstall.sh -- uninstalls fnloc
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
#

if [ ! -e /usr/local/bin/fnloc ]
then
	echo "FnLoC not installed."
else
	echo "Uninstalling FnLoC..."
	sudo rm -v /usr/local/bin/fnloc
	sudo rm -v /usr/local/bin/lloc
fi

if [ ! -e /usr/local/bin/loc2file* ]
then
	echo "loc2file not installed."
else
	echo "Uninstalling loc2file..."
	sudo rm -v /usr/local/bin/loc2file*
fi

if [ ! -d /usr/local/src/fnloc/ && ! -d /usr/local/doc/fnloc/ ]
then
    exit
fi

# Remove source code files and directory
if [ -d /usr/local/src/fnloc/ ]
then
    pushd /usr/local/src/
    echo "Removing program source code."
	sudo rm -rfv fnloc/
	popd
fi

# Remove documentation files and directory
if [ -d /usr/local/doc/fnloc/ ]
then
    pushd /usr/local/doc/
    echo "Removing program documentation."
	sudo rm -rfv fnloc/
	popd
fi

echo "FnLoC uninstalled."
sleep 5

exit

