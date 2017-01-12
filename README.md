# ADMINISTRAR USUARIOS CGI WEB APPLICATION RASPBERRY PI

**Instalacion apache 2**
~~~~
apt-get install apache2
~~~~

**Habilitacion CGI-BIN RASPBERRY PI**
~~~~
vim /etc/apache2/mods-enabled/cgid.load
~~~~
~~~~
LoadModule cgid_module /usr/lib/apache2/modules/mod_cgid.so
~~~~
**Compilacion**
~~~~
cd /usr/lib/cgi-bin/
gcc index.c script.cgi
~~~~

# Materia Aplicacion de sistemas operativos
**Docente** 
> *Cussi Nicolas Grover Humberto
**Grupo** 
> *Maricela Chavarria Callahuara
> *Rudy Rafael Ramirez Caero

