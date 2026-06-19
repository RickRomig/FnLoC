#!/usr/bin/env bash
###############################################################################
# Script Name  :  fnloc-install.sh
# Description  : Installs fnloc using source files
# Author       : Copyright (C) 2018 Richard Romig
# Email        : rick.romig@gmail.com | rick.romig@mymetronet.com
# Created      : 12 Apr 1998
# Last updated : 19 Jun 2026
# Comments     : Be sure the fnloc and lloc executable hinaries have been created,
#              : either from the repository or from soucc before running the script.
###############################################################################
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE. See the GNU General Public License for more details.
###############################################################################

copy_executables() {
	local -r repo_dir="$1"
	local -r binary_dir="/usr/local/bin"
	[[ -d "$binary_dir" ]] || sudo mkdir -p "$binary_dir"
	printf "Installing FnLoC...\n"
	sudo cp -v "$repo_dir/fnloc" "$repo_dir/lloc" "$repo_dir/loc2file.sh" "$binary_dir/"
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
	sudo cp -v "$repo_dir/*.md" "$docs_dir/"
	sudo cp -v "$repo_dir/WARRANTY" "$repo_dir/LICENSE" "$docs_dir/"
}

main() {
	local -r repo_dir="$PWD"
	if [[ ! -x fnloc || ! -x lloc ]]; then
		printf "\e[91mERROR:\e[0m One or both binary files are missing.\n"
		exit 1
	fi
	copy_executables "$repo_dir"
	copy_source_files "$repo_dir"
	copy_docs "$repo_dir"
	exit
}

main "$@"
