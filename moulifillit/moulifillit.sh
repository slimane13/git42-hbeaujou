#!/bin/bash -e

gcc -o test_fillit *.c -L. -lft

timeout() {
	time=$1
	command="/bin/sh -c \"$2\""
	expect -c "set echo \"-noecho\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"
	if [ $? = 1 ] ; then
		echo ""
		echo "\033[37m		Timeout after ${time} seconds"
		echo ""
		echo "\033[31m------------------------------------------------"
	fi
}

echo ""
echo "\033[34m------------------ DEMARRAGE -------------------"
echo""
echo "\033[33m-------------------- N = 1 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 1 > sample11.txt
        timeout 30 "./test_fillit sample11.txt > slim.txt"
        ./solution_fillit sample11.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
		echo ""
                echo "\033[31m		Votre grille pour 1 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 1 :"
                cat domi.txt
        else
		echo ""
                echo "\033[32m		[✔] Grille 1 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 2 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 2 > sample22.txt
        timeout 30 "./test_fillit sample22.txt > slim.txt"
        ./solution_fillit sample22.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
		echo ""
                echo "\033[31m		Votre grille pour 2 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 2 :"
                cat domi.txt
        else
		echo ""
                echo "\033[32m		[✔] Grille 2 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 3 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 3 > sample33.txt
        timeout 30 "./test_fillit sample33.txt > slim.txt"
        ./solution_fillit sample33.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
		echo ""
                echo "\033[31m		Votre grille pour 3 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 3 :"
                cat domi.txt
        else
		echo ""
                echo "\033[32m		[✔] Grille 3 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 4 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 4 > sample44.txt
        timeout 30 "./test_fillit sample44.txt > slim.txt"
        ./solution_fillit sample44.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
		echo ""
                echo "\033[31m		Votre grille pour 4 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 4 :"
                cat domi.txt
        else
		echo ""
                echo "\033[32m		[✔] Grille 4 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 5 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 5 > sample55.txt
        timeout 30 "./test_fillit sample55.txt > slim.txt"
        ./solution_fillit sample55.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
		echo ""
                echo "\033[31m		Votre grille pour 5 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 5 :"
                cat domi.txt
        else
		echo ""
		echo "\033[32m		[✔] Grille 5 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 6 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 6 > sample66.txt
	timeout 30 "./test_fillit sample66.txt > slim.txt"
	./solution_fillit sample66.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
                echo "\033[31m		Votre grille pour 6 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 6 :"
                cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 6 bonne"
                echo ""
	fi
done

echo "\033[33m-------------------- N = 7 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 7 > sample77.txt
        timeout 30 "./test_fillit sample77.txt > slim.txt"
        ./solution_fillit sample77.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
                echo ""
                echo "\033[31m		Votre grille pour 7 :"
                cat slim.txt
                echo ""
                echo "\033[31m	  	  Solution pour 7 :"
                cat domi.txt
        else
                echo ""
                echo "\033[32m		[✔] Grille 7 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 8 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 8 > sample88.txt
        timeout 30 "./test_fillit sample88.txt > slim.txt"
        ./solution_fillit sample88.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
                echo ""
                echo "\033[31m		Votre grille pour 8 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 8 :"
                cat domi.txt
        else
                echo ""
                echo "\033[32m		[✔] Grille 8 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 9 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 9 > sample99.txt
        timeout 30 "./test_fillit sample99.txt > slim.txt"
        ./solution_fillit sample99.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
                echo ""
                echo "\033[31m		Votre grille pour 9 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 9 :"
                cat domi.txt
        else
                echo ""
                echo "\033[32m		[✔] Grille 9 bonne"
                echo ""
        fi
done

echo "\033[33m-------------------- N = 10 ---------------------"

for i in 'seq 1 50'
do
        python map_gen.py 10 > sample1010.txt
        timeout 30 "./test_fillit sample1010.txt > slim.txt"
        ./solution_fillit sample1010.txt > domi.txt
        diff slim.txt domi.txt > diff.txt
        if [ -s diff.txt ]
        then
                echo ""
                echo "\033[31m		Votre grille pour 10 :"
                cat slim.txt
                echo ""
                echo "\033[31m		  Solution pour 10 :"
                cat domi.txt
        else
                echo ""
                echo "\033[32m		[✔] Grille 10 bonne"
                echo ""
        fi
done

rm domi.txt
rm slim.txt
rm sample*
