#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>




int main(){
    printf("�������� �.�. ���. ���. 4\n");
	int fd[2], result;
	size_t size;
	pipe(fd);
	result = fork();
	if (result > 0){
	//������������ ������c
		int buf = 0;
		close(fd[0]);//��������� ����� ������
		while (1){
		 // �������� � ����������� ����� ���������� �� 1 ����� � �����
			buf++;
			size = write(fd[1],"", 1);
			printf("%d ���� \n ", buf); //������ ������ � ������������ ������������ �������
		}

		close(fd[1]);//��������� ����� ������
	}
	else{
	//�������� �������
		close(fd[1]);//��������� ����� ������
		while (1); // ������� ������ �� ������ �� ������
		close(fd[0]);//��������� ����� ������
	}
	return 0;
}
