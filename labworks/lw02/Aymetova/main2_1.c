#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
printf("������������ ������ 2. �������� �.�. �����-21\n");
int fd = 0;
fd = open("txt4.dat", O_CREAT|O_RDWR, 777);
ftruncate(fd, 1000*sizeof(int));///���������� ����� �����
int * ptr = (int *) mmap(NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0);///���� ���������� �� ������ � �� �����
if (ptr == MAP_FAILED) {
printf("��������� ������\n");
exit(1);
}
close(fd);
int * tmpptr = ptr;
///��������� ����� ����� �������
for (int i = 0; i < 1000; i++) {
(*tmpptr) = i;
tmpptr++;
}
///���������� ����������� ����� � ������, ���������� �� ���� � ����������� ������
munmap((void*)ptr, 1000*sizeof(int));

return 0;
}
