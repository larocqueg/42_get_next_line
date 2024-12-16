To test the program use ./run.sh, this script will run all test files inside ./files/, it will show all otputs with a spleep 1 delay && removes the a.out!

If you want to test one at a time:
cc *.c -D BUFFER_SIZE=n;
./a.out ./files/"file_name" (to test a file instide of ./files/);
./a.out "file_name" (if you want to test another file that is not inside ./files/).
