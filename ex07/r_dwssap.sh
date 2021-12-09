#!/bin/bash
cat /etc/passwd | grep -v "^#" | awk 'NR%2==0' | head -n $FT_LINE2 | tail -n $(($FT_LINE2-FT_LINE1+1)) | cut -d ":" -f 1 | tr "\n" ", " | sed 's/_/._/' | sed 's/,_/ ,_/g' | sed 's/,$//' | sort -r | rev
