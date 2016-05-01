#include "DataBase.h"

//-------============================================-----------
//                       GLOBAL
//----------===================================-----------------

std::vector<Card*> DataBase::db_cards;

//Le id, abre outro bd, retorna seus valores, e coloca em X cartas, onde X é o valor da coluna NUM

std::vector<Card*> DataBase::Init(std::string i){

   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc, rc2;
   std::string sql;
   std::string name_db = "cards.db";
   //Junção das strings para descobrir endereço do bd
   std::string ad = "etc/DataBase/";
   // Open database 
   rc = sqlite3_open((ad+name_db).c_str(), &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }
   sql = "ATTACH DATABASE 'etc/DataBase/deck" + i +".db' AS deckfile";
   rc = sqlite3_exec(db, sql.data(), NULL, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sql = "SELECT * from cards join deckfile.deck using (id)";
   // Execute SQL statement 
   rc = sqlite3_exec(db, sql.data(), callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   sqlite3_close(db);   
   
   return db_cards;
 } 

int DataBase::callback(void *NotUsed, int argc, char **argv, char **azColName){
   for (int i=0; i < atoi(argv[10]); i++)
      db_cards.push_back(new Card(argv));
   return 0;
}