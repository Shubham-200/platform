echo "******************************************"
echo

fname=Makefile
if [ -f $fname ] 
then
	if (make clean)
	then
		echo "-----------------------Welcome-----------------------"
	fi
else
	echo "$fname not found in th current directory "
	exit 1
fi

echo "Enter the filename without extension: \c"
read fname

dmesg="dmesg -C"
insmod="insmod $fname.ko"


if [ -f $fname.c ]
then
	echo "-----$fname.c-----"
	if (make)
	then
		if [ -f $fname.ko ]
		then
			echo "-----$fname.ko found-----"
			echo "****************************************************"
			echo "Press 'y' to continue\nPress 'n' to exit: \c"
			read val
			while [ "$val" = "y" ]
			do
				echo "---------------- insmod --------------------------"
				if [ dmesg -a insmod ] 
				then
					echo "-----------------------------------------------------"
					echo "Press 'y' to continue\nPress 'n' to exit to exit the loop\nval: \c"
					read val
					echo "-----------------------------------------------------"
				fi
			done
			echo 
			echo "Press 'y' for the Application o/p\nPress 'n' to exit\nval: \c"
			read val
			echo "Enter the application name without extension: \c"
			read fname
			if [ -f $fname.c ]
			then
				echo "$fname.c found"
				echo "------------------------------------------------"
					
				gcc="gcc -o app_mpu $fname.c"
				app="./app_mpu"
					
				while [ "$val" = "y" ]
				do
					echo "----------------------------------------------------------"
					if (app)
					then
						echo "-----------------------------------------------------"
						echo "Press 'y' to continue\nPress 'n' to exit the loop\nval: \c"
						read val
					fi
				done
			else
				echo "$fname.c is not found "
			fi
		else
			echo "$fname.ko not found "	
		fi
	elif (make clean)
	then
		echo "------------------cleaned------------------------------"
	fi			
else
	echo "$fname.c found "
fi


