Punteros:
    - Defino un puntero a un int como: int *ptr
    - Si quiero dar valor al puntero es: ptr = valor(que será una direccion de memoria)
    - Si quiero dar valor a ese espacio de memoria es: *ptr = 42 (y en esa memoria aparecerá el valor 42)
    - Si quiero recuperar el valor de memoria que tiene el puntero sería: echo ptr
    - Pero si quiero recuperar el valor contenido en esa memoria sería: echo *ptr
Estructura:
    - Para compilar todos los .c que estén en subcarpetas del main:
        - gcc -Wall -Wextra -Werror main.c ex*/*.c -o programa
Norminette:
    - Para pasar el norminette desde el directorio del proyecto y que repaso obvie los de "/primerosIntentos2 y el "main.c":
        - find . -type f \( -name "*.c" -o -name "*.h" \) \
    -not -path "./primerosIntentos/*" \
    -not -name "main.c" \
    -exec norminette {} +