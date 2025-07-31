
#include "../index_components.h"
//#include <stdio.h>
//#include <stdlib.h>


/**************    EJER 00  *************/
void run_test_03_00(char *s1, char *s2, int expected) {
    int result = ft_strcmp(s1, s2);
    int std_result = strcmp(s1, s2);

    // Verificación (signo del resultado)
    int ok = (result == 0 && expected == 0) ||
             (result * expected > 0 && result * std_result > 0);

    // Formato visual claro
    printf("Test: \"%s\" vs \"%s\" -> ", s1, s2);
    if (ok) {
        printf("\033[0;32m✅ OK\033[0m (ft: %2d | std: %2d)\n", result, std_result);
    } else {
        printf("\033[0;31m❌ KO\033[0m (ft: %2d | expected: ", result);
        if (expected < 0) printf(" <0");
        else if (expected > 0) printf(" >0");
        else printf("  0");
        printf(" | std: %2d)\n", std_result);
    }
}

void main_C3_00 (void)
{
	printf("\n=== Tests ft_strcmp ===\n\n");

    // ---- Casos Iguales ----
    printf("\033[1;36m[Iguales]\033[0m\n");
    run_test_03_00("hello", "hello", 0);
    run_test_03_00("", "", 0);

    // ---- s1 < s2 ----
    printf("\n\033[1;36m[s1 < s2]\033[0m\n");
    run_test_03_00("apple", "banana", -1);
    run_test_03_00("123", "1234", -1);
    run_test_03_00("Hello", "hello", -1);  // 'H' < 'h'

    // ---- s1 > s2 ----
    printf("\n\033[1;36m[s1 > s2]\033[0m\n");
    run_test_03_00("zebra", "apple", 1);
    run_test_03_00("1234", "123", 1);
    run_test_03_00("A", "a", -1);  // ASCII: 'A'(65) < 'a'(97)

    // ---- Caracteres Especiales ----
    printf("\n\033[1;36m[Especiales]\033[0m\n");
    run_test_03_00("!", " ", 1);      // '!' (33) > ' ' (32)
    run_test_03_00("\t", "\n", -1);   // '\t' (9) < '\n' (10)

    // ---- Casos Límite ----
    printf("\n\033[1;36m[Límite]\033[0m\n");
    run_test_03_00("hello", "hello world", -1);  // '\0' < ' '
    run_test_03_00("ab\0c", "ab\0d", 0);         // Se detiene en '\0'

    // [Caso específico para el error detectado]
    printf("\033[1;33m[Caso Especial: Diferentes terminaciones]\033[0m\n");
    run_test_03_00("abc\0def", "abc\0xyz", 0);  // Debería devolver 0 (se detiene en \0)

    //return 0;



}
/**************    FIN EJER 00  *************/

/**************    INI EJER 01  *************/
void run_test_03_01(char *s1, char *s2, unsigned int n, int expected) {
    int result = ft_strncmp(s1, s2, n);
    int std_result = strncmp(s1, s2, n);

    // Verificación (signo del resultado)
    int ok = (result == 0 && expected == 0) ||
             (result * expected > 0 && result * std_result > 0);

    // Formato visual claro
    printf("Test: \"%s\" vs \"%s\" (n=%u) -> ", s1, s2, n);
    if (ok) {
        printf("\033[0;32m✅ OK\033[0m (ft: %2d | std: %2d)\n", result, std_result);
    } else {
        printf("\033[0;31m❌ KO\033[0m (ft: %2d | expected: ", result);
        if (expected < 0) printf(" <0");
        else if (expected > 0) printf(" >0");
        else printf("  0");
        printf(" | std: %2d)\n", std_result);
    }
}

