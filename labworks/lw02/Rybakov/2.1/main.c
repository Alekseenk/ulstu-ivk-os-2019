#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>


int main()
{
    printf("������������ ������ �2 , ����� 2_1. ���������� ������� �.�. ������� ������ �����-21\n");
    int fd = 0;
    fd = open("text2_1.dat", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 1000* sizeof(int));
    int*ptr = (int*) mmap(NULL,1000*sizeof(int), PROT_WRITE, MAP_SHARED,fd,0);
    close(fd);
    if(ptr == MAP_FAILED)
    {
        printf("MAP_FAILED");
        exit(2);
    }
    for (int i = 0; i<1000; i++)
    {
        *(ptr+i) = i;
    }
    munmap((void*)ptr, 1000*sizeof(int));
    return 0;
}
