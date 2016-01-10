norminette . | grep "Error" > diff.txt
echo "[0;36;40m-------------------------"
if [ -s diff.txt ]
then
	echo "[0;31;40m      [X]Faute de norme"
	echo "[0;36;40m-------------------------"
else
	echo "\033[32m      [✔]Norme OK"
	echo "[0;36;40m-------------------------"
fi
echo "[0;37;40mFonctions utilisees : "
nm $1 | grep "U _"
rm diff.txt
