#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("������������ ������ �2\n");
    printf("�������� ������� ������ �����-22 ������ �.�./n");
     int fd = 0;///�������� ����������
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);///����������� ��������� ����(���� ��� ���, ���������)(������ ��� ������)
     char * atxt = "TEXT FILE";
     write(fd,atxt, 9);///������������ ����� � ����
     close(fd);///�������� �����
    return 0;
}
