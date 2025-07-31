Punteros:
    - Defino un puntero a un int como: int *ptr
    - Si quiero dar valor al puntero es: ptr = valor(que será una direccion de memoria)
    - Si quiero dar valor a ese espacio de memoria es: *ptr = 42 (y en esa memoria aparecerá el valor 42)
    - Si quiero recuperar el valor de memoria que tiene el puntero sería: echo ptr
    - Pero si quiero recuperar el valor contenido en esa memoria sería: echo *ptr
    - MATRICES, matriz argumentos main:
        Si argv es la matriz de argumentos de main

        - **argv -> Hace referencia al contenido de argv[0][0]
        - *(*argv + 1) -> Hace referencia al contenido de argv[0][1]
        - *(*argv + 2) -> Hace referencia al contenido de argv[0][2]

        - **(argv + 1) -> Hace referencia al contenido de argv[1][0]
        - *(*(argv + 1)+1) -> Hace referencia al contenido de argv[1][1]

        - **(argv + 2) -> Hace referencia al contenido de argv[2][0]
        - *(*(argv +2)+1) -> Hace referencia al contenido de argv[2][1]

        - *argv -> Es el puntero de argv[0]
        - (*argv)+1 -> Es el puntero de argv[0][1]
        - *(argv + 1) -> Es el puntero de argv[1]
        - (*(argv +1))+1 -> Es el puntero de argv[1][1]
        - *(*(argv + 2)+3) -> Seria el contenido de arg[2][3]

        Duda: buscando el argv[2][3] el puntero sería *(argv + 2)+3, pero acceder al valor sería **(argv +2)+3?
Estructura:
    - Para compilar todos los .c que estén en subcarpetas del main:
        - gcc -Wall -Wextra -Werror main.c ex*/*.c -o programa
Norminette:
    - Para pasar el norminette desde el directorio del proyecto y que repaso obvie los de "/primerosIntentos2 y el "main.c":
        - find . -type f \( -name "*.c" -o -name "*.h" \) \
    -not -path "./primerosIntentos/*" \
    -not -name "main.c" \
    -exec norminette -R CheckForbiddenSourceHeader {} +


martin
rudvan
david
matej
ruben
nico
hamid
eneko
asall
jumill


