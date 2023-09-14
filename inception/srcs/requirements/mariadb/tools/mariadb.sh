#!bin/sh
# First we check if the database already exists, if so, we do not do anything.
# In the contrary case, we execute "mysql_secure_installation"
# The flags of mysql are: -s silen, -f keep going if there is an error and -u
# uses the user specified (in this case is the user root)
# After setting the configuration of "mysql_secure_installation", we create the
# database with utf8 which makes our database suitable for multilingual
# applications.
# utf8_unicode_ci means that our database is case-insensitive and
# accent-insensitive, which is suitable with diverse languages.
# Function to handle errors

service mysql start

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "Creating database..."
	mysql -u root --password=${MYSQL_ROOT_PASSWORD} -e "CREATE DATABASE $MYSQL_DATABASE DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;"
	mysql -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
	mysql -e "GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'
	IDENTIFIED BY '$MYSQL_PASSWORD' WITH GRANT OPTION;"
	mysql -e "FLUSH PRIVILEGES;"
	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
else
	echo "Database already exists"
fi

echo "MariaDB setup script finished."
mysqladmin -u root --password=${MYSQL_ROOT_PASSWORD} shutdown
mysqld
