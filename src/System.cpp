//==============================================================================
#include "System.h"
#include "Log.h"

System System::Instance;

//==============================================================================
System::System() {
}

//------------------------------------------------------------------------------
void System::OnEvent(SDL_Event* Event) {
	gameObjects[2][0]->Update(Event);
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
		"Pedro Lima Gebao",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
	) == NULL) {
		Log("[ERRO] Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}
	SDL_SetWindowFullscreen(Window,SDL_WINDOW_FULLSCREEN);

	PrimarySurface = SDL_GetWindowSurface(Window);
	
	if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
	    Log("[ERRO] Unable to create renderer");
	    return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		
	SDL_DisplayMode current;
	if (SDL_GetCurrentDisplayMode(0, &current) != 0){
		  SDL_Log("Could not get display mode for video display #%d: %s", 0, SDL_GetError());
		  return false;
	}
	
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
	monitor = (float) current.w/(float)WindowWidth;
	gameObjects.resize(3);
	//Log("[ OK ] sdl2-engine initialized.");
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
void System::Cleanup() {
	TextureBank::Cleanup();

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}
	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}
	IMG_Quit();
	SDL_Quit();
	Log("[ OK ] System cleaned");
}

//------------------------------------------------------------------------------
int System::Execute(){ return Execute(&Running); }

int System::Execute(bool *conditional) {
	SDL_Event Event;

	while(*conditional) {
		while(SDL_PollEvent(&Event) != 0) {
			OnEvent(&Event);
			if(Event.type == SDL_QUIT) 
				Running = false;
			}	
		Loop();
		Render();
		SDL_Delay(17); // Breath
	}
	Cleanup();
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

float System::GetMonitor(){
	return monitor;
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
