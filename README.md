# Práctica 4: Algoritmos de ordenamiento

## Tabla de promedio

[![image.png](https://i.postimg.cc/MGRpCft8/image.png)](https://postimg.cc/xkfQHCWs)

## Tabla de desviación estándar

[![image.png](https://i.postimg.cc/1zt3zY9s/image.png)](https://postimg.cc/JsfL6xD2)

## Gráfica de promedio

[![image.png](https://i.postimg.cc/fTGPy3DL/image.png)](https://postimg.cc/dL96SV7P)

## Gráfica de desviación estándar

[![image.png](https://i.postimg.cc/d37WtFfr/image.png)](https://postimg.cc/K327J6x8)

A continuación, presento un análisis de los resultados obtenidos de la tabla de promedios. Después de realizar el experimento, podemos llegar a las siguientes conclusiones:

### Tendencias Generales:

- **Incremento en los tiempos con el tamaño del conjunto de datos:** En general, se observa un aumento en los tiempos de ejecución a medida que el tamaño del conjunto de datos crece. Este comportamiento es común y esperado, ya que manejar conjuntos de datos más grandes implica más operaciones y, por lo tanto, más tiempo de ejecución.

- **Diferencias notables entre algoritmos:** Existen variaciones significativas en los tiempos de ejecución entre diferentes algoritmos para un mismo tamaño de conjunto de datos. Algunos algoritmos son consistentemente más rápidos que otros, lo cual puede deberse a la complejidad algorítmica, la eficiencia en la implementación o la capacidad de manejar ciertos tipos de datos.

- **Comportamiento no lineal:** A medida que el tamaño del conjunto de datos aumenta, el incremento en el tiempo de ejecución no es necesariamente lineal. Pueden existir puntos donde el tiempo de ejecución aumenta significativamente, indicando posibles umbrales de rendimiento.

### Aspectos Específicos:

#### Algoritmos eficientes para conjuntos pequeños:

- En conjuntos de datos pequeños (por ejemplo, tam = 5 y tam = 10), algoritmos como Insertion Sort y Selection Sort demuestran ser más eficientes en términos de tiempo de ejecución.

#### Comportamiento de los algoritmos con conjuntos de datos grandes:

- A medida que el tamaño del conjunto de datos aumenta considerablemente (tam = 50000, tam = 100000, tam = 500000), el algoritmo QuickSort muestra un rendimiento relativamente bueno en comparación con otros algoritmos.

### Análisis por Tamaños de Arreglo:

#### Tamaños pequeños del arreglo (5-1000):

- En general, todos los algoritmos tienen tiempos de ejecución bajos y son eficientes en arreglos pequeños.
- Insertion Sort y Selection Sort son más rápidos en este rango, mientras que Bubble Sort es más lento.

#### Tamaños medianos del arreglo (5000-50000):

- Quick Sort y Merge Sort superan claramente a los otros algoritmos en eficiencia.
- Bubble Sort es significativamente más lento.

#### Tamaños grandes del arreglo (100000-10000000):

- Quick Sort sigue siendo el algoritmo más eficiente, incluso en comparación con Merge Sort.
- Insertion Sort, Selection Sort y Bubble Sort se vuelven impracticables para arreglos de este tamaño.

#### Tamaños extremadamente grandes del arreglo (50000000-100000000):

- En este punto, solo Quick Sort parece manejar estos tamaños de arreglo.
- Notas Adicionales:
  - Algunos algoritmos, como Bubble Sort, tienen un rendimiento cuadrático, indicando que su tiempo de ejecución crece cuadráticamente con el tamaño del arreglo.
  - Quick Sort y Merge Sort, algoritmos más eficientes, tienen un rendimiento linealítmico y lineal, respectivamente.
  - Valores marcados con 'x' indican que el rango de ejecución excedió el tiempo autorizado para realizar el experimento.

### Comparativa entre Quick Sort y Merge Sort:

Ambos son eficientes, pero con diferencias:

#### Quick Sort:

- Rendimiento excepcional en la mayoría de los casos.
- Complejidad promedio O(n log n), eficiente para grandes conjuntos de datos.
- Puede tener peor caso (O(n^2)), pero raramente ocurre en la práctica con una buena estrategia de partición.

#### Merge Sort:

- Rendimiento consistente en todos los casos, garantizando O(n log n) en todos los escenarios.
- Desventaja en el uso adicional de memoria.
- En general, Quick Sort es preferido en la práctica debido a su menor uso de memoria y mejor rendimiento promedio.

### Análisis de la Desviación Estándar:

#### Tamaños pequeños del arreglo (5-1000):

- Desviaciones estándar bajas, indicando consistencia en los tiempos de ejecución.
- Bubble Sort muestra la desviación estándar más baja, sugiriendo consistencia en su rendimiento.

#### Tamaños medianos del arreglo (5000-50000):

- Desviaciones estándar relativamente bajas.
- Merge Sort y Quick Sort muestran consistencia en su rendimiento.

#### Tamaños grandes del arreglo (100000-10000000):

- Aumento de las desviaciones estándar con el tamaño del arreglo.
- Bubble Sort muestra tendencia a desviaciones más altas, indicando variabilidad en su rendimiento.

#### Tamaños extremadamente grandes del arreglo (50000000-100000000):

- Valores 'x' indican dificultades en el manejo eficiente de esos tamaños de arreglo en el tiempo asignado.

### Conclusiones:

En general, se observa un comportamiento consistente con las complejidades teóricas esperadas para los algoritmos de ordenamiento en diferentes tamaños de arreglos. Algoritmos como Quick Sort y Merge Sort demuestran eficiencia, especialmente en conjuntos de datos más grandes. Las desviaciones estándar sugieren consistencia en los tiempos de ejecución, aunque algunos algoritmos experimentan dificultades en tamaños extremadamente grandes de arreglos.

Las desviaciones estándar, en su mayoría, se mantienen en niveles aceptables, lo que sugiere una consistencia en los tiempos de ejecución. Sin embargo, se observa que en tamaños extremadamente grandes de arreglo, algunos algoritmos experimentan dificultades para manejar eficientemente la tarea dentro del tiempo asignado, como se indica por los valores marcados como 'x'. Esto es consistente con la noción de que algunos algoritmos cuadráticos, como Bubble Sort, pueden volverse impracticables en conjuntos de datos demasiado grandes.

La elección del algoritmo debe basarse en la naturaleza específica de los conjuntos de datos y los requisitos de rendimiento deseados. Estos resultados proporcionan una valiosa perspectiva sobre el rendimiento práctico de los algoritmos y respaldan la eficacia de estrategias avanzadas en aplicaciones del mundo real. Se identificaron áreas de mejora o investigación adicional, como el rendimiento del algoritmo Merge Sort con conjuntos de datos más grandes.

Considero que este experimento cumplió en gran medida con las expectativas planteadas. La interpretación de la desviación estándar puede ser una tarea desafiante, y aunque no estoy completamente seguro de si la representación gráfica de la desviación estándar se ajusta a lo esperado, me esforcé por analizar minuciosamente cada dato de la tabla.

A lo largo del análisis, aplicé los conocimientos adquiridos en clase de manera adecuada, teniendo en cuenta las complejidades teóricas de los algoritmos de ordenamiento y evaluando su rendimiento en diferentes tamaños de arreglos. Los resultados obtenidos respaldan la eficiencia de ciertos algoritmos en comparación con otros, proporcionando una visión valiosa sobre la elección de algoritmos basada en la naturaleza específica de los conjuntos de datos y los requisitos de rendimiento deseados.

A pesar de las dificultades observadas en tamaños extremadamente grandes de arreglos, los datos recopilados y analizados ofrecen una perspectiva informada sobre el comportamiento práctico de los algoritmos de ordenamiento. En conjunto, considero que el experimento fue una oportunidad valiosa para aplicar los conocimientos adquiridos y obtener una comprensión más profunda del rendimiento práctico de los algoritmos de ordenamiento.
