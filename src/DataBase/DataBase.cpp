#include "DataBase.h"

//-------============================================-----------
//                       GLOBAL
//----------===================================-----------------

std::vector<Card*> DataBase::db_cards;


std::vector<Card*> DataBase::Init(std::string address){

   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   std::string sql;
   //Junção das strings para descobrir endereço do bd
   std::string ad = "etc/DataBase/";
   /* Open database */
   rc = sqlite3_open((ad+address).c_str(), &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   sql = "SELECT * from CARTAS";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql.data(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sqlite3_close(db);   
   
   return db_cards;
 } 

/*
Le id, abre outro bd, retorna seus valores, e coloca em X cartas, onde X é o valor da coluna NUM

std::vector<Card*> DataBase::Init(int i){

   sqlite3 *db, *deck;
   char *zErrMsg = 0;
   int  rc, deck;
   std::string sql;
   //Junção das strings para descobrir endereço do bd
   std::string ad = "etc/DataBase/";
   /* Open database 
   rc = sqlite3_open((ad+"cartas.db").c_str(), &db);
   deck = sqlite3_open((ad+"deck"+ i.to_string() + ".db").c_str(), &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   sql = "SELECT * from CARTAS join DECK using (id)";

   /* Execute SQL statement 
   rc = sqlite3_exec(db, sql.data(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sqlite3_close(db);   
   
   return db_cards;
 } 

*/

int DataBase::callback(void *NotUsed, int argc, char **argv, char **azColName){
   
   db_cards.push_back(new Card(argv));
   return 0;
}