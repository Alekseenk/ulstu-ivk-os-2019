#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("�������� �.�. ���. ���. 4\n");
	int fd;
	size_t size;
	char result[1024];
	printf("��������� FIFO �� ������...\n");
	fd = open("/home/student/new/fifo", O_RDONLY);
    //���� FIFO ����������� ������ ��� ������, � ���� O_NDELAY �� �����,
    //�� �������, ������������� ��������� �����, ����������� �� ��� ���, ����
    //�����-���� ������ ������� �� ������� FIFO �� ������.
    printf("������ ������...\n");
	char *s = result;// ����������� ������
	do {
		size = read(fd, s, 1);
		s++;
	} while (size != 0);//��������� �� ������ ������� ���� ��� �� ����������
	printf("������ ���������\n");
	printf("���������: %s\n", result);
	close(fd);

	return 0;
}
