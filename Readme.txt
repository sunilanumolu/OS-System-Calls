
Task1: For reversing the file we use lseek and we will find the size and then we will divide the data of the input file into certain packets and then we will reverse it using a for loop and also changing the Upper case letters to Lower case letters and vice-versa.

Task2: Using the command stat I go through man page for to check the permissions of a symlink ,file,directory,then we get to know whether the file,directory are created .Now to create a symlink we use command symlink.Now check whether the symlink created or not,then we use the logic for to check whether the output came in Task1 is correct or not.
please make sure the input given is in the format "input.txt",as in the answer I took the file descriptor as fd2=open("./input.txt",O_RDONLY);
Then we print all the permissions in order::(symlink permissions ,file permissions,directory permissions)as per given in the question. 
