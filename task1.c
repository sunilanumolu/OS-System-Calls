#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc,char *argv[]){

	if(argc != 3){
                printf("Usage: ./a.out [input_filename] [output_filename]\n");
                return 0;
        }

	int fd1,fd2;
	off_t file_size;
	fd1 = open(argv[1], 0600);
	if(fd1 < 0){
                // open returns -1 if the file failed to open
                fprintf(stderr, "Failed to open file \"%s\"\n", argv[1]);
                exit(1);
        }
	
	char d[1000]= "Assignment/";
	strcat(d, argv[2]);
	
	if((mkdir("Assignment", 0700) < 0)){
		fprintf(stderr, "Failed to create the directory Assignment\n");
		exit(1);
	}
	
	fd2 = creat(d, 0600);
	if(fd2 < 0){
                // creat returns -1 if the file failed to create
                fprintf(stderr, "Failed to create file \"%s\"\n", argv[2]);
                exit(1);
        }

	file_size = lseek(fd1, (off_t) 0, SEEK_END);
	//printf("Input file size is %lu\n",file_size);
	
	int i,j,k,n;
	int div= file_size/1000;
	int rem= file_size%1000;
	char b;
	char buff1[1000];

	if(rem > 0){
		for(j= file_size-1;j>=div*1000;j--){
			lseek(fd1,(off_t) j,SEEK_SET);
			read(fd1,&b,1);
			if(b >= 97 && b <= 122){
	                        b= b - 32;
        	        }

                	else if(b >=65 && b <= 90){
                        	b= b + 32;
                	}
			write(fd2,&b,1);
		}
	}

	if(div > 0){
		for(i=(div-1)*1000;i>=0;i=i-1000){
			lseek(fd1,(off_t) i,SEEK_SET);
                        read(fd1,&buff1,1000);
			char buff2[1001];
			for(k=0;k<1000;k++){
			buff2[k]=buff1[999-k];
                        if(buff2[k] >= 97 && buff2[k] <= 122){
                                buff2[k]= buff2[k] - 32;
                        }

                        else if(buff2[k] >=65 && buff2[k] <= 90){
                                buff2[k]= buff2[k] + 32;
                        }
			}
			buff2[1000]='\0';
                        write(fd2,&buff2,1000);
		}
	}
	
	chmod("Assignment",0600);
	close(fd1);
	close(fd2);	 
	return 0;
}
