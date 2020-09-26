# Preparació MPI per Python

Abans de continuar cal fixar la IP de la Orange Pi One. Jo ho he fet des del meu router, però es pot fer d'altres formes, fins-i-tot amb armbian-config.

Ara ja podem crear a l'ordinador principal un fitxer [~/myhostfile](myhostfile) con las IPs de los servidores i quants programes executaran simultàniament

També crearem un parell de claus ssh en aquest ordinador amb:

    ssh-keygen

deixant els valors per defecte (ENTER a totes les pregunytes). Farem una còpia de la clave pública amb el nom *master*:

    cd .ssh
    cp id_rsa.pub master

Instal·lem mpi, que ens permetrà executar ordres remotes:

    sudo apt install openmpi-bin python3-mpi4py -y

També instal·larem openmpi-bin python3-mpi4py a les targetes Orange Pi One del cluster i generarem la parella de claus ssh.  Crearem una còpia de la clau pública del client en la carpeta .ssh del servidor (en el meu cas el servidor té la IP 192.168.1.60):

    ssh-keygen
    cd .ssh
    cp id_rsa.pub server
    scp 192.168.1.10:/home/jordi/.ssh/master .
    cat master>>authorized_keys

A l'ordinador principal tambñe haurem de copiar les claus públiques de les targetes Orange Pi One i afegir-les a les autoritzades:

    En el cliente copiar las claves de los servidores en ~/.ssh y añadir a authorized_keys :

    scp 192.168.1.60:/home/jordi/.ssh/server ./cluster1
    cat cluster1>>authorized_keys




