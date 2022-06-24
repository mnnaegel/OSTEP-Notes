#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
  char bf[20];
  int fd = open("sample.txt",O_RDWR);
  int n = read(fd,bf,19);
  bf[19] = '\0';
  int rc = fork();
  
  if (rc < 0) {
    printf("failed\n");
  } else if (rc == 0) {
    // parent
    char sl[] = "parent";
    write(fd,sl,strlen(sl)+1);
  } else {
    // child
    char sl[] = "child";
    write(fd,sl,strlen(sl)+1);
  }
}