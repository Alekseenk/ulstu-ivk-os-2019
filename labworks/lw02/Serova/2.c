#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>


int main()
{
    //������������ ������ �1
  //��������� ��������� �����-22 ������ �.�.
  printf("������������ ������ �1 \n");
  printf("��������� ��������� ��.�����-22 ������ �.�.");
DIR * fd;
fd = opendir(".");
struct dirent * d;
int i = 50;
while(fd && i-- > 0)
  {
   d = readdir(fd);
     if (d!=NULL)
	    printf("%s\n",d->d_name);
  }
closedir(fd);
return 0;
}
