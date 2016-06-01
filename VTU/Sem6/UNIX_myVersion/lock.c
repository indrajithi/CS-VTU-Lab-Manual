 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
 int main(int argc,char *argv[])
 {
        int fd;
        char buffer[255];
        struct flock fvar;
        if(argc==1)
        {
                printf("usage: %s filename\n",argv[0]);
                return -1;
        }
        if((fd=open(argv[1],O_RDWR))==-1)
        {
                perror("open");
                exit(1);
        }
        fvar.l_type=F_WRLCK;                 // type of lock
        fvar.l_whence=SEEK_END;              // relative to the end of the file
        fvar.l_start=SEEK_END-100;           // where to start
        fvar.l_len=100;                      // number of bytes to lock

        printf("press enter to set lock\n");
        getchar();
        printf("trying to get lock..\n");
        if((fcntl(fd,F_SETLK,&fvar))==-1)    // -1 if file already locked
        {     fcntl(fd,F_GETLK,&fvar);
              printf("\nFile already locked by process (pid):    \t%d\n",fvar.l_pid);        
              return -1;        
        }
        printf("locked\n");

        if((lseek(fd,SEEK_END-50,SEEK_END))==-1)
        {
                perror("lseek");
                exit(1);
        }

        if((read(fd,buffer,50))==-1)
        {
                perror("read");
                exit(1);
        }
        printf("data read from file..\n");
        puts(buffer);

        printf("press enter to release lock\n");
        getchar();
        fvar.l_type = F_UNLCK;          
        fvar.l_whence = SEEK_SET;      //relative to the begining of the file  
        fvar.l_start = 0;               
        fvar.l_len = 0;

        if((fcntl(fd,F_UNLCK,&fvar))==-1)
        {
                perror("fcntl");
                exit(0);
        }

       
         printf("Unlocked\n");
        close(fd);
        return 0;
 }
