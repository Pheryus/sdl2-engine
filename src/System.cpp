//==============================================================================
#include "System.h"
#include "Log.h"
#include "Event.h"

System System::Instance;

//==============================================================================
System::System() {
}

//------------------------------------------------------------------------------
void System::SeekEvents() {
	Event* ev = Event::GetInstance();
	ev->update();
	/*if (ev->QuitRequest()){}
		Running = false;
	else{
		if (ev->MouseButtonUp(SDL_BUTTON_LEFT))
			Log("Esquerdo");
	}*/
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
		monitor = (float) current.w/(float)WindowWidth;
		//Log("[ OK ] sdl2-engine initialized.");
		gameObjects.resize(2);
		gameControl = NULL;

		Log("[ OK ] sdl2-engine initialized.");
	}
}
	


//------------------------------------------------------------------------------
void System::Loop() {
	gameControl->update();
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
void System::SetFullScreen(){
	SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_GetWindowSize(Window, &WindowWidth, &WindowHeight);
}

//------------------------------------------------------------------------------
void System::ResizeWindow(int w, int h){
	if(SDL_GetWindowFlags(Window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
		SDL_SetWindowFullscreen(Window, 0);
	WindowWidth = w;
	WindowHeight = h;
	SDL_SetWindowSize(Window, WindowWidth, WindowHeight);
}

//------------------------------------------------------------------------------
int System::Execute() {

	while(gameControl->isRunning()) {
		SeekEvents();
		Loop();
		Render();
		SDL_Delay(17); // Breath
	}
	return 0;
}

//==============================================================================

SDL_Renderer* System::GetRenderer() { return Renderer; }
System* System::GetInstance() { return &System::Instance; }
int System::GetWindowWidth()  { return WindowWidth; }
int System::GetWindowHeight() { return WindowHeight; }

//==============================================================================

GameObject* convert_pointer(void* p){
	GameObject* go;
	try{
		go = (GameObject*) p;
	}
	catch (int e){
		Log("[INFO] Given pointer 0x%x can not be converted to GameObject. Ignoring...",go);
		return NULL;
	}
	return go;
}

void System::AddGameObject(void* go){
	AddGameObject(go, gameObjects.size()-1);
}

float System::GetMonitor(){
	return monitor;
}

void System::AddGameObject(void* go_p, int layer){
	GameObject* go = convert_pointer(go_p);
	if (go){
		if (layer >= gameObjects.size())	layer = gameObjects.size()-1;
		else if (layer < 0)					layer = 0;
		gameObjects[layer].push_back(go);
	}
}

void System::RemGameObject(void* go_p){
	GameObject* go = convert_pointer(go_p);
	if (go)
		for (int i = 0, j = 0; i < gameObjects.size(); i++, j=0){
			for (GameObject* it : gameObjects[i]){
				if (go == it)
					gameObjects[i].erase(gameObjects[i].begin()+j);
				j++;
			}
		}
}

void System::SetGameControl(GameControl* gc){
	gameControl = gc;
	//gc->setGameObjects(gameObjects);
}
