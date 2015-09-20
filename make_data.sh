#!/bin/bash

heihgt=`wc -l $1 |  awk '{print $1}'`
all_numb=`wc -w $1 | awk '{print $1}'`
let "width = all_numb  / heihgt"
answ="${heihgt} ${width}"

eval "sed -i '1s/^/${answ}\n/' $1"
