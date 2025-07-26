#include "index_components.h"

void show_usage(void)
{
    ft_putstr("Uso: ./programa [leccion]\n");
    ft_putstr("Ejemplo: ./programa 0  (ejecuta main_00)\n");
    ft_putstr("         ./programa 1  (ejecuta main_01)\n");
}

int main(int argc, char **argv)
{
    int lesson;

    if (argc != 3)
    {
        show_usage();
        return (1);
    }

    lesson = atoi(argv[1]);

    if (lesson == 0)
        main_00(atoi(argv[2]));
    else if (lesson == 1)
        main_01(atoi(argv[2]));
    else if (lesson == 2)
        main_02(atoi(argv[2]));
    else if (lesson == 3)
        main_03(atoi(argv[2]));
    else
    {
        ft_putstr("Error: lección no encontrada\n");
        show_usage();
    }

    return (0);
}
