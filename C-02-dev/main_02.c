
#include "../index_components.h"
//#include <stdio.h>
//#include <stdlib.h>


/**************    EJER 00  *************/
void run_test(char *test_name, char *src)
{
    // Búferes suficientemente grandes para la mayoría de las pruebas
    char dest_original[50];
    char dest_ft[50];

    // Limpiamos los búferes para asegurar que no hay datos residuales
    memset(dest_original, 'X', sizeof(dest_original) - 1);
    dest_original[sizeof(dest_original) - 1] = '\0';
    memset(dest_ft, 'X', sizeof(dest_ft) - 1);
    dest_ft[sizeof(dest_ft) - 1] = '\0';

    printf("--- Prueba: %s ---\n", test_name);
    printf("Fuente (src): \"%s\"\n", src);

    // --- Llamadas a las funciones ---
    char *ret_original = strcpy(dest_original, src);
    char *ret_ft = ft_strcpy(dest_ft, src);

    // --- Verificación ---
    printf("strcpy    (esperado): \"%s\"\n", dest_original);
    printf("ft_strcpy (tu func):  \"%s\"\n", dest_ft);
	printf("strcpy    (develto): \"%s\"\n", ret_original);
    printf("ft_strcpy (devuelto):  \"%s\"\n", ret_ft);

    // Comparar contenido de los búferes y valor de retorno
    int content_ok = strcmp(dest_original, dest_ft) == 0;
    int return_ok = (ret_ft == dest_ft);

    if (content_ok && return_ok) {
        printf("✅ Resultado: CORRECTO\n\n");
    } else {
        printf("❌ Resultado: INCORRECTO\n");
        if (!content_ok) {
            printf("   -> El contenido de 'dest' no coincide.\n");
        }
        if (!return_ok) {
            printf("   -> El valor de retorno no es el puntero a 'dest'.\n");
        }
        printf("\n");
    }

    char src2[] = "Esta es una cadena bastante mas larga que las demas. Y más de 60";
    char dest_std2[50] = {0};
    char dest_ft2[50] = {0};

    strcpy(dest_std2, src2);    // Debería fallar (buffer overflow)
    ft_strcpy(dest_ft2, src2);  // Debería fallar igual

    printf("strcpy   : %s\n", dest_std2);
    printf("ft_strcpy: %s\n", dest_ft2);
}

void main_C2_00 (void)
{
	// Caso 1: Cadena estándar
    run_test("Copia basica", "Hola mundo!");

    // Caso 2: Cadena vacía
    run_test("Cadena vacia", "");

    // Caso 3: Cadena con varios caracteres especiales y espacios
    run_test("Caracteres variados", "  Probando\tcon\n saltos!  ");

    // Caso 4: Una cadena larga
    run_test("Cadena larga", "Esta es una cadena bastante mas larga que las demas. Y más de 60");

    //return 0;



}
/**************    FIN EJER 00  *************/

/**************    INI EJER 01  *************/
void print_buffer(char *buf, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        if (buf[i] == '\0') printf("\\0");
        else printf("%c", buf[i]);
    }
    printf(" (");
    for (unsigned int i = 0; i < n; i++) {
        printf("%02X ", (unsigned char)buf[i]);
    }
    printf(")\n");
}

void test_and_print(char *test_name, char *src, unsigned int n) {
    char dest1[30];  // Para strncpy
    char dest2[30];  // Para ft_strncpy

    // Inicializamos con basura (no con puntos)
    memset(dest1, 0xAA, 30);  // 0xAA es un valor arbitrario para detectar basura
    memset(dest2, 0xAA, 30);

    printf("\n--- %s (n=%u, src=\"%s\") ---\n", test_name, n, src);

    // Llamadas a las funciones
    strncpy(dest1, src, n);
    ft_strncpy(dest2, src, n);

    // Mostramos resultados
    printf("strncpy (esperado): ");
    print_buffer(dest1, n);

    printf("ft_strncpy (tuyo):  ");
    print_buffer(dest2, n);

    // Comparamos SOLO los primeros n bytes (sin usar bool)
    int correct = (memcmp(dest1, dest2, n) == 0);
    printf("Resultado: %s\n", correct ? "✅ CORRECTO" : "❌ INCORRECTO");

    // Opcional: Mostrar bytes restantes para depuración
    if (!correct) {
        printf("\n--- Bytes adicionales (para depuración) ---\n");
        printf("strncpy: ");
        for (unsigned int i = n; i < 30; i++) printf("%02X ", (unsigned char)dest1[i]);
        printf("\nft_strncpy: ");
        for (unsigned int i = n; i < 30; i++) printf("%02X ", (unsigned char)dest2[i]);
        printf("\n");
    }
}

