#!/bin/bash
# A 'grep -n' compatible vi wrapper that lets you open
# a file at a given line number.
# e.g. $ vi file.ext:23

vi () {
	if [ ! -z "${_VI_WRAPPER_BIN}" ]; then
		local VI=${_VI_WRAPPER_BIN}
        elif [ -x /usr/bin/vim ]; then
                local VI=/usr/bin/vim
        elif [ -x /usr/bin/vi ]; then
                local VI=/usr/bin/vi
	else
		local VI=/bin/vi
        fi

        # file.ext ?23?
        local filename=$1
        local line_num=$2

	if [ ! -f "$filename" ]; then
		# file.ext:23
		local filename=$(echo $1 | sed 's/:.*$//')
		local line_num=$(echo $1 | sed -r 's/^[^:]+:([0-9]+).*$/\1/')
	fi

	if [ ! -f "$filename" ]; then
		# file.ext-23
		filename=$(echo $1 | sed -r 's/\-[0-9]+(\-|$).*$//')
		line_num=$(echo $1 | sed -r 's/^.*\-([0-9]+)(\-|$).*$/\1/')
	fi
	
	if [[ $line_num =~ ^[0-9]+$ ]] && [ -f "$filename" ]; then
		$VI $filename +$line_num ${_VI_WRAPPER_COMMANDS:--c ":set cursorline|:hi CursorLine cterm=NONE ctermbg=DarkGrey ctermfg=white guibg=red guifg=white"}
	else
		$VI $1
	fi
}
