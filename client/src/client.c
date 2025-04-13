#include "client.h"
#include "utils.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	if (logger == NULL) {
		// ¡No se pudo crear el config!
		// Terminemos el programa
		abort();
	}
	log_info(logger, "Hola! Soy un log");
	


	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();
	if (config == NULL) {
		// ¡No se pudo crear el config!
		// Terminemos el programa
		abort();
	};

	
	if (config_has_property (config, "IP")){
		ip=config_get_string_value(config, "IP");
	};
	if (config_has_property (config, "PUERTO")){
		puerto=config_get_string_value(config, "PUERTO");
	}; 
	if (config_has_property (config, "CLAVE")){
		valor=config_get_string_value(config, "CLAVE");
	};

	//printf("%s", ip);
	log_info(logger,"%s", valor);
	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	log_destroy(logger);
	config_destroy(config);
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("TP0.log", "LOGGER TP0" , 1, LOG_LEVEL_INFO);

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	nuevo_config = config_create("../cliente.config");
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	//leido = readline("> ");
	while (!string_is_empty(leido)){
		// Mostrar el prompt al usuario y leer la línea de entrada
		leido = readline("> ");

		// Imprimir la línea de entrada
		log_info(logger, "%s", leido);
	
	}
	free(leido);

	


	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
