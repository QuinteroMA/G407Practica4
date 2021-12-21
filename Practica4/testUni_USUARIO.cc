
#include "usuario.h"
#include "gtest/gtest.h"

void test_alta_usuario()
{
	Usuario aux("XXX",-1, "XXX@YYY.es", "ZZZZ");
	Programa p;
	bool dato = p.altaUsuario(aux);
	bool dato2 = p.altaUsuario(aux);
	bool dato3 = p.baja_usuaario(aux);
	assert(dato == true);
	assert(dato == false);
}

void test_baja_usuario()
{
	Usuario aux("XXX",-1, "XXX@YYY.es", "ZZZZ");
	Programa p;
	bool dato = p.altaUsuario(aux);
	bool dato2 = p.baja_usuaario(aux);
	assert(dato == true);
	assert(dato2 == false);
}

void test_cambiar_usuario()
{
	Usuario aux("XXX",-1, "XXX@YYY.es", "ZZZZ");
	Programa p;
	bool dato = p.altaUsuario(aux);
	p.setNombre("WWWWW");
	bool dato2 = p.cambiar_usuario(aux);
	Usuario aux2("adfasdf",-1, "XXX@YYY.es", "ZZZZ");
	bool dato4 = p.cambiar_usuario(aux2);
	bool dato3 = p.baja_usuaario(aux);
	bool dato5 = p.baja_usuaario(aux);
	assert(dato == true);
	assert(dato2 == true);
	assert(dato3 == true);
	assert(dato4 == false);
	assert(dato5 == false);
}
