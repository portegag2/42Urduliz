#include "index_components.h"

void show_usage(void)
{
    ft_putstr("Uso: ./programa [leccion] [ejercicio]\n");
    ft_putstr("Ejemplo: ./programa 0 0  (ejecuta C-00 ex00)\n");
    ft_putstr("         ./programa 1 3  (ejecuta C-01 ex03)\n");
}

void execute_exercise(int lesson, int exercise)
{
    if (lesson == 0)
    {
        if (exercise == 0) c00_ex00();
        else if (exercise == 1) c00_ex01();
        else if (exercise == 2) c00_ex02();
        else if (exercise == 3) c00_ex03();
        else if (exercise == 4) c00_ex04();
        else if (exercise == 5) c00_ex05();
        else if (exercise == 6) c00_ex06();
        else if (exercise == 7) c00_ex07();
        else
        {
            ft_putstr("Error: ejercicio no encontrado en C-00\n");
            return;
        }
    }
    else if (lesson == 1)
    {
        if (exercise == 0) c01_ex00();
        else if (exercise == 1) c01_ex01();
        else if (exercise == 2) c01_ex02();
        else if (exercise == 3) c01_ex03();
        else if (exercise == 4) c01_ex04();
        else if (exercise == 5) c01_ex05();
        else if (exercise == 6) c01_ex06();
        else
        {
            ft_putstr("Error: ejercicio no encontrado en C-01\n");
            return;
        }
    }
    else if (lesson == 2)
    {
        if (exercise == 0) c02_ex00();
        else
        {
            ft_putstr("Error: ejercicio no encontrado en C-02\n");
            return;
        }
    }
    else
    {
        ft_putstr("Error: lección no encontrada\n");
        show_usage();
    }
}

int main(int argc, char **argv)
{
    int lesson;
    int exercise;

    if (argc != 3)
    {
        show_usage();
        return (1);
    }

    lesson = atoi(argv[1]);
    exercise = atoi(argv[2]);

    execute_exercise(lesson, exercise);

    return (0);
}
