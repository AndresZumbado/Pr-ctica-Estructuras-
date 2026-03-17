# Pr-ctica-Estructuras-
Práctica en clase de Estructuras

# Práctica de programación

1. Regístrese / verifique que puede acceder la instancia de Gitlab de UCR (https://git.ucr.ac.cr).
2. En grupos de ~4 personas (asignados automáticamente por breakout rooms), creen un proyecto en Gitlab donde implementen el juego de Memoria, siguiendo las siguientes reglas:

- El juego consiste en crear un tablero cuadrado. El tablero se rellena con números enteros, de manera que haya únicamente un par de cada número. Cuando se despliega en pantalla, se muestran todas las casillas escondidas, excepto las que ya se han descubierto.
- El tablero puede tener un tamaño arbitrario entre 8x8 y 32x32 casillas, que siempre sea potencia de 2.
- Cada turno:
  1. El jugador decide descubrir una casilla indicando las coordenadas en formato `(fila, columna)`.
  2. Si la casilla ya fue descubierta, se imprime un mensaje de error y se pide una nueva coordenada (regresar a 2).
  3. Si no ha sido descubierta, la casilla se descubre.
  4. Con la primera casilla descubierta, se le pide al jugador que indique dónde está el par de ese número, en formato `(fila, columna)`.
  5. Si esa casilla ya fue descubierta, se imprime un mensaje de error y se pide una nueva coordenada (regresar a 4).
  6. Si la casilla es la pareja de la primera casilla, las dos quedan descubiertas y se inicia un nuevo turno (regresar a 1).
  7. Si no es la pareja de la primera casilla, se imprime un mensaje de error y se inicia un nuevo turno (regresar a 1).
  8. El juego termina cuando todas las casillas quedan descubiertas.

3. En cuanto a la implementación:

- Deben implementar el juego utilizando estructuras.
- El tablero no puede tener un tamaño estático, sino que debe inicializarse con un parámetro desde la función `main()`.
- La memoria para el juego debe asignarse dinámicamente.
- El código debe organizarse en funciones con responsabilidades claras, sencillas y comprensibles.

4. Al finalizar la clase, deben escribir todos sus cambios en el repositorio de Gitlab que hicieron al principio. Cada grupo presentará su código en clase el viernes.
