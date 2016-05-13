#undef main
//==============================================================================
/*
	Run the System from here!
*/
//==============================================================================
#include "System.h"
#include "GameControl.h"
#include <cstdlib>
#include <ctime>

using namespace std;


int main(int argc, char* argv[]) {
	// Escolhe uma carta aleatoria pra mostrar
	/*srand(time(NULL));
	char num[4];
	sprintf(num,"%d",(rand()%153)+1);*/
	// Salva a instancia do sistema
	System* sys = System::GetInstance();
	// Se o sistema conseguir inicializar com sucesso
	if (sys->Init()){
		// Carrega pasta de imagens
		//TextureBank::LoadFolder("Textures/Cards_bd");
		// Cria gameObjects
		//GameObject* Mario = new GameObject("Test");
		//GameObject* Card = new GameObject(num);
		// add gameoObjects as rotinas render e update
		//sys->AddGameObject(Mario);
		//sys->AddGameObject(Card);
		// Define Tela Cheia
		sys->SetFullScreen();
		GameControl* gc = new GameControl();
		gc->Run();
		//sys->SetGameControl(gc);
		// Seta a posição da carta na tela
		//Card->SetPos(600,100);
		//Card->resize(0.5);
		// Executa o jogo até a primeira tentativa de fechamento da janela
		//sys->Execute();
		// Remove a carta das rotinas de render e update, libera memoria
		//sys->RemGameObject(Card);
		//delete Card;
		// Redimensiona a janela (perde Fullscreen)
		//sys->ResizeWindow(648,480);
		// Executa de novo até ser fechado
		//sys->Execute();
		// Fecha sistema e limpa tudo (do sistema)
		sys->Quit();
		// Não esqueça de liberar memória a qual você alocou!
		//delete Mario;
	}
	return 0;
}
