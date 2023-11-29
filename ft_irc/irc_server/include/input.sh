#!/bin/bash

# Replace these values with your desired credentials
PASS="hola"
NICK="nue"
USER="nuevo"

# Connect to the server
echo -e "PASS $PASS\r\n" | nc localhost 6667
echo -e "NICK $NICK\r\n" | nc localhost 6667
echo -e "USER $USER * * :nuevo\r\n" | nc localhost 6667

# Add more commands if needed

# Sleep to give the server some time to process the commands
sleep 1

# You can add more commands here

# Close the connection
echo -e "QUIT\r\n" | nc localhost 6667

