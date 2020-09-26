# Instal·lació de jupyter notebook a l'ordinador principal

Aquesta instal·lació l'he comprovada amb Debian 10. és important escollir aquesta distribució per compatibilitat amb el cluster, ja que no dona problemes de comunicació MPI amb Armbian.

Primer instal·lem les biblioteques científiques, després jupyter:

    sudo apt install python3-pip
    sudo python3 -m pip install --upgrade pip
    sudo pip3 install sympy
    sudo apt-get install python3-matplotlib
    sudo apt-get install python3-scipy -y
    sudo apt-get install python3-numpy -y
    sudo pip3 install jupyter

També interessa instal·lar Latex, ja que ens permetrà exportar el nostre document a PDF

    sudo apt-get install texlive-xetex texlive-fonts-recommended texlive-generic-recommended

Ara ja podrem crear una carpeta a l'usuari que executarà el servidor jupyter per desar els arxius, i executarem des d'aquesta carpeta jupyter, que obrira un navegador amb el webide

    mkdir ~/jupyter
    cd ~/jupyter
    jupyter notebook

Si el volem tenir a un servidor, caldrà evitar que intenti obrir el navegador i haurem d'autoritzar el seu ús des d'altres màquines a la xarxa

Primer hem de crear un fitxer de configuració

    jupyter notebook --generate-config

Aquest fitxer el trobarem a ~/.jupyter/jupyter_notebook_config.py. L'haurtem de modificar amb les línies

    c.NotebookApp.open_browser = False
    c.NotebookApp.ip = '*'

I haurem de generar una contrasenya per evitar treballar amb tokens

    jupyter notebook password

Ara ja podem crear a l'ordinador principal un fitxer  [~/myhostfile](bash/myhostfile) con las IPs de los servidores i quants programes executaran simultàniament

També crearem un parell de claus ssh en aquest ordinador amb:

    ssh-keygen

deixant els valors per defecte (ENTER a totes les preguntes). Farem una còpia de la clave pública amb el nom main:

    cd .ssh
    cp id_rsa.pub main

Instal·lem mpi, que ens permetrà executar ordres remotes:

    sudo apt install openmpi-bin python3-mpi4py -y


Per treballar amb el cluster caldrà configurar Jupyter notebook

    sudo ipcluster nbextension enable
    jupyter serverextension enable --py ipyparallel
    jupyter nbextension install --py ipyparallel
    jupyter nbextension enable --py ipyparallel

I copiar els executables [clusterM](bash/clusterM) i [clusterS](bash/clusterS) per iniciar el cluster i que caldrà adaptar al vostre cluster (nom d'usuari, IPs on copiar arxiu de seguretat, nombre de slots disponibles)
 