int main_C3_01(void) {
    printf("\n=== Tests ft_strncmp ===\n\n");

    // ---- Casos Iguales (n limita o no) ----
    printf("\033[1;36m[Iguales]\033[0m\n");
    run_test_03_01("hello", "hello", 5, 0);      // Compara todos los caracteres
    run_test_03_01("hello", "hello", 3, 0);      // Compara solo 3 chars (iguales)
    run_test_03_01("", "", 1, 0);                // Cadenas vacías

    // ---- s1 < s2 ----
    printf("\n\033[1;36m[s1 < s2]\033[0m\n");
    run_test_03_01("apple", "banana", 5, -1);    // 'a' < 'b'
    run_test_03_01("123", "1234", 4, -1);        // '\0' < '4'
    run_test_03_01("A", "a", 1, -1);             // 'A'(65) < 'a'(97)

    // ---- s1 > s2 ----
    printf("\n\033[1;36m[s1 > s2]\033[0m\n");
    run_test_03_01("zebra", "apple", 3, 1);      // 'z' > 'a'
    run_test_03_01("1234", "123", 4, 1);         // '4' > '\0'

    // ---- Comparación Parcial (n limita) ----
    printf("\n\033[1;36m[Límite n]\033[0m\n");
    run_test_03_01("hello", "world", 0, 0);      // n=0 → no compara
    run_test_03_01("abc", "def", 2, -1);         // Compara solo 2 chars ('a' < 'd')
    run_test_03_01("abc\0def", "abc\0xyz", 7, 0); // Se detiene en '\0'

    // ---- Caracteres Especiales ----
    printf("\n\033[1;36m[Especiales]\033[0m\n");
    run_test_03_01("\t\n", "\t\r", 2, -1);       // '\n'(10) < '\r'(13)
    run_test_03_01("!", " ", 1, 1);              // '!'(33) > ' '(32)

    // [Caso específico para el error detectado]
    printf("\033[1;33m[Caso Especial: Diferentes terminaciones con n limitado]\033[0m\n");
    run_test_03_01("abc\0def", "abc\0xyz", 5, 0);  // Debería devolver 0 (solo compara 5 chars, 

    return 0;
}
/**************    FIN EJER 01  *************/

/**************    INI EJER 02  *************/
void run_test_03_02(char *dest, char *src, char *expected) {
    // Copiamos 'dest' a un buffer para no modificar el original
    char buffer[1024];
    strcpy(buffer, dest);

    char *result = ft_strcat(buffer, src);
    int ok = strcmp(buffer, expected) == 0 && result == buffer;

    printf("Test: \"%s\" + \"%s\" -> ", dest, src);
    if (ok) {
        printf("\033[0;32m✅ OK\033[0m (\"%s\")\n", buffer);
    } else {
        printf("\033[0;31m❌ KO\033[0m (ft: \"%s\" | expected: \"%s\")\n", buffer, expected);
    }
}
void main_C3_02 (void)
{
	printf("\n=== Tests ft_strcat ===\n\n");

    // ---- Casos Normales ----
    printf("\033[1;36m[Normales]\033[0m\n");
    run_test_03_02("Hello", "World", "HelloWorld");
    run_test_03_02("123", "456", "123456");
    run_test_03_02("", "Empty", "Empty");       // 'dest' vacío
    run_test_03_02("NonEmpty", "", "NonEmpty"); // 'src' vacío

    // ---- Sobreescritura ----
    printf("\n\033[1;36m[Sobreescritura]\033[0m\n");
    char dest1[20] = "Overwrite";
    run_test_03_02(dest1, "Me", "OverwriteMe"); // Verifica que no se corrompa memoria

    // ---- Caracteres Especiales ----
    printf("\n\033[1;36m[Especiales]\033[0m\n");
    run_test_03_02("Line", "\nBreak", "Line\nBreak"); // Salto de línea
    run_test_03_02("Tab", "\tHere", "Tab\tHere");     // Tabulador

    // ---- Casos Límite ----
    printf("\n\033[1;36m[Límite]\033[0m\n");
    char dest2[10] = "Small";
    run_test_03_02(dest2, "Buffer", "SmallBuffer"); // ¡Ojo! Esto es inseguro (pero prueba el código)

    //return 0;

}

/**************   FIN EJER 02  *************/

