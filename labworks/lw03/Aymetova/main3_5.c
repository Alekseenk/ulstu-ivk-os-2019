#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{printf("�������� �.�. ���-21 ��� 3\n");
// fork();
if (fork()==0)
execle("/bin/cat", "/bin/cat", "main.c", envp);//�������� envp �������� ���������� ���������, ������������� � ������������ ������� ��� ������� ������������.
//���������� �������������� ����� �� ��, ��� ����-������ � ������� main()
else printf("%s","���-�� ����� �� ���...");
return 0;
}
