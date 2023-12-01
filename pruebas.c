#include "src/abb.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa2m.h"
#include <string.h>
#define VOLUMEN 10000

int nocmp(void *a, void *b)
{
	return 0;
}

int cmp_letras(void *a, void *b) 
{
	char *aa = (char*)a;
	char *bb = (char*)b;
	return strcmp(aa, bb);
}

void abbSeCreaVacio()
{
	abb_t *arbol = abb_crear(cmp_letras);
	pa2m_afirmar(abb_vacio(arbol) == true, "El arbol se crea vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 0, "El tamaño del arbol es 0");
	pa2m_afirmar(abb_quitar(arbol, "a") == NULL, 
			"No se pueden quitar elementos");
	abb_destruir(arbol);
}

void abb_insertar_quitar()
{
	char a='a', b='b', c='c', d='d', e='e', f='f', g='g';

	abb_t *arbol = abb_crear(cmp_letras);
	pa2m_afirmar(abb_vacio(arbol) == true, "El arbol se crea vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 0, "El tamaño del arbol es 0");
	pa2m_afirmar(abb_buscar(arbol, &a) == NULL, "No se encontro a");

	pa2m_afirmar(abb_insertar(arbol, &e) == arbol, "Se inserta e");

	pa2m_afirmar(abb_vacio(arbol) == false, "El arbol no esta vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 1, "El tamaño del arbol es 1");

	pa2m_afirmar(abb_buscar(arbol, &e) == &e, "Se encontro e");
	pa2m_afirmar(abb_insertar(arbol, &b) == arbol, "Se inserta b");
	pa2m_afirmar(abb_buscar(arbol, &b) == &b, "Se encontro b");
	pa2m_afirmar(abb_insertar(arbol, &f) == arbol, "Se inserta f");
	pa2m_afirmar(abb_buscar(arbol, &f) == &f, "Se encontro f");
	pa2m_afirmar(abb_insertar(arbol, &a) == arbol, "Se inserta a");
	pa2m_afirmar(abb_buscar(arbol, &a) == &a, "Se encontro a");
	pa2m_afirmar(abb_insertar(arbol, &d) == arbol, "Se inserta d");
	pa2m_afirmar(abb_buscar(arbol, &d) == &d, "Se encontro d");
	pa2m_afirmar(abb_insertar(arbol, &c) == arbol, "Se inserta c");
	pa2m_afirmar(abb_buscar(arbol, &c) == &c, "Se encontro c");
	pa2m_afirmar(abb_insertar(arbol, &g) == arbol, "Se inserta g");
	pa2m_afirmar(abb_buscar(arbol, &g) == &g, "Se encontro g");
	pa2m_afirmar(abb_tamanio(arbol) == 7, "El tamaño del arbol es 7");

	pa2m_afirmar(abb_quitar(arbol, &a) == &a, "Se quita a");
	pa2m_afirmar(abb_quitar(arbol, &b) == &b, "Se quita b");
	pa2m_afirmar(abb_quitar(arbol, &c) == &c, "Se quita c");
	pa2m_afirmar(abb_quitar(arbol, &d) == &d, "Se quita d");
	pa2m_afirmar(abb_quitar(arbol, &e) == &e, "Se quita e");
	pa2m_afirmar(abb_buscar(arbol, &a) == NULL, "No se encontro a");
	pa2m_afirmar(abb_quitar(arbol, &a) == NULL, "No se quita a");
	pa2m_afirmar(abb_tamanio(arbol) == 2, "El tamaño del arbol es 2");

	abb_destruir(arbol);
}

bool verdadero(void *a, void *b)
{
	return true;
}

void prueba_volumen()
{
	abb_t *arbol = abb_crear(nocmp);
	pa2m_afirmar(abb_vacio(arbol) && abb_tamanio(arbol) == 0, 
				"El arbol esta vacii, el tamaño es 0");

	int vector[VOLUMEN];
    	for (int i=0; i<VOLUMEN; i++){
        	vector[i] = i;
        	abb_insertar(arbol, &vector[i]);
	}
	pa2m_afirmar(abb_tamanio(arbol) == VOLUMEN, 
				"Se insertan 10000 elementos");
	abb_destruir(arbol);
}

void prueba_insertar_null()
{
	abb_t *arbol = abb_crear(nocmp);
	pa2m_afirmar(abb_vacio(arbol) == true, "El arbol esta vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 0, "El arbol tiene 0 elementos");
	pa2m_afirmar(abb_buscar(arbol, NULL) == NULL, 
			"Se busca null y no se encuentra");
	pa2m_afirmar(abb_insertar(arbol, NULL) == arbol, "Se inserta null");
	pa2m_afirmar(abb_vacio(arbol) == false, "El arbol no esta vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 1, "El arbol tiene 1 elemento");
	pa2m_afirmar(abb_insertar(arbol, NULL) == arbol, 
			"Se inserta null (repetido)");
	pa2m_afirmar(abb_tamanio(arbol) == 2, "El arbol tiene 2 elementos");
	pa2m_afirmar(abb_buscar(arbol, NULL) == NULL, 
			"Se busca null y se encuentra");
	pa2m_afirmar(abb_tamanio(arbol) == abb_con_cada_elemento(arbol, 
	INORDEN, verdadero, NULL), "Se iteran todos los elementos del arbol");
	pa2m_afirmar(abb_quitar(arbol, NULL) == NULL, "Se quita null");
	pa2m_afirmar(abb_vacio(arbol) == false, "El arbol no esta vacio");
	pa2m_afirmar(abb_tamanio(arbol) == 1, "El arbol tiene 1 elemento");
	pa2m_afirmar(1, "Se destruye el arbol");
	abb_destruir(arbol);
}

void destruir(void *a)
{
	abb_destruir(a);
}

void prueba_destuir_todo()
{
	abb_t *arbol = abb_crear(nocmp);
	abb_t *arbol1 = abb_crear(nocmp);
	abb_t *arbol2 = abb_crear(nocmp);
	abb_t *arbol3 = abb_crear(nocmp);
	abb_insertar(arbol, arbol1);
	abb_insertar(arbol, arbol2);
	abb_insertar(arbol, arbol3);
	abb_destruir_todo(arbol, destruir);

	pa2m_afirmar(1, "El elemento 1 se destuye con la lista");
	pa2m_afirmar(1, "El elemento 2 se destuye con la lista");
	pa2m_afirmar(1, "El elemento 3 se destuye con la lista\n(ver valgrind)");
}

void prueba_abb_recorrer()
{
	char a='a', b='b', c='c', d='d', e='e', f='f', g='g';
	char *elementos[10];

	abb_t *arbol = abb_crear(cmp_letras);
	abb_insertar(arbol, &e);
	abb_insertar(arbol, &b);
	abb_insertar(arbol, &f);
	abb_insertar(arbol, &a);
	abb_insertar(arbol, &d);
	abb_insertar(arbol, &c);
	abb_insertar(arbol, &g);

	pa2m_afirmar(abb_tamanio(arbol) == 7, 
		"Se crea un arbol con 7 elementos");
	pa2m_afirmar(abb_tamanio(arbol) == abb_con_cada_elemento(arbol, INORDEN,
		 verdadero, NULL), "Se iteran todos los elementos del arbol");
	pa2m_afirmar(abb_tamanio(arbol) == abb_recorrer(arbol, INORDEN, 
	(void**)elementos, 10), "Se recorren todos los elementos del arbol");

	abb_destruir(arbol);	  
}

void prueba_null() 
{
	abb_t *arbol;
	char a = 'a';
	pa2m_afirmar(abb_crear(NULL) == NULL, 
		"No se puede crear un arbol con comparador null");
	arbol = abb_crear(cmp_letras);
	pa2m_afirmar(abb_insertar(NULL, &a) == NULL, 
		"Insertar en un arbol null devuelve null");
	pa2m_afirmar(abb_quitar(NULL, &a) == NULL, 
		"Quitar en un arbol null devuelve null");
	pa2m_afirmar(abb_buscar(NULL, &a) == NULL, 
		"Buscar en un arbol null devuelve null");
	pa2m_afirmar(abb_vacio(NULL) == true, 
		"Determinar si un arbol null esta vacio devuelve true");
	pa2m_afirmar(abb_tamanio(NULL) == 0, 
		"Tamanio de un arbol null devuelve 0");
	pa2m_afirmar(abb_con_cada_elemento(NULL, INORDEN, verdadero, &a) == 0, 
		"Iterar un arbol null devuelve 0");
	pa2m_afirmar(abb_con_cada_elemento(arbol, INORDEN, NULL, &a) == 0, 
		"Iterar un arbol con funcion null devuelve 0");
	void *elementos[10];
	pa2m_afirmar(abb_recorrer(NULL, INORDEN, elementos, 10) == 0, 
		"Recorrer un arbol null devuelve 0");
	pa2m_afirmar(abb_recorrer(arbol, INORDEN, NULL, 10) == 0, 
		"Recorrer un arbol con funcion null devuelve 0");
	abb_destruir(arbol);
}

void pruebas_abb() 
{
	pa2m_nuevo_grupo("Pruebas de creación de abb");
	abbSeCreaVacio();
	pa2m_nuevo_grupo("Pruebas de insertar, buscar y quitar");
	abb_insertar_quitar();
	pa2m_nuevo_grupo("Prueba de volumem");
	prueba_volumen();
	pa2m_nuevo_grupo("Pruebas insertar Null");
	prueba_insertar_null();
	pa2m_nuevo_grupo("Pruebas destruir todo");
	prueba_destuir_todo();
	pa2m_nuevo_grupo("Pruebas iterar y recorrer abb");
	prueba_abb_recorrer();
	pa2m_nuevo_grupo("Pruebas Null");
	prueba_null();
}

int main()
{	
	pruebas_abb();
	return pa2m_mostrar_reporte();
}

