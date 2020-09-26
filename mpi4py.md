# Preparació MPI per Python

Abans de continuar cal fixar la IP de la Orange Pi One. Jo ho he fet des del meu router, però es pot fer d'altres formes, fins-i-tot amb armbian-config.

Ara ja podem crear a l'ordinador principal un fitxer [~/myhostfile](bash/myhostfile) con las IPs de los servidores i quants programes executaran simultàniament

També crearem un parell de claus ssh en aquest ordinador amb:

    ssh-keygen

deixant els valors per defecte (ENTER a totes les pregunytes). Farem una còpia de la clave pública amb el nom *main*:

    cd .ssh
    cp id_rsa.pub main

Instal·lem mpi, que ens permetrà executar ordres remotes:

    sudo apt install openmpi-bin python3-mpi4py -y

També instal·larem openmpi-bin python3-mpi4py a les targetes Orange Pi One del cluster i generarem la parella de claus ssh.  Crearem una còpia de la clau pública del client en la carpeta .ssh del servidor (en el meu cas el servidor té la IP 192.168.1.60):

    ssh-keygen
    cd .ssh
    cp id_rsa.pub  cluster1
    scp 192.168.1.60:/home/jordi/.ssh/main .
    cat main>>authorized_keys

A l'ordinador principal tambñe haurem de copiar les claus públiques de les targetes Orange Pi One i afegir-les a les autoritzades:

En el meu cas la tarjeta Orange Pi One té la IP 192.168.1.136:

    scp 192.168.1.136:/home/jordi/.ssh/cluster1 .
    cat cluster1>>authorized_keys

Ara ja podem provar el funcionament (en el meu cas tinc un total de 12 slots disponibles en aquest moment) amb:

    mpirun -hostfile myhostfile -np 12 hostname

També caldrà instal·lar en les targetes Orange Pi One el processament paral·lel en Python3:

    sudo apt install pkg-config libzmq3-dev
    sudo pip install ipyparallel

I a l'ordinador principal preparar Jupyter notebooks per treballar amb el cluster:

    sudo ipcluster nbextension enable
    jupyter serverextension enable --py ipyparallel
    jupyter nbextension install --py ipyparallel
    jupyter nbextension enable --py ipyparallel

I copiar els executables [clusterM](bash/clusterM) i [clusterS](bash/clusterS) per iniciar el cluster i que caldrà adaptar al vostre cluster (nom d'usuari, IPs on copiar arxiu de seguretat, nombre de slots disponibles)
 




