#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
	Лаб.раб. ОС №4.1
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/
int main(){
    int fd[2];
    size_t size;
    char string[] = "Hello, world!";
    char resstring[14];
    int er = pipe(fd);
    if (er == 0) {
    /* Запись всей строки вместе с признаком конца строки в канал */
        printf("Начали запись строки...\n");
        size = write(fd[1], string, 14);
        printf("Записали строку...\n");
    /* Чтение строки из канала */
        printf("Начали чтение строки...\n");
        size = read(fd[0], resstring, 14);
        printf("Прочитали строку...\n");
    /* Печать прочитанной строки */
        printf("Прочитанная строка: \n");
        printf("%s\n",resstring);
    /* Закрыть входной и выходной потоки */
        close(fd[0]);
        close(fd[1]);
    } else {
        printf("Ошибка создания канала...\n");
    }

    return 0;
}
