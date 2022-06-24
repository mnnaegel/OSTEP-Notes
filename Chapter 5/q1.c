#include <stdio.h>
#include <unistd.h>

int main(void) {
  int x = 0;
  int rc = fork();
  printf("%d, %d\n",rc,x);
  if (rc < 0) {
    printf("failed\n");
  } else if (rc == 0) {
    printf("child, before %d\n",x);
    x = 4;
    printf("child, after %d\n",x);
  } else {
    printf("parent, before %d\n",x);
    x = 5;
    printf("parent, after %d\n",x);
  }
}