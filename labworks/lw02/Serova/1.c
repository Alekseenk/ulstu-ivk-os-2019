#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    //������������ ������ �1
    //��������� ��������� �����-22 ������ �.�.
     printf("������������ ������ �1 \n");
     printf("��������� ��������� ��.�����-22 ������ �.�.");
     int fd = 0;//�������� ����������
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);//��������� ��������� ����, ���� ��� ���, �� �� ����� ������, ���� ������ ��� ������
     char * atxt = "TEXT FILE";
     write(fd,atxt, 9);//���������� ����� � ����
     close(fd);//��������
    return 0;
}
