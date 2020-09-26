# Preparació MPI per Python

**Important: Totes les operacions d'aquest document es faran amb l'usuari creat, no amb root**

Abans de continuar cal fixar la IP de la Orange Pi One. Jo ho he fet des del meu router, però es pot fer d'altres formes, fins-i-tot amb armbian-config.

També instal·larem openmpi-bin python3-mpi4py a les targetes Orange Pi One del cluster i generarem la parella de claus ssh.  Crearem una còpia de la clau pública del client en la carpeta .ssh del servidor (en el meu cas el servidor té la IP 192.168.1.60):

    sudo apt install openmpi-bin python3-mpi4py -y
    ssh-keygen
    cd .ssh
    cp id_rsa.pub  cluster1
    scp 192.168.1.60:/home/jordi/.ssh/main .
    cat main>>authorized_keys

A l'ordinador principal també haurem de copiar les claus públiques de les targetes Orange Pi One i afegir-les a les autoritzades:

En el meu cas la tarjeta Orange Pi One té la IP 192.168.1.136:

    scp 192.168.1.136:/home/jordi/.ssh/cluster1 .
    cat cluster1>>authorized_keys

Ara ja podem provar el funcionament (en el meu cas tinc un total de 12 slots disponibles en aquest moment) amb:

    mpirun -hostfile myhostfile -np 12 hostname

També caldrà instal·lar en les targetes Orange Pi One el processament paral·lel en Python3:

    sudo apt install pkg-config libzmq3-dev
    sudo pip3 install ipyparallel

