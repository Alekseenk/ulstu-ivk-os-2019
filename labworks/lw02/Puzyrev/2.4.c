#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    ///������������ ������ �2.4
     printf("������������ ������ �2.4 \n");
     printf("�������� ������� ��.�����-21 ������� �.�.");
     int fd = 0;///�������� ����������
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);///��������� ��������� ����, ���� ��� ���, �� �� ����� ������, ���� ������ ��� ������
     char * atxt = "TEXT IN MY FILE";
     write(fd,atxt, 16);///���������� ����� � ����
     close(fd);///��������
    return 0;
}
