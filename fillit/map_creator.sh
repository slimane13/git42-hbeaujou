#!/bin/sh

rm -f sample.txt map.txt
touch sample.txt map.txt
python map_gen.py $1 > map.txt
./test map.txt $1 > sample.txt

