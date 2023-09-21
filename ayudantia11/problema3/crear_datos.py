def generar_datos_lineales(n):
    datos = []
    for i in range(n):
        columna1 = i
        columna2 = i * 2 + 5
        columna3 = i * 3 + 10
        datos.append((columna1, columna2, columna3))
    return datos

def crear_archivo_txt(datos, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        for fila in datos:
            linea = '\t'.join(str(valor) for valor in fila) 
            archivo.write(linea + '\n')

# Generar datos y crear archivo
datos_lineales = generar_datos_lineales(10) 
crear_archivo_txt(datos_lineales, 'datos.txt') 