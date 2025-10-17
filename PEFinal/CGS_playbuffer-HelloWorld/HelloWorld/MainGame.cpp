#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

struct GameState
{
	int score{ 0 };
};

GameState gameState;

enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_PADDLEL,
	TYPE_PADDLER,
	TYPE_BALL
};

void HandlePlayerControls();
void UpdateBall();

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\pong_background.png");
	Play::StartAudioLoop("chill-beats-185843");
	Play::CreateGameObject(TYPE_PADDLEL, { 100, DISPLAY_HEIGHT/2 }, 50, "PaddleL");
	Play::CreateGameObject(TYPE_PADDLER, { 1180, DISPLAY_HEIGHT/2 }, 50, "PaddleR");
	int id_ball = Play::CreateGameObject(TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, 0, "ball");
	Play::GetGameObject(id_ball).velocity = { 3, -3 };
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::DrawBackground();
	HandlePlayerControls();
	UpdateBall();
	Play::PresentDrawingBuffer();
	return Play::KeyDown( KEY_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}

void HandlePlayerControls()
{
	GameObject& obj_paddleL = Play::GetGameObjectByType(TYPE_PADDLEL);
	if (Play::KeyDown(Play::KEY_W))
	{
		obj_paddleL.velocity = { 0, 10 };
		obj_paddleL.acceleration = { 0, 1 };
		Play::SetSprite(obj_paddleL, "PaddleL", 0);
	}
	else if (Play::KeyDown(Play::KEY_S))
	{
		obj_paddleL.velocity = { 0, -10 };
		obj_paddleL.acceleration = { 0, -1 };
		Play::SetSprite(obj_paddleL, "PaddleL", 0);
	}
	else
	{
		Play::SetSprite(obj_paddleL, "PaddleL", 0.02f);
		obj_paddleL.velocity *= 0.5f;
		obj_paddleL.acceleration = { 0, 0 };
	}
	Play::UpdateGameObject(obj_paddleL);

	if (Play::IsLeavingDisplayArea(obj_paddleL))
		obj_paddleL.pos = obj_paddleL.oldPos;

	Play::DrawObjectRotated(obj_paddleL);

	GameObject& obj_paddleR = Play::GetGameObjectByType(TYPE_PADDLER);
	if (Play::KeyDown(Play::KEY_UP))
	{
		obj_paddleR.velocity = { 0, 10 };
		obj_paddleR.acceleration = { 0, 1 };
		Play::SetSprite(obj_paddleR, "PaddleR", 0);
	}
	else if (Play::KeyDown(Play::KEY_DOWN))
	{
		obj_paddleR.velocity = { 0, -10 };
		obj_paddleR.acceleration = { 0, -1 };
		Play::SetSprite(obj_paddleR, "PaddleR", 0);
	}
	else
	{
		Play::SetSprite(obj_paddleR, "PaddleR", 0.02f);
		obj_paddleR.velocity *= 0.5f;
		obj_paddleR.acceleration = { 0, 0 };
	}

	Play::UpdateGameObject(obj_paddleR);

	if (Play::IsLeavingDisplayArea(obj_paddleR))
		obj_paddleR.pos = obj_paddleR.oldPos;

	Play::DrawObjectRotated(obj_paddleR);
}

void UpdateBall()
{
	GameObject& obj_ball = Play::GetGameObjectByType(TYPE_BALL);
	//obj_ball.velocity = { -10, -10 };
	Play::DrawObject(obj_ball);
}