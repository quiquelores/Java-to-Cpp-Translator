#!/bin/bash

# xtc - The eXTensible Compiler
# Copyright (C) 2009-2012 New York University
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
# USA.


# Finds specific percentiles from a data file.

pctls=".5 .9 1" # the default list of percentiles to find

while getopts :p: opt; do
    case $opt in
        p)
            pctls=$OPTARG
            ;;
        \?)
            echo "(`basename $0`)" "Invalid argument: -$OPTARG"
            ;;
        :)
            echo "(`basename $0`)" "-$OPTARG requires an argument."
            ;;
    esac
done

shift $(($OPTIND - 1))

if [[ $# -lt 3 ]]; then
    echo "USAGE: `basename $0` [-p \"pctls\"] file row_name col_number"
    echo ""
    echo "EXAMPLE: `basename $0` -p \".5 .8 .9 1\" performance.txt performance 3"
    exit
fi

file=$1
item=$2
field=$3

count=`cat $file | grep $item | wc -l`

echo "Out of $count rows."
for pctl in $pctls; do
    n=`perl -w -e "use POSIX; print ceil($count * $pctl), qq{\n}"`  # ugh
    echo "Percentile $pctl ($n rows)"
    echo `cat $file | grep $item | awk -v col=$field '{ print $col }' \
        | sort -n | head -n $n | tail -n 1`
    echo
done