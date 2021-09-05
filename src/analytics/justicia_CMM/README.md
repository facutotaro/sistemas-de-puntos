## ¿que es un ranking?

un ranking es un orden que se le asigna a un conjunto de participantes (individuos o equipos) luego de una competencia que busca representar la capacidad que tiene un participante de ganar o perder frente a otro.

# CMM: Colley Matrix Method

CMM es un metodo que se utiliza para calcular el ranking de un conjunto de equipos luego de una competencia. 
Las caracteristicas principales de este metodo son:

- ranking se calculan en base a los partidos ganados y perdidos
- no se toma en cuenta el puntaje de los partidos
- no se realizan ajustes
- toma en cuenta la dificultad del schedule

Estas caracteristicas, entre otras, logran eliminar cualquier tipo de bias que provenga por fuera de los resultados de los partidos.

### CMM vs WP

Se sabe que para el correcto funcionamiento del metodo WP (win percentage) se necesita que los equipos de una liga en particular jueguen con una parte representiva de la misma.

Esto ultimo no siempre sucede, como por ejemplo en la liga de football universitario de estados unidos, donde hay 117 que solo juegan 11 partidos cada uno.

En casos como el anterior, CMM busca aproximarse al fucionamiento de WP, pero ademas tomando en cuenta la dificultad del schedule para subsanar el problema de dicho metodo.

### Teoria de CMM

#### Primeros Razonamientos

En primer lugar se define el ranking de un equipo como:

r = 1 + n\_w / 2 + n\_l + n\_w 		(1)

Luego se define:

n\_w,i= (n\_w,i - n\_l,i)/ 2 + sum(j = 1, n\_tot,i)(r^i\_j)	(2)

siendo r^i\_j el ranking del j-esimo oponente del equipo i.

donde la sumatoria de los ranking de los jugadores contra los que jugo el equipo i, representa su dificultad de schedule.

#### Matriz de Colley

Finalmente, poniendo en lugar de r^i\_j la definicion de r, se puede obtener la siguiente formula: ...(3)

La cual nos permite crear el sistema de ecuaciones lineales Cr = b, donde C es ..., b es ... y r, los ranking, son nuestras incognitas. Por lo que finalmente, el problema de calcular los ranking de una liga se reduce a resolver dicho sistema de ecuaciones lineales[1].

# Justicia CMM:

En este bloque de experimentacion se busca estudiar si CMM es justo al momento de calcular rankings.

Para ello se define **justicia** por: 

>Que no sea posible que el resultado de un partido
entre dos equipos afecte indirectamente el ranking de un tercero

Aclaro que con ranking nos referimos tanto al valor del ranking de un equipo, desde ahora "rating", como a la posición en el orden segun rating que ocupa un equipo respecto a los demas (1ro, 2do, 3ro etc..)

## Experimentación

Suponiendo la ocurrencia de un partido entre el equipo i y el equipo j, vamos a analizar que le ocurre a un tercer equipo, llamdo h.

Para ello, vamos a categorizar todos los posibles torneos a estudiar en las siguiente categorias:

- (1) h esta "desconectada por partidos" de i y j.

- (2) h esta "conectada por partidos" con i y j, y:

	- (2.1) h no jugo ni con i ni con j
	- (2.2) h jugo exclusivamente con i o con j
	- (2.3) h jugo con i y con j

### Experimento (1) :

Creamos una competencia en donde existen dos grupos de equipos, grupo A y grupo B. Los equipos de cada grupo van a jugar entre si, pero nunca va a haber un partido entre un equipo del grupo A y del grupo B.

En primer lugar simulamos que lo partidos del grupo A ya se jugaron y que ahora se estan jugando los partidos del grupo B. Partiendo de este escenario analisamos que le sucede al ranking (rating y posicion) de un equipo particular del grupo A.

Hipotesis: el equipo observado del grupo A no va a tener cambios en el rating pero si puede tener cambios en la posicion.

Resultados: (graficos)

Analizando los casos de 6 equipos con 12 partidos, 10 equipos con 100 partidos y 20 equipos con 200 partidos, podemos decir que el rating del equipo observado no varia y la su posicion varia a medida que se van desarrollando los partidos del grupo B.

Volviendo al caso (1), podemos concluir que h (el equipo observado del grupo A), no cambia su rating, pero si puede llegar a cambiar su posicion, si dos equipos cualesquiera que esten "desconectados por partidos" de h juegan entre si. 

### Experimento (2) :

Creamos una competencia en donde vamos a observar el comportamiento de un equipo h (representado por el indice 1 en la tabla), respecto a los resultados de otros dos equipos, i y j (representados por el indice 2 y 3 en la tabla respectivamente)

#### Experimento (2.1) :

En esta competencia vamos a estudiar que sucede con el raking de h cuando nunca juega ni con i ni con j. 

Para ello la tabla va a estar formada primero por partidos aleatoreos con h, sin que juegue con i y j, y luego por partidos aleatoreos sin h. Luego se analizara que hubiera pasado con el ranking de h si: i y j tiene el resultado obtenido, i y j tiene el resultado inverso, entre i y j gana siempre i, entre i y j gana siemrpe j, y otro resultado aleatoreo entre los partidos de i y j.

hipotesis: los partidos de i y j afectan al rating de h, pero no demasiado (comparacion con 2.2 y 2.3), mientras que la posicion puede cambiar o no.

Resultados: (graficos)

En los experimentos se puede observar que, como se habia planteado en la hipotesis, los resultados de los partidos de i y j afectan en mayor o menor medida el rating de h, lo cual puede o no afectar su posicion en el ranking.

Ademas, luego de observar los casos de 6 equipos con 12 partidos, 10 equipos con 100 partidos y 20 equipos con 200 partidos, los resultados entre los partidos entre i y j afectan cada vez menos al resultado de h. Esto se evidencia midiendo el desvio standard de una muestra de 1000 rating en cada uno de los casos, el cual es de alrededor de 0.15 en el primer caso, 0.12 en el segundo caso y 0.09 en el ultimo caso.

Creemos que esto ultimo es a causa de la mayor cantidad de equipos y variedad de partidos, que causa que solo los enfrentamientos entre i y j no afecten tanto al rating de h.

(Poner en formato las refencias)

[1] Colley’s Bias Free College Football Ranking Method (Paper)