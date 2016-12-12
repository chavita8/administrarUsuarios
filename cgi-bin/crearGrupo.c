#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define MAX_LEN 1024
#define _XOPEN_SOURCE
#include <unistd.h>

// Separar: separa datos del formulario

void separar(char *cadena, char *linea, char separador){
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
//Funcion que remplaza una subcadena(orig) por otra(rep) en una cadena(str) dada.
void replace_str(char *str, char *orig, char *rep)
{
  static char buffer[4096];
  char *p;
  p = strstr(str, orig); // Is 'orig' even in 'st
  strncpy(buffer, str, p-str); // Copy characters from 'str' start to 'orig' st$
  buffer[p-str] = '\0';
  sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));
  strcpy(str,buffer);
}

int main(void){
    FILE *listar_guid;
    char *lenstr;   //puntero a los datos del formulario entrante
    char inputBuffer[MAX_LEN]; //arreglo de datos donde seran guardados los datos del formulario
    int contentLength;
    int i;
    char x;
    char grupo[80];
    char comando[100];
    char cmd_getguid[100];
    char linea[100];

    printf ("Content-type:text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<title>Response</title>");
    printf("</head>");
    printf("<body>");
    printf("<link href='/bootstrap.css' rel='stylesheet' type='text/css'>");
    printf("<link href='/main.css' rel='stylesheet' type='text/css'>");
    printf("<link href='/index.css' rel='stylesheet' type='text/css'>");
    printf("<div class=\"blog-masthead\">");
    printf("<div class=\"container\">");
    printf("<nav class=\"blog-nav\">");
    printf("<a class=\"blog-nav-item\" href=\"/index.html\">Usuarios</a>");
    printf("<a class=\"blog-nav-item active\" href=\"/grupos.html\">Grupos</a>");
    printf("<a class=\"blog-nav-item\" href=\"/bdd.html\">Base de datos</a>");
    printf("</nav>");
    printf("</div>");
    printf("</div>");

    printf("<div class=\"container\">");
    printf("<div class=\"row\">");
    printf("<div class=\"col-sm-8 blog-main\">");
    lenstr = getenv("CONTENT_LENGTH");

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

    separar(grupo, inputBuffer, '=');
    separar(grupo, inputBuffer, '&');

    printf("<p> Grupo: %s",grupo);

    // CREAR USUARIO
    if((setuid(0)) < 0) printf("<br>setuid: operation not permitted");
    if((setgid(0)) < 0) printf("<br>setgid: operation not permitted");
    strcpy(comando, "groupadd ");
    strcat(comando, grupo);
    strcat(comando, " 1>exito 2>error");
    printf("\n");
    printf("%s",comando);
    system(comando);

    strcpy(cmd_getguid,"cat /etc/group | grep ");
    strcat(cmd_getguid,grupo);
    strcat(cmd_getguid," | cut -d \\: -f1,3 > lista_guid");
    system(cmd_getguid);

    listar_guid = fopen("lista_guid","r");
    if(listar_guid != NULL){
        fgets(linea,100,listar_guid);
    }
    printf("<br/>");
    printf("%s",linea);
    fclose(listar_guid);
    printf("</div>");//end blog main
    printf("</div>");//end row
    printf("</div>");//end container
    printf("<footer class=\"blog-footer\">");
    printf("<p>ASO 2016</p>");
    printf("</footer>");
    printf("</body>");
    printf("</html>");


    return 0;
}



