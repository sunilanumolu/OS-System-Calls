#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

struct stat a;
int sy;
off_t file1,file2;
char b1,c1;
char buff[1001];
char buff1[1001];
off_t i,j;

int main(int argc,char *argv[]){
	char str[7]="sylink";
	int fd,fd1,fd2,div=0,rem=0,k;
	fd=open("./Assignment/Output.txt",O_RDONLY);
	write(STDOUT_FILENO,"Checking whether the directory has been created:",48);
	if(fd<0){
		write(STDOUT_FILENO,"NO",2);
		exit(-1);
	}
	else{
		if(stat("./Assignment",&a) == 0)
	    {
	        if(S_ISDIR(a.st_mode))
	        {
	            	write(STDOUT_FILENO,"YES",3);
	        }
	    }
	}

	write(STDOUT_FILENO,"\nChecking whether the file has been created:",44);
	if(fd<0){
		write(STDOUT_FILENO,"NO",2);
	}
	else{
		if(stat("./Assignment",&a) == 0)
	    {
	        if(S_ISDIR(a.st_mode))
	        {
	        	if(stat("./Assignment/Output.txt",&a)==0)
	            	write(STDOUT_FILENO,"YES",3);
	        }
	    }

	}

	write(STDOUT_FILENO,"\nChecking whether the symlink has been created:",47);
	if (fd < 0)
	{

		write(STDOUT_FILENO,"NO",2);
	        return 0;
	}
	else{
		sy=symlink("./Assignment/Output.txt",str);
		if(lstat(str,&a)==0){
			if(S_ISLNK(a.st_mode)){
				write(STDOUT_FILENO,"YES",3);
			}
		}
	}

	write(STDOUT_FILENO,"\nChecking whether file contents have been reversed and case-inverted:",69);
	if(fd>0){
		fd1=open("./Assignment/Output.txt",O_RDONLY);
		fd2=open("./input.txt",O_RDONLY);
		file1=lseek(fd1,(off_t)0,SEEK_END);
		file2=lseek(fd2,(off_t)0,SEEK_END);
		div=file1/1000;
		rem=file1%1000;
		if(rem>0){
			for(int j=file1-1,i=0;j>=div*1000,i<=rem-1;j--,i++){

		     	lseek(fd1,(off_t)j,SEEK_SET);
		     	read(fd1,&b1,1);
		     	lseek(fd2,(off_t)i,SEEK_SET);
		     	read(fd2,&c1,1);
		     	if(b1>=65&&b1<=90){
		     		b1+=32;
		     	}
		     	else if(b1>=97&&b1<=122){
		     		b1-=32;
		     	}
		     	if(b1!=c1){
		     		write(STDOUT_FILENO,"NO",2);
		     	
		     		break;	
		     	}	
		     	
	     	}
		}
		
		if(div>0){
			for(int p=(div-1)*1000,l=rem;p>=0,l<=file2-1;p-=1000,l+=1000){
		    
		     	lseek(fd1,(off_t)p ,SEEK_SET);
		     	read(fd1,buff1,1000);
		     	
		     	lseek(fd2,(off_t)l,SEEK_SET);
		     	read(fd2,buff,1000);
		     	char buff2[1001];
		     	
		     	for(k=0;k<1000;k++){
		     		buff2[k]=buff1[999-k];
		     		if(buff2[k]>=65&&buff2[k]<=90){
		     			buff2[k]=buff2[k]+32;
		     		}
		     		else if(buff2[k]>=97&&buff2[k]<=122){
		     			buff2[k]=buff2[k]-32;
		     		}
		     	}
		     	buff2[1000]='\0';
		     	for(int m=0;m<1000;m++){
		     		if(buff[m]!=buff2[m]){
		     			write(STDOUT_FILENO,"NO",2);
		     		}
		     
		     		
		     	}
		     	
		     }
		}
		write(STDOUT_FILENO,"YES",3);	
	}

	write(STDOUT_FILENO,"\n",1);
	write(STDOUT_FILENO,"\n",1);
	if(lstat(str,&a)==0){
		if(S_IRUSR&a.st_mode){
			write(STDOUT_FILENO,"User has read permission on file:YES",37);
		}
		else{
			write(STDOUT_FILENO,"User has read permission on file:NO",36);	
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWUSR&a.st_mode){
			write(STDOUT_FILENO,"User has write permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"User has write permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXUSR&a.st_mode){
			write(STDOUT_FILENO,"User has execute permission on file:YES",40);		
		}
		else{
			write(STDOUT_FILENO,"User has execute permission on file:NO",39);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IRGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Group has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has write permission on file:YES",39);
		}
		else{
			write(STDOUT_FILENO,"Group has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Group has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IROTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Owner has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has write permission on file:YES",39);	
		}
		else{
			write(STDOUT_FILENO,"Owner has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Owner has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);
	}
	write(STDOUT_FILENO,"\n",1);

	if(stat("./Assignment/Output.txt",&a)==0){
		if(S_IRUSR&a.st_mode){
			write(STDOUT_FILENO,"User has read permission on file:YES",37);
		}
		else{
			write(STDOUT_FILENO,"User has read permission on file:NO",36);	
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWUSR&a.st_mode){
			write(STDOUT_FILENO,"User has write permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"User has write permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXUSR&a.st_mode){
			write(STDOUT_FILENO,"User has execute permission on file:YES",40);		
		}
		else{
			write(STDOUT_FILENO,"User has execute permission on file:NO",39);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IRGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Group has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has write permission on file:YES",39);
		}
		else{
			write(STDOUT_FILENO,"Group has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Group has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IROTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Owner has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has write permission on file:YES",39);	
		}
		else{
			write(STDOUT_FILENO,"Owner has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Owner has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);

	}
	write(STDOUT_FILENO,"\n",1);

	if(stat("./Assignment",&a)==0){
		if(S_IRUSR&a.st_mode){
			write(STDOUT_FILENO,"User has read permission on file:YES",37);
		}
		else{
			write(STDOUT_FILENO,"User has read permission on file:NO",36);	
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWUSR&a.st_mode){
			write(STDOUT_FILENO,"User has write permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"User has write permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXUSR&a.st_mode){
			write(STDOUT_FILENO,"User has execute permission on file:YES",40);		
		}
		else{
			write(STDOUT_FILENO,"User has execute permission on file:NO",39);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IRGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Group has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has write permission on file:YES",39);
		}
		else{
			write(STDOUT_FILENO,"Group has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXGRP&a.st_mode){
			write(STDOUT_FILENO,"Group has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Group has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IROTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has read permission on file:YES",38);
		}
		else{
			write(STDOUT_FILENO,"Owner has read permission on file:NO",37);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IWOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has write permission on file:YES",39);	
		}
		else{
			write(STDOUT_FILENO,"Owner has write permission on file:NO",38);
		}
		write(STDOUT_FILENO,"\n",1);
		if(S_IXOTH&a.st_mode){
			write(STDOUT_FILENO,"Owner has execute permission on file:YES",41);
		}
		else{
			write(STDOUT_FILENO,"Owner has execute permission on file:NO",40);
		}
		write(STDOUT_FILENO,"\n",1);
	}
	write(STDOUT_FILENO,"\n",1);
	return 0;
}
