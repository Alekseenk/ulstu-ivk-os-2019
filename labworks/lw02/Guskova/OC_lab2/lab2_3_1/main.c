#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
//������������ ������ �2.3
//��������� ������ ��� ������ � �������, ������������� � ������
//��������� ��������� ��.�����-22 �������� �.�.
int main()
{
    /*struct A{
    double f;
    double f1;} *ptr, *tmpptr;*/
    printf("������������ ������ �2.3\n");
    printf("��������� ������ ��� ������ � �������, ������������� � ������\n");
    printf("��������� ��������� ��.�����-22 �������� �.�.\n");
    int fd = 0;//�������� ����������
    fd = open("/home/student/Desktop/lab2_3/lb111.dat", O_RDONLY, 777);//��������� ����
    if (fd < 0)
    {printf("error");
    exit(2);
    }
    int * ptr;//ptr - ��������� ����� ���������� ������� ������
    ptr = (int *)mmap(NULL, 1000*sizeof(int), PROT_READ, MAP_SHARED, fd, 0);//���������� ���� � ������ � �� �����
    close(fd);                                        //PROT_READ - ��������� ������ ������� ������ � ������
    int *tmpptr = ptr;                                        //MAP_SHARED - ��� ��������� � ����� ����� ���������
    for(int i = 1; i<=1000; i++)
    {
    printf("%d ",*tmpptr);
    tmpptr++;
    }

    return 0;
}