/**************    INI EJER 03  *************/
void run_test_03_03(char *dest, char *src, unsigned int nb, char *expected) {
    // Copiamos 'dest' a un buffer para no modificar el original
    char buffer[1024];
    strcpy(buffer, dest);

    char *result = ft_strncat(buffer, src, nb);
    int ok = strcmp(buffer, expected) == 0 && result == buffer;

    printf("Test: \"%s\" + \"%s\" (nb=%u) -> ", dest, src, nb);
    if (ok) {
        printf("\033[0;32m✅ OK\033[0m (\"%s\")\n", buffer);
    } else {
        printf("\033[0;31m❌ KO\033[0m (ft: \"%s\" | expected: \"%s\")\n", buffer, expected);
    }
}

void main_C3_03 (void)
{
	printf("\n=== Tests ft_strncat ===\n\n");

    // ---- Casos Normales ----
    printf("\033[1;36m[Normales]\033[0m\n");
    run_test_03_03("Hello", "World", 5, "HelloWorld");  // nb = longitud de src
    run_test_03_03("123", "456", 2, "12345");          // nb < longitud de src
    run_test_03_03("", "Empty", 5, "Empty");           // 'dest' vacío
    run_test_03_03("NonEmpty", "", 3, "NonEmpty");     // 'src' vacío

    // ---- Límite de Caracteres (nb) ----
    printf("\n\033[1;36m[Límite nb]\033[0m\n");
    run_test_03_03("Partial", "Concatenation", 5, "PartialConca");  // nb corta src
    run_test_03_03("Test", "1234", 0, "Test");                     // nb = 0 (no copia nada)
    run_test_03_03("A", "BCDEF", 10, "ABCDEF");                    // nb > longitud de src

    // ---- Caracteres Especiales ----
    printf("\n\033[1;36m[Especiales]\033[0m\n");
    run_test_03_03("Line", "\nBreak", 3, "Line\nBr");              // Salto de línea + truncamiento
    run_test_03_03("Tab", "\tHere", 10, "Tab\tHere");              // Tabulador (nb suficiente)

    // ---- Casos Críticos ----
    printf("\n\033[1;36m[Críticos]\033[0m\n");
    char dest1[10] = "Small";
    run_test_03_03(dest1, "Buffer", 3, "SmallBuf");                // Buffer justo (¡cuidado con overflow!)

    char dest2[20] = "Safe";
    run_test_03_03(dest2, "Concatenate", 15, "SafeConcatenate");   // Buffer amplio

    //return 0;

}

/**************   FIN EJER 03  *************/

/**************   INI EJER 04  *************/

void run_test_03_04(char *str, char *to_find, char *expected) {
    char *result = ft_strstr(str, to_find);
    int ok = (result == NULL && expected == NULL) ||
             (result != NULL && expected != NULL && strcmp(result, expected) == 0);

    printf("Test: \"%s\" in \"%s\" -> ", to_find, str);
    if (ok) {
        printf("\033[0;32m✅ OK\033[0m (\"%s\")\n", result ? result : "NULL");
    } else {
        printf("\033[0;31m❌ KO\033[0m (ft: \"%s\" | expected: \"%s\")\n",
               result ? result : "NULL",
               expected ? expected : "NULL");
    }
}

void main_C3_04(void) {
    printf("\n=== Tests ft_strstr ===\n\n");

    // ---- Coincidencias Exactas ----
    printf("\033[1;36m[Coincidencias]\033[0m\n");
    run_test_03_04("Hello World", "World", "World");
    run_test_03_04("abcde", "bcd", "bcde");
    run_test_03_04("123 456 789", "456", "456 789");
    run_test_03_04("same", "same", "same");  // Coincidencia completa

    // ---- Sin Coincidencias ----
    printf("\n\033[1;36m[Sin Coincidencias]\033[0m\n");
    run_test_03_04("Hello", "xyz", NULL);
    run_test_03_04("abc", "abcd", NULL);     // to_find más largo
    run_test_03_04("", "a", NULL);           // str vacío

    // ---- Subcadenas Vacías ----
    printf("\n\033[1;36m[Subcadenas Vacías]\033[0m\n");
    run_test_03_04("Hello", "", "Hello");    // to_find vacío retorna str
    run_test_03_04("", "", "");              // Ambas vacías

    // ---- Casos Límite ----
    printf("\n\033[1;36m[Límite]\033[0m\n");
    run_test_03_04("aaa", "aa", "aaa");      // Primera ocurrencia
    run_test_03_04("aaabbb", "aab", "aabbb");// Tras solapamiento parcial
    run_test_03_04("abc\0def", "def", NULL); // No encuentra tras '\0'

    // ---- Caracteres Especiales ----
    printf("\n\033[1;36m[Especiales]\033[0m\n");
    run_test_03_04("a\\tb", "\\t", "\\tb");  // Busca tabulación escapada
    run_test_03_04("$@!%", "@!", "@!%");     // Caracteres no alfanuméricos

    //return 0;
}

