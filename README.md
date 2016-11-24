# ADMINISTRAR USUARIOS CGI WEB APPLICATION RASPBERRY PY

apt-get install apache2
vim /etc/apache2/mods-enabled/cgid.load

LoadModule cgid_module modules/mod_cgid.so

cd /usr/lib/cgi-bin/
gcc index.c script.cgi

view
http://localhost/cgi-bin/script.cgi

Materia Aplicacion de sistemas operativos
Docente:  Cussi Nicolas Grover Humberto
Grupo: Maricela Chavarria Callahuara
       Rudy Rafael Ramirez Caero

