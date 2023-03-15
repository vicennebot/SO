DROP DATABASE IF EXISTS parchis;
CREATE DATABASE parchis;

USE parchis;

CREATE TABLE jugador(
	DNI INT NOT NULL,
	username VARCHAR(25),
	password VARCHAR(25),
	PRIMARY KEY(DNI)
)ENGINE=InnoDB;

CREATE TABLE partida(
	idpartida INT NOT NULL,
	ganador VARCHAR(25),
	PRIMARY KEY(idpartida)
)ENGINE=InnoDB;

CREATE TABLE CLASIFICACION(
	usuario_dni INT NOT NULL,
	ultima_partida INT NOT NULL,
	posicion INT
	FOREIGN KEY(usuario_dni) REFERENCES jugador(DNI),
	FOREIGN KEY(ultima_partida) REFERENCES partida(idpartida)
INSERT INTO jugador VALUES(1, 'juankiller','patata69');
INSERT INTO jugador VALUES(1, 'armandokiller','viscaelbarça');
INSERT INTO partida VALUES('1', 'juankiller');
INSERT INTO partida VALUES('1', 'armandokiller');
INSERT INTO CLASIFICACION VALUES(1,1,2);
INSERT INTO CLASIFICACION VALUES(2,1,1);