int main_C2_01(void) {
    // Caso 1: src más corto que n
    test_and_print("SRC < n", "hola", 7);

    // Caso 2: src más largo que n
    test_and_print("SRC > n", "esto es una prueba larga", 5);

    // Caso 3: src igual a n
    test_and_print("SRC == n", "exacto", 6);

    // Caso 4: n = 0
    test_and_print("n = 0", "nada", 0);

    // Caso 5: src vacío
    test_and_print("SRC vacío", "", 5);

    return 0;
}
/**************    FIN EJER 01  *************/

/**************    INI EJER 02  *************/
void test_and_print0202(char *test_name, char *str) {
    printf("--- Prueba: %s ---\n", test_name);
    printf("String: \"%s\"\n", str);

    int result = ft_str_is_alpha(str);
    int expected = 1; // Valor esperado (ajustar según el caso)

    // Determinamos el valor esperado dinámicamente
    if (strlen(str) == 0) {
        expected = 1; // Caso string vacío
    } else {
        expected = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
                expected = 0;
                break;
            }
        }
    }

    printf("Resultado: %d (Esperado: %d)\n", result, expected);
    printf("Estado: %s\n\n", (result == expected) ? "✅ CORRECTO" : "❌ INCORRECTO");
}
void main_C2_02 (void)
{
	// Caso 1: String vacío (debe devolver 1)
    test_and_print0202("String vacío", "");

    // Caso 2: Solo letras mayúsculas
    test_and_print0202("Solo mayúsculas", "ABCDEF");

    // Caso 3: Solo letras minúsculas
    test_and_print0202("Solo minúsculas", "abcdef");

    // Caso 4: Letras mixtas (mayúsculas y minúsculas)
    test_and_print0202("Letras mixtas", "AbCdEf");

    // Caso 5: Con números (debe devolver 0)
    test_and_print0202("Con números", "abc123");

    // Caso 6: Con símbolos (debe devolver 0)
    test_and_print0202("Con símbolos", "abc!");

    // Caso 7: Con espacio (debe devolver 0)
    test_and_print0202("Con espacio", "a b c");

    //return 0;

}

/**************   FIN EJER 02  *************/

