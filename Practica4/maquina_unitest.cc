
#include "maquina.h"
#include "usuario.h"
#include "gtest/gtest.h"

TEST(maquina, comprobarMaquina) {
maquina m(1,1);
maquina m2(2,3);
maquina m3(7,4);

EXPECT_FALSE(m3.comprobarReserva());
EXPECT_TRUE(m2.comprobarReserva());
EXPECT_TRUE(m.comprobarReserva());

}

TEST(usuario, identificarse) {
	usuario u1();
 	usuario u2();
 	usuario aux2("fernando","1234","fer@gmail.com","fernandoLopez",3,2,123456789,1);
 	usuario aux("","","","",0,0,0,0);
 	
 	EXPECT_EQ(aux, u1.identificarse("fallo","9999"));
 	EXPECT_EQ(aux2, u2.identificarse("fernando","1234"));
}
