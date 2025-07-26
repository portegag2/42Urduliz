
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
void test_and_print0303(char *test_name, char *str) {
    printf("--- Prueba: %s ---\n", test_name);
    printf("String: \"%s\"\n", str);

    int result = ft_str_is_numeric(str);
    int expected = 1; // Valor esperado (se ajusta según el caso)

    // Calculamos el valor esperado automáticamente
    if (strlen(str) == 0) {
        expected = 1; // String vacío → 1
    } else {
        expected = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!(str[i] >= '0' && str[i] <= '9')) { // Verifica si NO es dígito
                expected = 0;
                break;
            }
        }
    }

    printf("Resultado: %d (Esperado: %d)\n", result, expected);
    printf("Estado: %s\n\n", (result == expected) ? "✅ CORRECTO" : "❌ INCORRECTO");
}
void main_C3_03 (void)
{
	// Caso 1: String vacío (debe devolver 1)
    test_and_print0303("String vacío", "");

    // Caso 2: Solo dígitos
    test_and_print0303("Solo dígitos", "123456");

    // Caso 3: Con letras (debe devolver 0)
    test_and_print0303("Con letras", "123abc");

    // Caso 4: Con símbolos (debe devolver 0)
    test_and_print0303("Con símbolos", "123!");

    // Caso 5: Con espacio (debe devolver 0)
    test_and_print0303("Con espacio", "1 2 3");

    // Caso 6: Número negativo (debe devolver 0, el '-' no es dígito)
    test_and_print0303("Número negativo", "-42");

    // Caso 7: Número decimal (debe devolver 0, el '.' no es dígito)
    test_and_print0303("Número decimal", "3.14");

    //return 0;

}

/**************   FIN EJER 03  *************/

/**************   INI EJER 04  *************/

void test_and_print0304(char *test_name, char *str) {
    printf("\n--- Prueba: %s ---\n", test_name);
    printf("String: \"%s\"\n", str);

    int result = ft_str_is_lowercase(str);
    int expected = 1; // Valor esperado (se ajustará según el caso)

    // Determinamos el valor esperado automáticamente
    if (strlen(str) == 0) {
        expected = 1; // String vacío → 1
    } else {
        expected = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!(str[i] >= 'a' && str[i] <= 'z')) { // Verifica si NO es minúscula
                expected = 0;
                break;
            }
        }
    }

    printf("Resultado: %d (Esperado: %d)\n", result, expected);
    printf("Estado: %s\n", (result == expected) ? "✅ CORRECTO" : "❌ INCORRECTO");
}

void main_C3_04(void) {
    // Caso 1: String vacío (debe devolver 1)
    test_and_print0304("String vacío", "");

    // Caso 2: Solo minúsculas válidas
    test_and_print0304("Solo minúsculas", "abcdef");

    // Caso 3: Con mayúsculas (debe devolver 0)
    test_and_print0304("Con mayúsculas", "abcDef");

    // Caso 4: Con números (debe devolver 0)
    test_and_print0304("Con números", "abc123");

    // Caso 5: Con símbolos (debe devolver 0)
    test_and_print0304("Con símbolos", "abc!");

    // Caso 6: Con espacio (debe devolver 0)
    test_and_print0304("Con espacio", "a b c");

    // Caso 7: Carácter Unicode (e.g., 'ñ'). Depende de tu implementación.
    // Si decides manejarlo, añade: test_and_print0304("Con 'ñ'", "añob");

    //return 0;
}

/**************   FIN EJER 04  *************/

/**************   INI EJER 05  *************/

void tes_and_print0305(char *test_name, char *str) {
     printf("\n--- Prueba: %s ---\n", test_name);
    printf("String: \"%s\"\n", str);

    int result = ft_str_is_uppercase(str);
    int expected = 1; // Valor esperado (se ajustará según el caso)

    // Determinamos el valor esperado automáticamente
    if (strlen(str) == 0) {
        expected = 1; // String vacío → 1
    } else {
        expected = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!(str[i] >= 'A' && str[i] <= 'Z')) { // Verifica si NO es mayúscula
                expected = 0;
                break;
            }
        }
    }

    printf("Resultado: %d (Esperado: %d)\n", result, expected);
    printf("Estado: %s\n", (result == expected) ? "✅ CORRECTO" : "❌ INCORRECTO");
}

void main_C3_05(void) {
    // Caso 1: String vacío (debe devolver 1)
    tes_and_print0305("String vacío", "");

    // Caso 2: Solo mayúsculas válidas
    tes_and_print0305("Solo mayúsculas", "ABCDEF");

    // Caso 3: Con minúsculas (debe devolver 0)
    tes_and_print0305("Con minúsculas", "ABCDef");

    // Caso 4: Con números (debe devolver 0)
    tes_and_print0305("Con números", "ABC123");

    // Caso 5: Con símbolos (debe devolver 0)
    tes_and_print0305("Con símbolos", "ABC!");

    // Caso 6: Con espacio (debe devolver 0)
    tes_and_print0305("Con espacio", "A B C");

    // Caso 7: Caracteres especiales (e.g., 'Ñ')
    // Si tu implementación lo requiere, añade: tes_and_print0305("Con 'Ñ'", "AÑO");

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

