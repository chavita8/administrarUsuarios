#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define MAX_LEN 1024
#define _XOPEN_SOURCE
#include <unistd.h>

// Separar: separa datos del formulario

void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}

void fixshell(char *shell){
	for(int i=0;i<sizeof(shell);i++){
		printf("%s",shell[i]);
	}
}

int main(void){
    char *lenstr;   //puntero a los datos del formulario entrante
    char inputBuffer[MAX_LEN]; //arreglo de datos donde seran guardados los datos del formulario
    int contentLength;
    int i;
    char x;
    char mensaje[80];
    char usuario[80];
    char clave[80];
    char shell[80];
    char comando[100];
    char *password;

    printf ("Content-type:text/html\n\n");
    printf("<TITLE>Response</TITLE>\n");
    lenstr = getenv("CONTENT_LENGTH");
    printf("CONTENT_LENGTH %s",lenstr);

    if (lenstr!= NULL)
    {
	contentLength = atoi(lenstr);   
    }
    else contentLength = 0;

    if (contentLength > sizeof(inputBuffer)-1)
	contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

	x = fgetc(stdin);
	if (x==EOF) break;
	inputBuffer[i] = x;
	i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;

    printf("<br>Datos Formulario: %s\n", inputBuffer);
    printf("<br>Tama&ntildeo: %d\n",contentLength);

    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    separar(clave, inputBuffer, '=');
    separar(clave, inputBuffer, '&');
    separar(shell, inputBuffer, '=');
    separar(shell, inputBuffer, '&');

    printf("<p> Mensaje: %s",mensaje);
    printf("<p> Usuario: %s",usuario);
    printf("<p> Clave: %s",clave);
    printf("<p> Shell: %s",shell);
    password = crypt(clave,"aa");


    // CREAR USUARIO
    if((setuid(0)) < 0) printf("<br>setuid: operation not permitted");
    if((setgid(0)) < 0) printf("<br>setgid: operation not permitted");
    strcpy(comando, "useradd ");
    strcat(comando, "-d /home/");
    strcat(comando, usuario);
    strcat(comando, " -p ");
    strcat(comando, password);
    strcat(comando, " -m ");
    strcat(comando, usuario);
    strcat(comando, " 1>exito 2>error");
    printf("\n");
    printf("%s",comando);
    system(comando);
    return 0;
}



