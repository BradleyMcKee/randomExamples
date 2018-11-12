#!/bin/sh
for file in "$@";
do
    if file "$file" | grep -q "ASCII text, with CRLF"; then
	echo "converting $file"
	dos2unix "$file"

fi
done

