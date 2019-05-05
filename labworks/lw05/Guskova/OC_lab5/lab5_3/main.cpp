#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
//������������ ������ �5.3
//����������� ������ � ����������� �������
//��������� ��������� ��.�����-22 �������� �.�.
using namespace std;
int main()
{
    printf("������������ ������ �5.3\n");
    printf("����������� ������ � ����������� �������\n");
    printf("��������� ��������� ��.�����-22 �������� �.�.\n");
    printf("�������: ������ ��������� ������ ��������� ������� ����������� ������ � ���������� ����\
            ����������� �������� �����, ������ ��������� ������ ����� ������ ����\
            �����, �������� ��� �� ������ � ������� ������� ����������� ������ �� �������.\n");
    cout<<"��������� 1"<<endl;
    int cpp = open("/home/student/Documents/OC_lab5/lab5_3/main.cpp", O_RDONLY);
    struct stat st;
    lstat("/home/student/Documents/OC_lab5/lab5_3/main.cpp", &st);
    int s = st.st_size;
    key_t key = ftok("/home/student/Documents", 1);
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            cout<<"������!"<<endl;
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                cout<<"������!"<<endl;
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(cpp, c, s);
    close(cpp);
    shmdt(m);
    return 0;
}
