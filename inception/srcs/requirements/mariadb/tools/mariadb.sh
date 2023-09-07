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
handle_error()
{
	local exit_code=$1
	local error_message="$2"
	echo "Error: $error_message"
	exit $exit_code
}

mysql_install_db

/etc/init.d/mysql start

if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then
	echo "Database already exists"
else

	if mysql -sfu root <<EOSQL
	-- set root password
	UPDATE mysql.user SET Password=PASSWORD('$MYSQL_ROOT_PASSWORD') WHERE User='root';
	-- delete anonymous users
	DELETE FROM mysql.user WHERE User='';
	-- delete remote root capabilities
	DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost',
	'127.0.0.1', '::1');
	-- drop database 'test'
	DROP DATABASE IF EXISTS test;
	-- make sure there are lingering permissions to it
	DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
	-- create database for wordpress
	CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE DEFAULT CHARACTER SET utf8
	COLLATE utf8_unicode_ci;
	-- create user for wordpress
	CREATE USER ${WP_USER}'@'localhost' IDENTIFIED BY ${WP_PASSWORD};
	-- grant privileges to the new user
	GRANT ALL PRIVILEGES ON wordpress.* TO ${WP_USER}@'localhost' IDENTIFIED BY
	${WP_PASSWORD};
	-- make changes inmediately
	FLUSH PRIVILEGES;
EOSQL
	then
		echo "Database created successfully"
	else
		handle_error 1 "Error creating database"
	fi
fi

echo "MariaDB setup script finished."
/etc/init.d/mysql stop
exec "$@"
