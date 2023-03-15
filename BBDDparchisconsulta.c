#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int edad;
	char dni[10];
	char consulta [80];
	//conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	conn = mysql_real_connect (conn, "localhost","user", "pass", "parchis",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//ultima partida de armandokiller
	err=mysql_query (conn, "SELECT partida.idpartida FROM (jugadores, partida, CLASIFICACION) WHERE jugador.username = 'armandokiller' AND jugador.DNI=CLASIFICAION.usuario_dni AND CLASIFICACION.ultima_partida=partida.idpartida");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			// la columna 2 contiene una palabra que es la edad
			// la convertimos a entero 
			edad = atoi (row[2]);
			printf ("DNI: %s, nombre: %s, edad: %d\n", row[0], row[1], edad);
			row = mysql_fetch_row (resultado);
		}
	}
		
