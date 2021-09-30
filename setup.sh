#!/bin/bash

# author: tmatis

# this script is used to setup the Makefile and project files

# colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
ORANGE='\033[0;33m'
BOLD='\033[1m'
UNDERLINE='\033[4m'
NC='\033[0m' # No Color
MAKEFILE_TEMPLATE="https://raw.githubusercontent.com/tmatis/42make/master/Makefile.template"

printf "$CYAN${BOLD}This script will help you setup the Makefile and project files.\n\n$NC"


printf "Enter the project's ${UNDERLINE}name$NC: \n $CYAN$BOLD>>> $NC";
read PROJECT_NAME;
# check if the project name is empty
if [ -z "$PROJECT_NAME" ]; then
	printf "[${RED}ERROR$NC] Project's name cannot be empty.\n";
	exit 1;
fi

printf "Enter the project's ${UNDERLINE}directory$NC: \
(default is ${BOLD}$PROJECT_NAME$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read PROJECT_DIR;
if [ -z "$PROJECT_DIR" ]; then
	PROJECT_DIR=$PROJECT_NAME;
fi

printf "Enter the project's ${UNDERLINE}author$NC: \
(default is ${BOLD}$USER$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read PROJECT_AUTHOR;
if [ -z "$PROJECT_AUTHOR" ]; then
	PROJECT_AUTHOR=$USER;
fi

printf "Enter the project's ${UNDERLINE}file extension$NC: \
(default is ${BOLD}.cpp$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read FILE_EXTENSION;
if [ -z "$FILE_EXTENSION" ]; then
	FILE_EXTENSION=".cpp";
fi

if [ $FILE_EXTENSION = ".c" ]; then
	DEFAULT_COMPILER="clang";
else
	DEFAULT_COMPILER="clang++";
fi

printf "Enter the project's ${UNDERLINE}compiler$NC: \
(default is ${BOLD}$DEFAULT_COMPILER$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read CC;
if [ -z "$CC" ]; then
	CC=$DEFAULT_COMPILER;
fi

if [ $CC = "clang++" ]; then
	DEFAULT_FLAGS="-Wall -Wextra -Werror -std=c++98"
elif [ $CC = "g++" ]; then
	DEFAULT_FLAGS="-Wall -Wextra -Werror -std=c++98"
else
	DEFAULT_FLAGS="-Wall -Wextra -Werror"
fi

printf "Enter the project's ${UNDERLINE}compilation flags$NC: \
(default is ${BOLD}$DEFAULT_FLAGS$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read FLAGS;
if [ -z "$FLAGS" ]; then
	FLAGS=$DEFAULT_FLAGS;
fi

printf "Enter the project's ${UNDERLINE}source directory$NC: \
(default is ${BOLD}src$NC leave empty if wanted) \n $CYAN$BOLD>>> $NC";
read SRC_DIR;
if [ -z "$SRC_DIR" ]; then
	SRC_DIR="src";
else
	SRC_DIR=`echo $SRC_DIR | sed 's/\.\///'`;
fi

printf "Enter the project's ${UNDERLINE}include directory$NC: \
(default is ${BOLD}src$NC leave empty if wanted or unused) \n $CYAN$BOLD>>> $NC";
read INC_DIR;
if [ -z "$INC_DIR" ]; then
	INC_DIR="src";
else
	INC_DIR=`echo $INC_DIR | sed 's/\.\///'`;
fi

printf "Do you want to create a repo with all these informations?\
 [y/n]\n\
$CYAN$BOLD>>> ${NC}name: ${BOLD}$PROJECT_NAME$NC\n\
$CYAN$BOLD>>> ${NC}directory: ${BOLD}$PROJECT_DIR$NC\n\
$CYAN$BOLD>>> ${NC}author: ${BOLD}$PROJECT_AUTHOR$NC\n\
$CYAN$BOLD>>> ${NC}file extension: ${BOLD}$FILE_EXTENSION$NC\n\
$CYAN$BOLD>>> ${NC}compiler: ${BOLD}$CC$NC\n\
$CYAN$BOLD>>> ${NC}compilation flags: ${BOLD}$FLAGS$NC\n\
$CYAN$BOLD>>> ${NC}source directory: ${BOLD}$SRC_DIR$NC\n\
$CYAN$BOLD>>> ${NC}include directory: ${BOLD}$INC_DIR$NC\n$NC
$CYAN$BOLD[y/n] >>> $NC";

read CREATE_REPO;
if [ -z "$CREATE_REPO" ]; then
	CREATE_REPO="y";
fi

DATE="$(date +%d\\/%m\\/%Y)"

if [ $CREATE_REPO = "y" ]; then
	mkdir -p $PROJECT_DIR;
	cd $PROJECT_DIR;
	mkdir -p $SRC_DIR;
	mkdir -p $INC_DIR;
	echo "int main(void) {}" > $SRC_DIR/main${FILE_EXTENSION};
	curl -s $MAKEFILE_TEMPLATE | sed 's/name_template/'"$PROJECT_NAME"'/g' \
							| sed 's/author_template/'"$PROJECT_AUTHOR"'/g' \
							| sed 's/file_extension_template/'"$FILE_EXTENSION"'/g' \
							| sed 's/cc_template/'"$CC"'/g' \
							| sed 's/cflags_template/'"$FLAGS"'/g' \
							| sed 's/src_template//g' \
							| sed 's/main_template/'"main.${FILE_EXTENSION}"'/g' \
							| sed 's/srcs_path_template/'"$SRC_DIR"'/g' \
							| sed 's/include_path_template/'"$INC_DIR"'/g' \
							| sed 's/date_template/'"$DATE"'/g' \
							> Makefile;
else
	printf "Exiting...\n";
	exit 0;
fi
