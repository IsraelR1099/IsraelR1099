#!/bin/bash
echo -e "\033[32;1;13mEjecutando la norminette...\033[0m"
norminette -R CheckForbiddenSourceHeader $1
