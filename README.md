# 42 Make
Just messing with makefiles

![preview](https://github.com/tmatis/cool-makefile/raw/master/preview.gif)

## how to use ?

    wget https://raw.githubusercontent.com/tmatis/42make/master/Makefile

And configure these field:

![image](https://user-images.githubusercontent.com/54767855/134815283-4f02c62b-a05d-4c2a-a13e-febe11588512.png)

## if you have tty error on workflows
	add NOVISU=1 as argument to your makefile:

	make NOVISU=1 


## if you want to list all .cpp file

    find . -type f | grep '.cpp' 
