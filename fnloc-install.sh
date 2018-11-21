#!/bin/bash
# fnloc-install.sh -- installs fnloc
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

echo "Installing fnloc..."
sudo cp -v fnloc /usr/local/bin/
sudo cp -v loc2file /usr/local/bin/
# Copy source code to /usr/local/src/fnloc/
echo "Copying program source code."
if [ ! -d /usr/local/src/fnloc/ ]; then
	sudo mkdir -p -v /usr/local/src/fnloc
fi
sudo cp -v fnloc.c /usr/local/src/fnloc/
# Copy documentation to /usr/local/doc/fnloc/
echo "Copying program documentation."
if [ ! -d /usr/local/doc/fnloc/ ]; then
	sudo mkdir -p -v /usr/local/doc/fnloc
fi
sudo cp -v changelog /usr/local/doc/fnloc/
sudo cp -v README /usr/local/doc/fnloc/
sudo cp -v fnloc_loc.txt /usr/local/doc/fnloc/
sudo cp -v LICENSE /usr/local/doc/fnloc/
sudo cp -v WARRANTY.txt /usr/local/doc/fnloc/
echo "fnloc installed."
exit
