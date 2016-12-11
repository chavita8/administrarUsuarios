#include <stdio.h>
#include <stdlib.h>



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

int main(){
    char usuario[100];
    char area_trabajo[100];
    char shell[100];
    FILE *lista_usuarios;
    char linea[100];
    printf("Content-type:text/html\n\n");
    printf("<title>Response</title>");

    if((setuid(0)) < 0) printf("<br>setuid: operation not permitted");
    if((setgid(0)) < 0) printf("<br>setgid: operation not permitted");

    system("cat /etc/passwd | grep /bin/bash > lista_usuarios");
    system("cat /etc/passwd | grep /bin/sh >> lista_usuarios");
    system("cat /etc/passwd | grep /bin/csh >> lista_usuarios");
    system("cat /etc/passwd | grep /bin/tcsh >> lista_usuarios");
    system("cat /etc/passwd | grep /bin/ksh >> lista_usuarios");
    system("cat lista_usuarios | cut -d \\: -f1,6,7 > lista_completa");
    lista_usuarios = fopen("lista_completa","r");
    printf("<table>");
    printf("<tr>");
    printf("<th>Usuario</th>");
    printf("<th>Directorio</th>");
    printf("<th>Shell</th>");
    printf("</tr>");
    if(lista_usuarios!=NULL){
        while(feof(lista_usuarios)==0){
            fgets(linea,200,lista_usuarios);
            printf("<tr>");
            separar(usuario,linea,':');
            separar(area_trabajo,linea,':');
            separar(shell,linea,':');
            printf("<td>");
            printf("%s",usuario);
            printf("</td>");
            printf("\n");
            printf("<td>");
            printf("%s",area_trabajo);
            printf("</td>");
            printf("\n");
            printf("<td>");
            printf("%s",shell);
            printf("</td>");
            printf("\n");
            printf("</tr>");
        }
    }
    printf("</table>");

}
