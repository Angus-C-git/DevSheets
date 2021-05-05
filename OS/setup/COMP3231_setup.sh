#!/bin/bash

## Config

RED='\033[0;31m'
Green='\033[0;32m'
NC='\033[0m' # No Color

#####################################################
#   Setup Script For COMP3231 - Operating Systems   #
#####################################################
printf "\n${RED} Make sure this script runs inside the desired COMP3231' working dir ${NC}\n\n"

echo -e "Enter Your zID: "
read zid

printf "\n${Green}Downloading OS Source From Git ...${NC}\n \n"

git clone https://$zid@gitlab.cse.unsw.EDU.AU/COMP3231/21T1/$zid-asst0.git asst0-src

mkdir Tools/ && cd Tools/ # create tools dir

printf "\n${Green}Downloading Toolchains ... ${NC}\n \n"

wget http://www.cse.unsw.edu.au/~cs3231/os161-files/os161-utils_2.0.8-3.deb

sudo dpkg -i os161-utils_2.0.8-3.deb

sudo apt-get install build-essential
sudo apt-get install python

printf "\n${Green}Running Installation Test: $ os161-gcc ... ${NC}\n"

printf "\n==============================================\n"

os161-gcc

printf "\n==============================================\n"

echo "Produced Error Msg Should Match: "

printf "\n==============================================\n"

printf "${RED} os161-gcc: fatal error: no input files\n"
printf "${RED} compilation terminated.\n"

printf "${NC}\n==============================================\n"


printf "\n${Green}Building the Application Executables ...\n\n"

cd ..

#Working Dir Variable
WORKING_DIR=$(pwd)

echo ""
printf "${Green}Installing into $WORKING_DIR/cs3231/root ${NC}\n\n"
mkdir cs3231/

cd asst0-src
./configure --ostree=$WORKING_DIR/cs3231/root

bmake
bmake install

printf "\n"

printf "\n${Green}File System Should Now Be Shown Below ${NC}\n \n"

printf "\n==============================================\n"

ls $WORKING_DIR/cs3231/root

printf "\n==============================================\n"


printf "\n${Green}Building the OS/161 Kernel ... ${NC}\n\n"

cd $WORKING_DIR/asst0-src/kern/conf

./config ASST0

cd ../compile/ASST0

bmake depend
bmake && bmake install

printf "\n${Green}Kernel-ASST0 Should Now Be Listed ... ${NC}\n\n"

printf "\n==============================================\n"

ls $WORKING_DIR/cs3231/root

printf "\n==============================================\n"

printf "\n${Green}Running the OS/161 Kernel ... ${NC}\n\n"

# Ensure you are in the root directory of your OS
cd $WORKING_DIR/cs3231/root

wget http://cgi.cse.unsw.edu.au/~cs3231/21T1/assignments/asst0/sys161.conf

printf "\n${Green}RUN: | cd cs3231/root && sys161 kernel | to begin${NC}\n\n"

printf "\n${Green}Done 🔥\n\n"