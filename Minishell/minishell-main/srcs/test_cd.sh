# MINISHELL-TESTER

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

# Compile and set executable rights
make -C ../ > /dev/null
cp ../minishell .
chmod 777 minishell

function rem_d()
{
	FILE=d
	if [ -d "$FILE" ]; then
	    $(chmod 777 d; rm -rf d/)
	fi
}


# function exec_test()
# {
# 	TEST1=$(./minishell -c "$@" 2>&1)
# 	ES_1=$?
# 	TEST2=$(echo $@ "; exit" | bash )
# 	ES_2=$?
# 	if [ "$TEST1" == "$TEST2" ] && [ "$ES_1" == "$ES_2" ]; then
# 		printf " $BOLDGREEN%s$RESET" "✓ "
# 	else
# 		printf " $BOLDRED%s$RESET" "✗ "
# 	fi
# 	printf "$CYAN \"$@\" $RESET"
# 	if [ "$TEST1" != "$TEST2" ]; then
# 		echo
# 		echo
# 		printf $BOLDRED"Your output : \n%.20s\n$BOLDRED$TEST1\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
# 		printf $BOLDGREEN"Expected output : \n%.20s\n$BOLDGREEN$TEST2\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
# 	fi
# 	if [ "$ES_1" != "$ES_2" ]; then
# 		echo
# 		echo
# 		printf $BOLDRED"Your exit status : $BOLDRED$ES_1$RESET\n"
# 		printf $BOLDGREEN"Expected exit status : $BOLDGREEN$ES_2$RESET\n"
# 	fi
# 	echo
# 	sleep 0.1
# }

function exec_test()
{
	TEST1=$(./minishell -c "$@" 2>&1)
	ES_1=$?
	TEST2=$(bash -c "$@" 2>&1)
	ES_2=$?
	if [[ "$TEST2" == *"$TEST1"* ]] && [ "$ES_1" == "$ES_2" ]; then
		printf " $BOLDGREEN%s$RESET" "✓ "
	else
		printf " $BOLDRED%s$RESET" "✗ "
	fi
	printf "$CYAN \"$@\" $RESET"
	#if [[ "$TEST1" != "$TEST2" ]]; then
	if [[ "$TEST2" != *"$TEST1"* ]]; then
		echo
		echo
		printf $BOLDRED"Your output : \n%.20s\n$BOLDRED$TEST1\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
		printf $BOLDGREEN"Expected output : \n%.20s\n$BOLDGREEN$TEST2\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
	fi

	if [ "$ES_1" != "$ES_2" ]; then
		echo
		echo
		printf $BOLDRED"Your exit status : $BOLDRED$ES_1$RESET\n"
		printf $BOLDGREEN"Expected exit status : $BOLDGREEN$ES_2$RESET\n"
	fi
	echo
	sleep 0.1
}

printf "$BOLDMAGENTA __  __ _____ _   _ _____  _____ _    _ ______ _      _      \n"
printf "|  \/  |_   _| \ | |_   _|/ ____| |  | |  ____| |    | |     \n"
printf "| \  / | | | |  \| | | | | (___ | |__| | |__  | |    | |     \n"
printf "| |\/| | | | | . \` | | |  \___ \|  __  |  __| | |    | |     \n"
printf "| |  | |_| |_| |\  |_| |_ ____) | |  | | |____| |____| |____ \n"
printf "|_|  |_|_____|_| \_|_____|_____/|_|  |_|______|______|______|\n$RESET"
echo

printf "$YELLOW TESTS CD\n\n$RESET"

printf "1.  "
exec_test 'cd'

printf "2.  "
exec_test 'cd .'

printf "3.  "
exec_test 'cd -'

printf "4.  "
exec_test 'cd ~'

printf "5.  "
exec_test 'cd $PWD'

printf "6.  "
exec_test 'cd $PWD hi'

printf "7.  "
exec_test 'cd 123123'

printf "8.  "
exec_test 'cd $OLDPWD'

printf "9.  "
exec_test 'cd libft'

printf "10. "
exec_test 'cd nada'

printf "11. "
exec_test 'cd ../..'

printf "12. "
exec_test 'cd ../../..'

printf "13. "
exec_test 'cd \'' '' '

printf "14. "
exec_test 'cd 'd' '

printf "15. "
exec_test 'cd /'

printf "16. "
exec_test 'cd //'

printf "17. "
exec_test 'cd ///'

printf "18. "
exec_test 'cd /home'

printf "19. "
exec_test 'cd //home'

printf "20. "
exec_test 'Cd .'

printf "21. "
exec_test 'cD .'

echo
