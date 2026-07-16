#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
int main()
{
    int fd;
    char buffer[100];
    struct stat fileinfo;
    DIR *dir;
    struct dirent*entry;
    /*
    PART 1:
    creat and write data into a file using open() and write()
    */
   printf("\n---Creating and Writing File ---\n");
   fd= open("student.txt",O_CREAT |O_WRONLY,0644);
   if(fd<0)
   {
    print("file creation failed\n");
    return 1;
   }
   char data[]="Linux System Calls Experiment\n"
   "B.Sc Cyber Security Laboratory";
   write(fd,data,strlen(data));
   close(fd);
   printf("Data written successfully\n");
   /*
   PART 2;
   Read file contents using open() and read()
   */
  printf("\n---Reading File Content---\n");
  fd=open("student.txt",O_RDONLY);
  if(fd<0)
  {
    printf("File opening failed\n");
    return 1;
  }
  int bytes=read(fd,buffer,sizeof(buffer)-1);
  buffer[bytes]='\0';
  printf("%s\n",buffer);
  close(fd);
  /*PART 3;
  Display file information using stat()
  */
 printf("\n---File Information---\n");
 if(stat("student.txt",&fileInfo)==0)
 {
    printf("File Size   :%1d bytes\n",fileInfo.st_size);
    printf("Number of Links:%1d\n",fileInfo.st_nlink);
    printf("Permissions  :%o\n",fileInfo.st_mode&0777);
 }
 else
 {
    printf("Unable to get file information\n");
 }
 

}