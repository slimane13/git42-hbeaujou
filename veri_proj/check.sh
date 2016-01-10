make fclean
make
make > maketest.txt
if [ -s maketest.txt ]
then
	diff maketest.txt "Nothing to do for all" > diff.txt
	if [ -s diff.txt ]
	then
		echo "[0;31;40m      [X]Recompile"
		echo "[0;36;40m-----------------------------------"
	fi
else
	echo "[0;32;40m      [✔]Ne recompile pas"
	echo "[0;36;40m-----------------------------------"
fi
norminette . | grep "Error" > diff.txt
echo "[0;36;40m-----------------------------------"
if [ -s diff.txt ]
then
	echo "[0;31;40m      [X]Faute de norme"
	echo "[0;36;40m-----------------------------------"
else
	echo "\033[32m      [✔]Norme OK"
	echo "[0;36;40m-----------------------------------"
fi
echo "[0;37;40mFonctions utilisees : "
nm $1 | grep "U _"
echo "[0;36;40m-----------------------------------"
echo "[0;37;40mNombre de lignes : "
cat $2/*.c | wc -l
echo ""
rm diff.txt
rm maketest.txt
