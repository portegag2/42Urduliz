int main_0(int argc)
{
    int ejercicio;

    // Si no se pasa argumento, usar valor por defecto
    if (argc == 1)
    {
        ejercicio = 1;  // Valor por defecto
        printf("Sin argumentos, ejecutando ejercicio %d por defecto\n", ejercicio);
    }

    // Resto del código igual...
    switch (ejercicio)
    {
        case 1:
            printf("=== Ejercicio 1 ===\n");
            main00();
            break;

        case 2:
            printf("=== Ejercicio 2 ===\n");
            main01();
            break;
        case 3:
            printf("=== Ejercicio 3 ===\n");
            main02();
            break;
        case 4:
            printf("=== Ejercicio 4 ===\n");
            main03();
            break;
        case 5:
            printf("=== Ejercicio 5 ===\n");
            main04();
            break;
		case 6:
            printf("=== Ejercicio 6 ===\n");
            main05();
            break;
		case 7:
            printf("=== Ejercicio 7 ===\n");
            main06();
            break;
        default:
            printf("Error: Ejercicio %d no existe\n", ejercicio);
            return (1);
    }

    return (0);
}
