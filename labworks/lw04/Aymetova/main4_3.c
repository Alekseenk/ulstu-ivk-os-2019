#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



//����� pipe ������ ��� ����������� ���������������� ��� ��������-
//��� �����. ��� ������� ������������ ����� pipe ������������ �����, �����
//�������-�������� ����� ���������� � pipe, �����������, ��� �� �������
//�������-�������, � ����� ������ ���������� �� ������ pipe, �����������,
//��� �� ������� ����������� �������, �� ����� �� ���������� ��������, �
//������� �������-�������� �������� �� ����������� ����������, � ���-
//����-������� �� ������� �� ������. ��� ������������� ������ ������ pipe �
//���� ������������ ���������� ����������� �������� ������������� ���������.
int main() {
    printf("�������� �.�. ���. ���. 4\n");
	int fdParentToChild[2], fdChildToParent[2], result;
	size_t size;
	char resForChild[17], resForParent[15];
	pipe(fdParentToChild); //����� ��� ������ ���������, ������ ��������
	pipe(fdChildToParent); //����� ��� ������ ��������, ������ ���������
	result = fork();
	if (result > 0){
	 //������������ ������c
		close(fdParentToChild[0]);//��������� ����� ������ ���������
		close(fdChildToParent[1]);//��������� ����� ������ ��������
		printf("��������: ������ ������ ������...\n");
		size = write(fdParentToChild[1], "Hello, child!", 17);
		printf("��������: ����� ������ ������\n");
		printf("��������: �������� ��������� ������...\n");
		size = read(fdChildToParent[0], resForParent, 15);
		printf("��������: ����� ������ ���������� ������\n");
		printf("��������: ���������� ���������: %s\n", resForParent);
		close(fdParentToChild[1]);//��������� ����� ������ ��������
		close(fdChildToParent[0]);//��������� ����� ������ ��������
        printf("��������: ������ ������.\n");
	}
	else{
	 //�������� �������
	    close(fdParentToChild[1]);//��������� ����� ������ ���������
		close(fdChildToParent[0]);//��������� ����� ������ ���������
		printf("�������: ������ ������ ������... \n");
		size = read(fdParentToChild[0], resForChild, 17);
		printf("�������: ����� ������ ���������� ������ \n");
		printf("�������: ���������� ���������: %s\n", resForChild);
		printf("�������: ������ ������ ������...\n");
		size = write(fdChildToParent[1], "Hello, parent!", 15);
		printf("�������: ����� ������ ������\n");
		close(fdParentToChild[0]);//��������� ����� ������ ��������
		close(fdChildToParent[1]);//��������� ����� ������ ��������
		printf("�������: ������ ������. \n");
	}
	return 0;
}
