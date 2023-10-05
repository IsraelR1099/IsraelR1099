echo -e "\033[0;32m-------CONFIGURING ENVIRONMENT-------\033[0m"

printf "Enter the path to the directory where you want to store the data: "
printf "\nExample: /home/user/data\n"
read path


if [ ! -d "$path" ]; then
	echo -e "\033[0;31mThis directory does not exist. You must create it first.\033[0m"
	exit 1
fi

echo "$path" > srcs/requirements/tools/path.txt

cp srcs/requirements/tools/template.yml srcs/docker-compose.yml

#Replace path to data directory in docker-compose.yml
cat srcs/docker-compose.yml | sed "s+pathtodata+$path+g" > srcs/docker-compose.yml.tmp
mv srcs/docker-compose.yml.tmp srcs/docker-compose.yml
