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

	- (2.1) h no jugo ni con i y ni con j

	- (2.2) h jugo solo con i o (exclusivo) con j

	- (2.3) h jugo con i y con j


(Poner en formato las refencias)

[1] Colley’s Bias Free College Football Ranking Method (Paper)