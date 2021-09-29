
# 42 Make
Just messing with Makefiles.
Contributions are welcome

![preview](https://github.com/tmatis/cool-makefile/raw/master/preview.gif)

## Features

 - [x]  Cool header with important infos (git aware) ℹ️
 - [x]  Colored errors and outputs 📚
 - [x]  Beautiful loading bar  🕓
 - [x]  No relink 🙅‍♂️
 - [x]  Easy to configure and customize 🔨
 - [x] 42's Makefile norm ✨
 - [x] Recompiling needed files when header file is edited 🔥

## How to use ?
Execute:
```bash
bash <(curl -s https://raw.githubusercontent.com/tmatis/42make/master/setup.sh)
```
And follow instructions.

OR

Just download the Makefile and customize field yourself.
```bash
curl https://raw.githubusercontent.com/tmatis/42make/master/Makefile --output Makefile
```
You can customize sources files here :

![image](https://user-images.githubusercontent.com/54767855/135317248-5d0f9e68-470a-4e49-9c36-1f71823149e7.png)


## if you have tty error on workflows
```bash
#add NOVISU=1 as argument to your makefile:

make NOVISU=1 
```

## if you want to list all .cpp file
```bash
find . -type f | grep '.cpp' 
```
