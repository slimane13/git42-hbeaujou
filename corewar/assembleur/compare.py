

import os, sys

os.system("gcc *.c -I. libdodo.a")
os.system("./a.out " + sys.argv[1])
os.system("mv " + sys.argv[1].replace(".s", ".cor") + " " + sys.argv[1].replace(".s", "2.cor"))
os.system("../asm " + sys.argv[1])
os.system("diff " + sys.argv[1].replace(".s", ".cor") + " " + sys.argv[1].replace(".s", "2.cor") + " > diff_file")
if len(open("diff_file").read()) > 1:
	print "DIFFERENT"
else:
	print "NO DIFFERENT"