/**************   FIN EJER 04  *************/

/**************   INI EJER 05  *************/

void run_test_03_05(char *dest, char *src, unsigned int size, unsigned int expected_ret, char *expected_dest) {
    // Buffer seguro para pruebas (evita overflow)
    char buffer[1024];
    strcpy(buffer, dest);
    //unsigned int original_dest_len = strlen(dest);
    //unsigned int src_len = strlen(src);

    // Ejecutar ft_strlcat
    unsigned int ret = ft_strlcat(buffer, src, size);

    // Verificar resultados
    int ok_ret = (ret == expected_ret);
    int ok_dest = (strcmp(buffer, expected_dest) == 0);

    printf("Test: \"%s\" + \"%s\" (size=%u) -> ", dest, src, size);
    if (ok_ret && ok_dest) {
        printf("\033[0;32m✅ OK\033[0m\n");
    } else {
        printf("\033[0;31m❌ KO\033[0m\n");
    }

    // Mostrar detalles
    printf("  - Return: ft=%u", ret);
    if (!ok_ret) printf(" (expected %u)", expected_ret);
    printf("\n  - Dest: \"%s\"", buffer);
    if (!ok_dest) printf(" (expected \"%s\")", expected_dest);
    printf("\n\n");
}

void main_C3_05(void) {
    printf("\n=== Tests ft_strlcat ===\n\n");

    // ---- Casos Normales ----
    printf("\033[1;36m[Normales]\033[0m\n");
    char dest1[20] = "Hello";
    run_test_03_05(dest1, "World", 11, 10, "HelloWorld");  // Size suficiente

    char dest2[10] = "123";
    run_test_03_05(dest2, "456", 6, 6, "12345");          // Size justo (trunca)

    // ---- Size Insuficiente ----
    printf("\033[1;36m[Size Insuficiente]\033[0m\n");
    char dest3[5] = "A";
    run_test_03_05(dest3, "BCDE", 5, 5, "ABCD");          // Size=5 (A + BCD + \0)

    char dest4[5] = "";
    run_test_03_05(dest4, "1234", 5, 4, "1234");          // Dest vacío

    // ---- Casos Límite ----
    printf("\033[1;36m[Límite]\033[0m\n");
    char dest5[10] = "Test";
    run_test_03_05(dest5, "", 10, 4, "Test");             // Src vacío

    char dest6[3] = "A";
    run_test_03_05(dest6, "B", 1, 2, "A");                // Size=1 (no cabe nada)

    // ---- Caracteres Especiales ----
    printf("\033[1;36m[Especiales]\033[0m\n");
    char dest7[20] = "Line";
    run_test_03_05(dest7, "\nBreak", 20, 10, "Line\nBreak"); // Con salto de línea

    //return 0;
}

/**************   FIN EJER 05  *************/

int main_03(int argc)
{
       // Resto del código igual...
    switch (argc)
    {
        case 0:
            printf("=== Ejercicio 0 ===\n");
            main_C3_00();
            break;

        case 1:
            printf("=== Ejercicio 1 ===\n");
            main_C3_01();
            break;
        case 2:
            printf("=== Ejercicio 2 ===\n");
            main_C3_02();
            break;
        case 3:
            printf("=== Ejercicio 3 ===\n");
            main_C3_03();
            break;
        case 4:
            printf("=== Ejercicio 4 ===\n");
            main_C3_04();
            break;
		case 5:
            printf("=== Ejercicio 5 ===\n");
            main_C3_05();
            break;
        default:
            printf("Error: Ejercicio %d no existe\n", argc);
            return (1);
    }

    return (0);
}

