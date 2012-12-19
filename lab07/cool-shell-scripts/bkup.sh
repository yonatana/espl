#!/bin/sh

# randomquote - given a one-line-per-entry datafile, this 
#   script will randomly pick one and display it. Best used
#   as an SSI call within a Web page.

num=$2
fName=$1
while [ $num != 1 ] ; do #
	      if [ -r $1.$num ] ; then	#if file vertion exists
	      cp  $1.$(( $num -1 )) $1.$num #copy file.(num-1) to file.num 
	  fi
    num="$(( $num- 1 ))"
  done
  cp $1 $1.1
exit 0