#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[]){
printf("�������� �.�. ���-21 ��� 3\n");
execle("/bin/cat", "/bin/cat", "main.c", envp);
return 0;

}