/**************    INI EJER 03  *************/
void test_and_print0203(char *test_name, char *str) {
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
void main_C2_03 (void)
{
	// Caso 1: String vacío (debe devolver 1)
    test_and_print0203("String vacío", "");

    // Caso 2: Solo dígitos
    test_and_print0203("Solo dígitos", "123456");

    // Caso 3: Con letras (debe devolver 0)
    test_and_print0203("Con letras", "123abc");

    // Caso 4: Con símbolos (debe devolver 0)
    test_and_print0203("Con símbolos", "123!");

    // Caso 5: Con espacio (debe devolver 0)
    test_and_print0203("Con espacio", "1 2 3");

    // Caso 6: Número negativo (debe devolver 0, el '-' no es dígito)
    test_and_print0203("Número negativo", "-42");

    // Caso 7: Número decimal (debe devolver 0, el '.' no es dígito)
    test_and_print0203("Número decimal", "3.14");

    //return 0;

}

/**************   FIN EJER 03  *************/

/**************   INI EJER 04  *************/

void test_and_print0204(char *test_name, char *str) {
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

void main_C2_04(void) {
    // Caso 1: String vacío (debe devolver 1)
    test_and_print0204("String vacío", "");

    // Caso 2: Solo minúsculas válidas
    test_and_print0204("Solo minúsculas", "abcdef");

    // Caso 3: Con mayúsculas (debe devolver 0)
    test_and_print0204("Con mayúsculas", "abcDef");

    // Caso 4: Con números (debe devolver 0)
    test_and_print0204("Con números", "abc123");

    // Caso 5: Con símbolos (debe devolver 0)
    test_and_print0204("Con símbolos", "abc!");

    // Caso 6: Con espacio (debe devolver 0)
    test_and_print0204("Con espacio", "a b c");

    // Caso 7: Carácter Unicode (e.g., 'ñ'). Depende de tu implementación.
    // Si decides manejarlo, añade: test_and_print0204("Con 'ñ'", "añob");

    //return 0;
}

/**************   FIN EJER 04  *************/

/**************   INI EJER 05  *************/

void tes_and_print0205(char *test_name, char *str) {
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

void main_C2_05(void) {
    // Caso 1: String vacío (debe devolver 1)
    tes_and_print0205("String vacío", "");

    // Caso 2: Solo mayúsculas válidas
    tes_and_print0205("Solo mayúsculas", "ABCDEF");

    // Caso 3: Con minúsculas (debe devolver 0)
    tes_and_print0205("Con minúsculas", "ABCDef");

    // Caso 4: Con números (debe devolver 0)
    tes_and_print0205("Con números", "ABC123");

    // Caso 5: Con símbolos (debe devolver 0)
    tes_and_print0205("Con símbolos", "ABC!");

    // Caso 6: Con espacio (debe devolver 0)
    tes_and_print0205("Con espacio", "A B C");

    // Caso 7: Caracteres especiales (e.g., 'Ñ')
    // Si tu implementación lo requiere, añade: tes_and_print0205("Con 'Ñ'", "AÑO");

    //return 0;
}

/**************   FIN EJER 05  *************/

void main_C2_02lll (void)
{
	int	num;
	int	*ptr1;
	int **ptr2;
	int ***ptr3;
	int ****ptr4;
	int *****ptr5;
	int ******ptr6;
	int *******ptr7;
	int ********ptr8;
	int *********ptr9;

	num = 10;
	ptr1 = &num;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	printf("el puntero 9 finalmente contiene el valor: %d \n", *********ptr9);
	ft_ultimate_ft(ptr9);
	printf("el puntero 9 finalmente contiene el valor: %d", *********ptr9);
}

void main_C2_03llll (void)
{
	int	num1;
	int num2;
	int	*a;
	int *b;

	num1 = 10;
	num2 = 34;
	a = &num1;
	b = &num2;
	printf("Antes llamada a y b: %d - %d \n", *a, *b);
	ft_swap(a, b);
	printf("Despues llamada a y b: %d - %d \n", *a, *b);
}

void main_C2_04lll (void)
{
	int	num1;
	int num2;
	int quot;
	int rem;
	int	*ptr_quot;
	int *ptr_rem;


	num1 = 75;
	num2 = 13;
	quot = 0;
	rem = 0;
	ptr_quot = &quot;
	ptr_rem = &rem;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
    printf("Dividir de %d entre %d: \n", num1, num2);
	ft_div_mod(num1, num2, ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
}

void main_C2_05llll (void)
{
	int	num1;
	int num2;
	int	*ptr_quot;
	int *ptr_rem;

	num1 = 80;
	num2 = 6;
	ptr_quot = &num1;
	ptr_rem = &num2;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	printf("Antes de la llamada a y b: %d - %d \n", num1, num2);
    ft_ultimate_div_mod(ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	printf("Finalmente a y b: %d - %d \n", num1, num2);
}

void main_C2_06llll (void)
{
	char palabra[] = "Hola mundo";
	char *ptr_palabra;

	ptr_palabra = palabra;

	ft_putstr(ptr_palabra);

}

void main_C2_07llll (void)
{
	char palabra[] = "Hola mundo mas";
	char *ptr_palabra;
	int length_str;

	ptr_palabra = palabra;
	length_str = ft_strlen(ptr_palabra);
	printf("La longitud de: %s es %d \n", palabra, length_str);

}



int main_02(int argc)
{
    /*
	int ejercicio;

    // Si no se pasa argumento, usar valor por defecto
    if (argc == 1)
    {
        ejercicio = 1;  // Valor por defecto
        printf("Sin argumentos, ejecutando ejercicio %d por defecto\n", ejercicio);
    }
    else if (argc == 2)
    {
        ejercicio = atoi(argv[1]);
    }
    else
    {
        printf("Uso: %s [número_ejercicio]\n", argv[0]);
        printf("Ejercicios disponibles: 1, 2, 3\n");
        return (1);
    }
	*/

    // Resto del código igual...
    switch (argc)
    {
        case 0:
            printf("=== Ejercicio 0 ===\n");
            main_C2_00();
            break;

        case 1:
            printf("=== Ejercicio 1 ===\n");
            main_C2_01();
            break;
        case 2:
            printf("=== Ejercicio 2 ===\n");
            main_C2_02();
            break;
        case 3:
            printf("=== Ejercicio 3 ===\n");
            main_C2_03();
            break;
        case 4:
            printf("=== Ejercicio 4 ===\n");
            main_C2_04();
            break;
		case 5:
            printf("=== Ejercicio 5 ===\n");
            main_C2_05();
            break;
		case 7:
            printf("=== Ejercicio 7 ===\n");
            //main_C2_06();
            break;
        default:
            printf("Error: Ejercicio %d no existe\n", argc);
            return (1);
    }

    return (0);
}

