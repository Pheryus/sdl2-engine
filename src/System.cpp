//==============================================================================
#include "System.h"
#include "Log.h"

System System::Instance;

//==============================================================================
System::System() {
}

//------------------------------------------------------------------------------
void System::OnEvent(SDL_Event* Event) {
	if(Event.type == SDL_QUIT) Running = false;
	else{
		
	}
}

//------------------------------------------------------------------------------
bool System::Init() {
	Log("[ .. ] Initializing sdl2-engine...")
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		Log("[ERRO] Unable to Init SDL: %s", SDL_GetError());
		return false;
	}

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Log("[ERRO] Unable to Init hinting: %s", SDL_GetError());
		return false;
	}

	if((Window = SDL_CreateWindow(
		"My SDL Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
	) == NULL) {
		Log("[ERRO] Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}

	PrimarySurface = SDL_GetWindowSurface(Window);

	if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
	    Log("[ERRO] Unable to create renderer");
	    return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	// Initialize image loading for PNGs
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		Log("[ERRO] Unable to init SDL_image: %s", IMG_GetError());
		return false;
	}

	// Load all of our Textures (see TextureBank class for expected folder)
	if(TextureBank::Init() == false) {
		Log("[ERRO] Unable to init TextureBank");
		return false;
	}

	gameObjects.resize(2);

	Log("[ OK ] sdl2-engine initialized.");

	return true;
}

//------------------------------------------------------------------------------
void System::Loop() {
	for (int i = 0; i < gameObjects.size(); i++){
		int j = 0;
		for (GameObject* go : gameObjects[i]){
			go->Update();
			if (!go->isAlive())
				gameObjects[i].erase(gameObjects[i].begin()+j);
			j++;
		}
	}
}

//------------------------------------------------------------------------------
void System::Render() {
	SDL_RenderClear(Renderer);

	//TextureBank::Get("Test")->Render(0, 0); // You should really check your pointers
	for (int i=0; i<gameObjects.size(); i++)
		for (int j=0; j<gameObjects[i].size(); j++)
			gameObjects[i][j]->Render();

	SDL_RenderPresent(Renderer);
}

//------------------------------------------------------------------------------
void System::Quit() {
	TextureBank::Cleanup();

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}
	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}
	for (int i=0; i<gameObjects.size(); i++)
		gameObjects[i].clear();
	gameObjects.clear();
	IMG_Quit();
	SDL_Quit();
	Log("[ OK ] System cleaned");
}

//------------------------------------------------------------------------------
int System::Execute(){ return Execute(&Running); }

int System::Execute(bool *conditional) {
	SDL_Event Event;

	while(*conditional) {
		while(SDL_PollEvent(&Event))
			OnEvent(&Event);
		Loop();
		Render();
		SDL_Delay(17); // Breath
	}
	//Cleanup();
	return 0;
}

//==============================================================================

SDL_Renderer* System::GetRenderer() { return Renderer; }
System* System::GetInstance() { return &System::Instance; }
int System::GetWindowWidth()  { return WindowWidth; }
int System::GetWindowHeight() { return WindowHeight; }

//==============================================================================

void System::AddGameObject(GameObject* go){
	AddGameObject(go, gameObjects.size()-1);
}

void System::AddGameObject(GameObject* go, int layer){
	if (layer >= gameObjects.size())	layer = gameObjects.size()-1;
	else if (layer < 0)					layer = 0;
	gameObjects[layer].push_back(go);
}

void System::RemGameObject(GameObject* go){
	for (int i = 0; i < gameObjects.size(); i++){
		int j = 0;
		for (GameObject* it : gameObjects[i]){
			if (go == it)
				gameObjects[i].erase(gameObjects[i].begin()+j);
			j++;
		}
	}
}
