#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>


int main()
{
    ///������������ ������ �2.5

  printf("������������ ������ �2.5 \n");
 printf("�������� ������� ��.�����-21 ������� �.�.");
DIR * fd;///n�� ������ DIR ������������ ����� ��������� ��������� ������, ����������� ����� ��������, ������� ��������� opendir
fd = opendir(".");///��������� ����� �������� � ��������� ��������� �� ��������� ���� DIR
struct dirent * d;///����������� ��������� ������, ����������� ���� ������ � ����������
int i = 50;
while(fd && i-- > 0)///���������� ����������� ��������,
  {
   d = readdir(fd);
     if (d!=NULL)
	    printf("%s\n",d->d_name);
  }
closedir(fd);
return 0;
}
