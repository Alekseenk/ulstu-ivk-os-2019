#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
//������������ ������ �5.4
//����������� ������ � ����������� �������
//��������� ��������� ��.�����-22 �������� �.�.
using namespace std;
int main()
{
    printf("������������ ������ �5.4\n");
    printf("����������� ������ � ����������� �������\n");
    printf("��������� ��������� ��.�����-22 �������� �.�.\n");
    printf("�������: ������ ��������� ������ ��������� ������� ����������� ������ � ���������� ����\
            ����������� �������� �����, ������ ��������� ������ ����� ������ ����\
            �����, �������� ��� �� ������ � ������� ������� ����������� ������ �� �������.\n");
    key_t key = ftok("/home/student/Documents", 1);
    int sh = shmget(key, sizeof(int), IPC_CREAT|0777);
    int* m = (int*)shmat(sh, NULL, 0);
    int length = *m;
    shmdt(m);
    sh = shmget(key, length+sizeof(int), IPC_CREAT|0777);
    m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    t++;
    char* c = (char *) t;
    char buff[length];
    for (int i = 0; i < length-1; i++)
    {
        buff[i] = *c;
        c++;
    }
    cout<<buff<<endl;
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
