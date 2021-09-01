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

## Analisis Teorico

Suponiendo la ocurrencia de un partido entre el equipo i y el equipo j, vamos a analizar que le ocurre a un tercer equipo, llamdo h.

Haciendo un primer analisis teorico, podemos observar la ecuacion lineal correspondiente al equipo h: ...

La misma contiene las variables n\_tot,h, n\_w,h, n\_l,h y todos los valores de ranking. Sabemos que si el partido fue entre i y j, luego n\_tot,h, n\_w,h, n\_l,h deben mantener el mismo valor. Por lo tanto, para que se siga cumpliendo la igualdad de la ecuacion del equipo h debe darse alguna de las siguientes situciones:

-  (1) Los valores de ranking no se modificaron (lo cual seria extraño, ya que esto implica que el ranking de i y j luego de su partido no se modificaron, cuando se sabe que uno gano y otro perdio)

- (2) Los valores de ranking si cambian y:
	- (2.1) si h no jugo ni con i ni con j, el ranking de h no se modifica
	- (2.2) si h jugo exclusivamente con i o con j, el ranking de h se modifica
	- (2.3) si h juego tanto con i como con j:
		- (2.3.1) el ranking de h se modifica
		- (2.3.2) el ranking de h no se modifica (se compensa el ranking de i con el ranking de j)

Partiendo de este analisis, resulta razonable estudiar los casos (1) y (2.3), ya que en los demas se pudo deducir que es lo que sucede con el ranking de h.

## Experimentación

Para la experimentacion vamos a crear tablas de datos que cumplan con las condiciones de los casos a estudiar.

### caso 1:

Creamos tablas, con 3, 10 y 100 equipos, con una cantidad de partidos aleatoreos (cualquier equipo contra cualquier otro) de 0.01, 0.1, 1 y 2 veces la cantidad de equipos, por equipo, siempre forzando a que todos los equipos jueguen por lo menos una vez.

Como hipotesis para todos los casos tengo que nunca es verdadero el caso 1, es decir, que luego de un partido el vector de los valores de ranking siempre se modifica.

### caso 2.3:

thinking

(Poner en formato las refencias)

[1] Colley’s Bias Free College Football Ranking Method (Paper)