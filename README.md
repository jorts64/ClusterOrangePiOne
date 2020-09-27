# Cluster Orange Pi One
Un Cluster [molt econòmic](bom.md) ( < 150 € ) utilitzant 7 [Orange Pi One](http://www.orangepi.org/orangepione/) amb [armbian](armbian.md). 

Aquest cluster el farem servir des d'un ordinador amb jupiter notebook

Utilitzem una torre vella de PC amb una font [ATX](img/ATX.jpg). Cada Orange Pi One va en una [safata](openscad/bandeja3p5OrangePiOne.stl) d'unitat 3.5" impressa en 3D dissenyada en [OpenSCAD](openscad/bandeja3p5OrangePiOne.scad) i té 6 leds connectats al seu connector [GPIO](img/OrangePiGpioConnector.png).

## Instal·lació a l'ordinador principal

Veure [instruccions](jupyter.md)

## Instal·lació a les plaques Orange Pi One

Cal fer 3 passos amb cada placa del cluster (canvieu el hostname *cluster1* per la placa que esteu treballant):

* Instal·lar armbian [Instruccions](armbian.md)
* Instal·lar les llibreries per treballar amb Jupyter [Instruccions](pythonlib.md)
* Instal·lar MPI [Instruccions](mpi4py.md)

També teniu disponible un [soport](openscad/ledsCluster.stl) pels 7 mòduls de leds dissenyat amb [openSCAD](openscad/ledsCluster.scad)

## Muntatge del conjunt

Podeu veure aquesta [galeria d'imatges](muntatge.md) del procés de muntatge

## Posada en funcionament

Una vegada tot a punt, he obert tres terminals a l'ordinador principal:

1r terminal: iniciem controlador del cluster

    ./clusterM

2n terminal: iniciem serveis computació paral·lela a les targetes Orange Pi One

    ./clusterS

3r terminal: iniciem Jupyter notebook

    cd ~/jupyter
    jupyter notebook

Jo he provat un [càlcul de pi pel mètode de Montecarlo](juipyter/parallel01.ipynb)    
Ha anat força bé: 320 millions de assatjos en 80s no es veu cada dia!
