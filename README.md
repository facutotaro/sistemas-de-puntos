# Cosas para hacer Ayer

#### Entender la matríz de Colley

.|.|.
-|-|-
2+n<sub>1</sub>|-n<sub>12</sub>|-n<sub>13</sub>
-n<sub>21</sub>|2+n<sub>2</sub>|-n<sub>23</sub>
-n<sub>31</sub>|-n<sub>32</sub>|2+n<sub>3</sub>


(2+n1)\*r1 - ( a\*r2  +  b\*r3  )=   1+(w1-l1)/2 \
(2+n2)\*r2 - ( a\*r1  +  c\*r3  )=   1+(w2-l2)/2 \
(2+n3)\*r3 - ( b\*r1  +  c\*r2  )=   1+(w3-l3)/2   

C.r = b \
A.x = b


#### Pensar
* ¿Porqué siempre se puede resolver con Colley?
* ¿Colley es justo?

#### Fabricar
* Datos artificiales para mostrar comportamientos


#### Adversario
* Preguntar ambigüedad: ¿sabemos el futuro de los partidos entre otros equipos?
* En tal caso, estrategia optima
* Caso contrario, vamos jugando "al día"

#### Implementación
* Colley
* Ganados/perdidos
* Método alternativo (tras pensarlo)
  * Idea: penalizar más por perder que recompensar por ganar

#### Pipeline
* Acomodar los datos (filtrar la basura) ¿Python?
* Métodos para solucionar cosas rápido (C++)
* Hacer grafiquitos ¿Python?


#### Opcionales
* Considerar empates
* Características especiales para solución más eficiente
  * Puede servir: es dominante y simétrica
* Matrices ralas eficientes en espacio y tiempo
  * Puede servir: solo guardar coeficientes no nulos

#### Tests
* A la salida del Pipeline

![Cuentita](/images/latex/renders/ecuacion-peola.svg)

![LaTeX](/images/plot.jpg)



```javascript
if (el-juego){
  return true
}
```

![Cuentita](/images/latex/renders/ecuacion-fea.svg)
