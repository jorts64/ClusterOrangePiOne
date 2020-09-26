He utilitzat [armbian](https://www.armbian.com/orange-pi-one/) 20.05.2 basada en Buster (Debian 10), però baixant la versió actual hauria de funcionar igual.

Una vegada restaurada la imatge a una SD de 32 GB (jo he utilitzat l'eina Discs del meu Ubuntu) la posem a l'Orange Pi one i connectem la placa a la xarxa i aun carregador USB de 2A.

Localitzem a la xarxa quina IP ha agafat la placa (en el meu cas 192.168.1.136)

Ens connectem a la placa per xarxa des d'un terminal (contrasenya de *root* **1234**)

     ssh root@192.168.1.136

Ens obliga a canviar la contrasenya de root i crear un nou usuari. En el meu cas he creat l'usuari jordi, el mateix que faig servir a la meva màquina principal.

Actualitzem els paquets

     apt update
     apt upgrade







