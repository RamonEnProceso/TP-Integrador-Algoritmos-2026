# Decisiones
> Elecciones de diseño, organización e ideas.

---

## Arquitectura
Se optó por organizar las funciones del programa a partir de su propósito.
Existen 5 carpetas padre:
### `\utiles`
> **Funciones reutilizables a lo largo de otros archivos.**
> Código que se separó para repetir sin tener que escribirlo siempre.


### `\logica`
> **Funciones vinculadas al manejo de datos.**
> Crea, lee, modifica y elimina datos del programa.


### `\menu`
> **Funciones vinculadas al menú de la aplicación.**
> Conecta el input del usuario con los datos a mostrar/modificar.

### `\structs`
> **Resgistros y constantes del programa.**
> Variables base del resto de funciones.

### `\datos`
> **Archivos generados por el programa**
> Datos guardados por el programa en `.txt` y `.dat`.

---

## Menú
- Menu Principal
  - Gestionar Juegos
    - Mostrar todos los juegos
      - Mostrar disponibles
      - Mostrar lista completa
    - Buscar juego (y mostrar datos)
      - Por Binario
      - Por Nombre
        - Consultar disponibilidad
        - Mostrar usos
        - Modificar
        - Eliminar
    - Ordenar lista de Juegos
      - Por Codigo
      - Por Nombre
    - Estadisticas
      - Contar juegos operando
      - Obtener juego más usado
  - Gestionar Visitantes
    - Mostrar Visitantes (codigo y nombre)
    - Registrar Visitante
    - Buscar Visitante (y mostrar datos)
      - Por Nombre
      - Por Codigo
        - Verificar acceso a juego (altura/ disponibilidad)
        - Modificar (altura/nombre/edad)
        - Eliminar
    - Liberar lista 
  - Generar Datos de prueba
  - Salir
