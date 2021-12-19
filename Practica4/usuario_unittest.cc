// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "usuario.h"
#include "gtest/gtest.h"

TEST(usuario, EliminarReservas) {
  usuario u1("30XX","1234","","",0,0,0,0);
  usuario u2("40XX","1234","","",0,0,0,0);
  
  ofstream salida("reservas.txt");
  salida<<"30XX,12,20 12 2021,25 12 2021,3"<<"\n";
  salida<<"30XX,11,25 11 2022,25 12 2022,3"<<"\n";
  salida<<"40XX,22,07 02 2021,09 08 2021,3"<<"\n";
  salida<<"40XX,23,11 05 2022,11 05 2022,3"<<"\n";

  EXPECT_TRUE(u1.eliminarReserva("12"));
  EXPECT_FALSE(u2.eliminarReserva("11"));
}

TEST(usuario, ConstructorParametros) {
   usuario u1("30XX","1234","","",0,0,0,0);
  
  ofstream salida("reservas.txt");
  salida<<"30XX,12,20 12 2021,25 12 2021,3"<<"\n";
  salida<<"30XX,11,25 11 2022,25 12 2022,3"<<"\n";
  salida<<"40XX,22,07 02 2021,09 08 2021,3"<<"\n";
  salida<<"40XX,23,11 05 2022,11 05 2022,3"<<"\n";

  u1.cargarReserva();
  EXPECT_EQ("30XX", u1.getListaUser().begin()->getID());
}
