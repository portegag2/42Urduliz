#!/bin/bash

# Script para preparar entrega
# Uso: ./preparar_entrega.sh [numero_leccion]
# Ejemplo: ./preparar_entrega.sh 0

if [ $# -ne 1 ]; then
    echo "Uso: $0 [numero_leccion]"
    echo "Ejemplo: $0 0  (para C-00-dev)"
    echo "         $0 1  (para C-01-dev)"
    exit 1
fi

LECCION=$1
ORIGEN="/home/portega-/piscina/42Urduliz/C-0${LECCION}-dev"
DESTINO="/home/portega-/piscina/entregaDefinitiva/C-0${LECCION}"

# Verificar que existe la carpeta origen
if [ ! -d "$ORIGEN" ]; then
    echo "Error: No existe la carpeta $ORIGEN"
    exit 1
fi

echo "Preparando entrega de C-0${LECCION}..."
echo "Origen: $ORIGEN"
echo "Destino: $DESTINO"

# Crear directorio destino
mkdir -p "$DESTINO"

# Copiar archivos .c de los ejercicios y quitar el include
for archivo in "$ORIGEN"/ex*/ft_*.c; do
    if [ -f "$archivo" ]; then
        # Obtener nombre del ejercicio (ex00, ex01, etc.)
        ejercicio=$(basename "$(dirname "$archivo")")
        
        # Crear carpeta del ejercicio en destino
        mkdir -p "$DESTINO/$ejercicio"
        
        # Copiar archivo sin la línea del include y la línea siguiente
        sed '/index_components\.h/{N;d;}' "$archivo" > "$DESTINO/$ejercicio/$(basename "$archivo")"
        echo "Copiado: $ejercicio/$(basename "$archivo")"
    fi
done

echo ""
echo "✅ Entrega preparada en: $DESTINO"
echo "Los archivos están listos para entregar (sin includes ni .o)"