#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
//������������ ������ �5.2
//����������� ������ � ����������� �������
//��������� ��������� ��.�����-22 �������� �.�.
int main()
{
    printf("������������ ������ �5.2\n");
    printf("����������� ������ � ����������� �������\n");
    printf("��������� ��������� ��.�����-22 �������� �.�.\n");
    printf("�������: � ����������� ������ ����������� ������ �� ���� ����� �����. ������ �������\
            ������� ������������ ��� ������� ��� ��������� 1, ������ ������� � ���\
            ��������� 2, ������ ������� � ��� ����� �������� ��������.\n");
    int *array; /* ��������� �� ����������� ������ */
    int shmid; /* IPC ���������� ��� ������� ����������� ������ */
    int nw = 1; /* ���� ������������� ������������� ��������� ������� */
    char pathname[] = "/home/student/Documents/4/4_1/output";
    key_t key; /* IPC ���� */
    /* ���������� IPC */
    if((key = ftok(pathname,0)) < 0)
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }
    /* �������� ����������� ������ */
    if((shmid = shmget(key, 3*sizeof(int),0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
    /* ������ ������ ��������*/
        if(errno != EEXIST)
        { /*������ ������*/
        printf("Can\'t create shared memory\n");
        exit(-1);
        }
        else
        { /* ������ ��� ���������� */
            if((shmid = shmget(key, 3*sizeof(int), 0)) < 0)
            {
            printf("Can\'t find shared memory\n");
            exit(-1);
            }
        nw = 0;
        }
    }
    /*����������� ����������� ������ � �������� ������������ ��������
    ��������. �������� �������� �� ��, ��� ��� ����������� ��������� �� ��-
    �� ��������������� �������� -1 � ��������� �� �����.*/
    if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1))
    {
    printf("Can't attach shared memory\n");
    exit(-1);
    }
    /* � ����������� �� �������� ����� new ���� �������������� ������, ��-
    �� ����������� ��������������� �������� */
    if(nw)
    {
        array[0] = 0;
        array[1] = 1;
        array[2] = 1;
    }
    else
        {
        array[1] += 1;
        array[2] += 1;
        }
    /* �������� ����� �������� ���������, ������� ����������� ������ ��
    ��������� ������������ �������� �������� � ��������� ������ */
    printf("Program 1 was spawn %d times,program 2 - %d times, total - %d times\n",array[0], array[1], array[2]);
    if(shmdt(array) < 0)
    {
    printf("Can't detach shared memory\n");
    exit(-1);
    }
    return 0;
}
