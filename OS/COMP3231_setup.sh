#!/bin/bash

## Config

RED='\033[0;31m'
Green='\033[0;32m'
NC='\033[0m' # No Color

#####################################################
#   Setup Script For COMP3231 - Operating Systems   #
#####################################################

mkdir Tools/ && cd Tools/ # create tools dir

printf "\n${Green}Downloading OS Files ...${NC}\n \n"

wget http://www.cse.unsw.edu.au/~cs3231/os161-files/os161-utils_2.0.8-3.deb

sudo dpkg -i os161-utils_2.0.8-3.deb

sudo apt-get install build-essential
sudo apt-get install python

printf "\n${Green}Running Installation Test: $ os161-gcc${NC}\n"

printf "\n==============================================\n"

os161-gcc

printf "\n==============================================\n"

echo "Produced Error Msg should match: "

printf "\n==============================================\n"

printf "${RED} os161-gcc: fatal error: no input files\n"
printf "${RED} compilation terminated.\n"

printf "${NC}\n==============================================\n"


printf "\n${Green}Done 🔥\n\n"