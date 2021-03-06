#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
//������������ ������ �5
//����:����������� ������ � ����������� �������.
///�������:������ ��������� ������ ��������� ������� ����������� ������ � ���������� ����
///����������� �������� �����, ������ ��������� ������ ����� ������ ����
///�����, �������� ��� �� ������ � ������� ������� ����������� ������ �� �������.
//��������� ��������� ������ �����-22: �������� �.�.
using namespace std;

int main()
{
    int cpp = open("/home/Anna/Documents/5/5_1/main.cpp", O_RDONLY);
    struct stat st; // ��������� ���������� ��� ��������� ���������� � �����
    lstat("/home/Anna/Documents/5/5_1/main.cpp", &st); //���������� ���������� � ����� � ��������� ��������� st
    int sizeST = st.st_size;
    key_t key = ftok("/home/Anna/Documents", 1);//��������� �������� ����� �� ���� ����������� �������������� �������� ftok()
    int sh;
    if ((sh = shmget(key, sizeST+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0) //��� �������� ������� ����������� ������
    //� ������������ ������ ��� ������� �� ����� � ��� ������������ ������� ����������� ��������� ����� shmget()
    //��������� ����� shmget ������������ ��� ���������� �������� ������� � �������� ����������� ������ �, � ������ ��� ��������� ����������,
    //���������� ���������� System V IPC ��� ����� �������� (����� ��������������� �����,
    //���������� ��������������� ������� ������ �������������� ������� � �������������� � ���������� ��� ������ �������� � ���).
    {
        if(errno != EEXIST) // ���� ������ �� ����������� � ���, ��� ������� ��� �����������
        {
            cout<<"���������� ������� ����������� ������!"<<endl;
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                cout<<"���������� ����� ����������� ������!"<<endl;
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, sizeST+sizeof(int), IPC_CREAT|0777);//�������� ���������
        }
    }
    int* memory = (int*)shmat(sh, NULL, 0); // ����� ��������� ����������� ����������
        //�������� ������� ����������� ������ � �������� ������������ �������� ��������
    int* tmp = memory;
    *tmp = sizeST;
    tmp++;
    char * c = (char *)tmp;
    read(cpp, c, sizeST); // ����������� ���������� ������ �����
    close(cpp); // ��������� ���� ����� ���������
    shmdt(memory); // ����� ��������� ������������� ����������� ������,
    //������� ����� ��������� ������ ������ ��������� ������������, �������� �� ���� ��� ������� � ������� ���������� ������ shmdt().
    return 0;
}
