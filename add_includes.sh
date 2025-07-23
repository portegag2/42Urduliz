#!/bin/bash

# Script para añadir #include "../index_components.h" a todos los archivos .c

# Para archivos en C-XX-dev/main_XX.c
for file in C-*-dev/main_*.c; do
    if [ -f "$file" ]; then
        # Verificar si ya tiene el include
        if ! grep -q "#include.*index_components.h" "$file"; then
            # Crear archivo temporal con el include al principio
            echo '#include "../index_components.h"' > temp_file
            cat "$file" >> temp_file
            mv temp_file "$file"
            echo "Añadido include a: $file"
        else
            echo "Ya existe include en: $file"
        fi
    fi
done

# Para archivos en C-XX-dev/exYY/ft_*.c
for file in C-*-dev/ex*/ft_*.c; do
    if [ -f "$file" ]; then
        # Verificar si ya tiene el include
        if ! grep -q "#include.*index_components.h" "$file"; then
            # Crear archivo temporal con el include al principio
            echo '#include "../../index_components.h"' > temp_file
            cat "$file" >> temp_file
            mv temp_file "$file"
            echo "Añadido include a: $file"
        else
            echo "Ya existe include en: $file"
        fi
    fi
done

echo "Script completado."
