##To test the program use ./run.sh, this script will run all test files inside /files, it will show all otputs with a spleep 1 delay && automatic removes the a.out!

#If you want to test one at a time:
*cc *.c -D BUFFER_SIZE=n;
*./a.out ./files/"file name"
