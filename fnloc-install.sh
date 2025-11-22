#!/bin/bash
# fnloc-install.sh -- installs fnloc using source files
# Copyright (C) 2018 Richard Romig
# Email: rick.romig@gmail.com
# Updated: 22 Nov 2025
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

copy_executables() {
	local -r repo_dir="$1"
	local -r binary_dir="/usr/local/bin"
	local -r script_dir="$HOME/bin"
	[[ -d "$binary_dir" ]] || sudo mkdir -p "$binary_dir"
	[[ -d "$script_dir" ]] || mkdir -p "$script_dir"
	printf "Installing FnLoC...\n"
	sudo cp -v "$repo_dir/fnloc" "$repo_dir/lloc" "$binary_dir/"
	sudo cp -v "$repo_dir/*.sh" "$script_dir/"
}

copy_source_files() {
	local -r repo_dir="$1"
	local -r source_dir="/usr/local/src/fnloc"
	[[ -d "$source_dir" ]] || sudo mkdir -p -v "$source_dir"
	printf "Copying program source code files...\n"
	sudo cp -v "$repo_dir/*.c" "$source_dir/"
	sudo cp -v "$repo_dir/*.h" "$source_dir/"
	sudo cp -v "$repo_dir/Makefile" "$source_dir/"
}

copy_docs() {
	local -r repo_dir="$1"
	local -r docs_dir="/usr/local/doc/fnloc"
	[[ -d "$docs_dir" ]] || sudo mkdir -p -v "$docs_dir"
	printf "Copying program documentation...\n"
	sudo cp -v "$repo_dir/changelog.md" "$repo_dir/README.md" "$docs_dir/"
	sudo cp -v "$repo_dir/SHA256sum.tx" "$docs_dir/"
	sudo cp -v "$repo_dir/WARRANTY" "$repo_dir/LICENSE" "$docs_dir/"
}

main() {
	local -r repo_dir="$HOME/Downloads/fnloc"
	copy_executables "$repo_dir"
	copy_source_files "$repo_dir"
	copy_docs "$repo_dir"
	exit
}

main "$@"
