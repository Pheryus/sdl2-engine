#include "Card.h"

//int* atrib, int* cost, char* nam, char* typ, char* sec_typ, char* des

Card::Card(char** argv){
		id_card = atoi(argv[0]);
		name = argv[1];
		type = argv[2];
		color = argv[3];
		pri_cost = atoi(argv[4]);
		res = argv[5] ? atoi(argv[5]) : -1;
		sec_cost = argv[6] ? atoi(argv[6]) : -1;
		power = argv[8] ? atoi(argv[8]) : -1;
		lt = argv[7] ? atoi(argv[7]) : -1;
		desc = argv[9] ? argv[9] : "";
}

void Card::print (){
	cout << "Nome " << name << endl;
	cout << "Tipo " << type << endl;
	cout << "Cor " << color << endl;
	cout << "Desc " << desc << endl;
	cout << "Pow " << power << endl;
	cout << "Lt " << lt << endl;
	cout << "Res " << res << endl;
	cout << "cost " << pri_cost << endl;
	cout << "carga " << sec_cost << endl;
}
