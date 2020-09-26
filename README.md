# Cluster Orange Pi One
Un Cluster [molt econòmic](bom.md) ( < 150 € ) utilitzant 7 [Orange Pi One](http://www.orangepi.org/orangepione/) amb [armbian](armbian.md). 

Aquest cluster el farem servir des d'un ordinador amb [jupiter notebook](jupyter.md)

Utilitzem una torre vella de PC amb una font [ATX](img/ATX.jpg). Cada Orange Pi One va en una [safata](openscad/bandeja3p5OrangePiOne.stl) d'unitat 3.5" impressa en 3D dissenyada en [OpenSCAD](openscad/bandeja3p5OrangePiOne.scad) i té 6 leds connectats al seu connector [GPIO](img/OrangePiGpioConnector.png).

Cal fer 3 passos amb cada placa del cluster:

* Instal·lar armbian [Instruccions](armbian.md)
* Instal·lar les llibreries per treballar amb Jupyter [Instruccions](pythonlib.md)
* Instal·lar MPI [Instruccions](mpi4py.md)

També teniu disponible un [soport](openscad/ledsCluster.stl) pels 7 mòduls de leds dissenyat amb [openSCAD](openscad/ledsCluster.scad)

