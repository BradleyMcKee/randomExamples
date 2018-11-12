#!/bin/sh
file="$1"
case $(file "$file") in
     *"ASCII text, with CRLF line terminators")
          echo "Windows ASCII" ;;
     * )
echo "Something else" ;;
esac
