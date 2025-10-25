#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

enum PlayState //StateOfGame. --> look at this to reset when a score is made
{
	STATE_APPEAR = 0,
	STATE_HALT,
	STATE_PLAY,
	STATE_RESET_LEFT,
	STATE_RESET_RIGHT,
};

struct GameState
{
	int scoreP1{ 0 };
	int scoreP2{ 0 };
	PlayState pongState{ STATE_APPEAR };
};

GameState gameState;

enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_TOOL,
	TYPE_COIN,
	TYPE_STAR,
	TYPE_PADDLEL,
	TYPE_PADDLER,
	TYPE_BALL,
};

void HandlePlayerControls();
void UpdateBall();
void UpdateTools();
void UpdatePong();

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\background.png");
	Play::StartAudioLoop("music");
	Play::CreateGameObject(TYPE_PADDLEL, { 100, DISPLAY_HEIGHT / 2 }, 50, "PaddleL");
	Play::CreateGameObject(TYPE_PADDLER, { 1180, DISPLAY_HEIGHT / 2 }, 50, "PaddleR");
	int id_ball = Play::CreateGameObject(TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, 50, "ball");
	Play::GetGameObject(id_ball).velocity = { 1, 1 };
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{	
	Play::DrawBackground();
	HandlePlayerControls();
	UpdateBall();
	UpdateTools();
	UpdatePong();
	Play::DrawFontText("32px", "LEFT SIDE: W = UP, S = DOWN.                RIGHT SIDE: ARROW KEYS TO MOVE UP AND DOWN",
		{ DISPLAY_WIDTH / 2, 40 }, Play::CENTRE);
	Play::DrawFontText("32px", "Press Space to Reset after someone scores.",
		{ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 40 }, Play::CENTRE);
	Play::DrawFontText("64px", "SCORE: " + std::to_string(gameState.scoreP1),
		{ 150, DISPLAY_HEIGHT - 40 }, Play::CENTRE);
	Play::DrawFontText("64px", "SCORE: " + std::to_string(gameState.scoreP2),
		{ 1130, DISPLAY_HEIGHT - 40 }, Play::CENTRE);
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
	GameObject& obj_paddleL = Play::GetGameObjectByType(TYPE_PADDLEL);
	GameObject& obj_paddleR = Play::GetGameObjectByType(TYPE_PADDLER);

	if (Play::RandomRoll(1000) == 1)
	{
		int id = Play::CreateGameObject(TYPE_TOOL, obj_ball.pos, 50, "driver");
		GameObject& obj_ball = Play::GetGameObject(id);
		obj_ball.velocity = Point2f(-4, Play::RandomRollRange(-1, 1) * 6);

		if (Play::RandomRoll(100) == 1)
		{
			Play::SetSprite(obj_ball, "spanner", 0);
			obj_ball.radius = 100;
			obj_ball.velocity.x = -1;
			obj_ball.rotSpeed = 0.1f;
		}
		Play::PlayAudio("tool");
	}
	Play::UpdateGameObject(obj_ball);

	if (Play::RandomRoll(1000) == 1)
	{
		int id = Play::CreateGameObject(TYPE_TOOL, obj_ball.pos, 50, "driver");
		GameObject& obj_ball = Play::GetGameObject(id);
		obj_ball.velocity = Point2f(4, Play::RandomRollRange(-1, 1) * 6);

		if (Play::RandomRoll(100) == 1)
		{
			Play::SetSprite(obj_ball, "spanner", 0);
			obj_ball.radius = 100;
			obj_ball.velocity.x = -1;
			obj_ball.rotSpeed = 0.1f;
		}
		Play::PlayAudio("tool");
	}
	Play::UpdateGameObject(obj_ball);

	if (Play::IsLeavingDisplayArea(obj_ball, Play::VERTICAL))
	{
		obj_ball.pos = obj_ball.oldPos;
		obj_ball.velocity.y *= -1;
	}
	Play::DrawObjectRotated(obj_ball);

	if (Play::IsLeavingDisplayArea(obj_ball, Play::HORIZONTAL))
	{
		obj_ball.pos = obj_ball.oldPos;
		double minX = obj_ball.radius;
		double maxX = 1280.0 - obj_ball.radius;
		
		if (obj_ball.pos.x < minX)
		{
			gameState.scoreP2 += 1;
			obj_ball.velocity = { 0, 0 };
			Play::StopAudio("music");
		}
		else if (obj_ball.pos.x > maxX)
		{
			gameState.scoreP1 += 1;
			obj_ball.velocity = { 0, 0 };
			Play::StopAudio("music");
		}
	}
	Play::DrawObjectRotated(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleL))
	{
		if (obj_ball.velocity.y == -1)
		{
			obj_ball.velocity = { 1, -1 };
		}
		else if (obj_ball.velocity.y == 1)
		{
			obj_ball.velocity = { 1, 1 };
		}
	}
	Play::UpdateGameObject(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleR))
	{
		if (obj_ball.velocity.y == -1)
		{
			obj_ball.velocity = { -1, -1 };
		}
		else if (obj_ball.velocity.y == 1)
		{
			obj_ball.velocity = { -1, 1 };
		}
	}
	Play::UpdateGameObject(obj_ball);
}

void UpdateTools()
{
	GameObject& obj_ball = Play::GetGameObjectByType(TYPE_BALL);
	std::vector<int> vTools = Play::CollectGameObjectIDsByType(TYPE_TOOL);
	
	for (int id : vTools)
	{
		GameObject& obj_tool = Play::GetGameObject(id);
		
		if (gameState.pongState != STATE_RESET_LEFT && Play::IsColliding(obj_tool, obj_ball))
		{
			gameState.pongState = STATE_RESET_LEFT;
		}
		if (gameState.pongState != STATE_RESET_RIGHT && Play::IsColliding(obj_tool, obj_ball))
		{
			gameState.pongState = STATE_RESET_RIGHT;
		}
		Play::UpdateGameObject(obj_tool);
		
		if (Play::IsLeavingDisplayArea(obj_tool, Play::VERTICAL))
		{
			obj_tool.pos = obj_tool.oldPos;
			obj_tool.velocity.y *= -1;
		}
		Play::DrawObjectRotated(obj_tool);
		
		if (!Play::IsVisible(obj_tool))
			Play::DestroyGameObject(id);
	}
}

void UpdatePong()
{
	GameObject& obj_ball = Play::GetGameObjectByType(TYPE_BALL);

	switch (gameState.pongState)
	{
	case STATE_PLAY:
		HandlePlayerControls();
		break;

	case STATE_RESET_LEFT:
		if (Play::KeyPressed(Play::KEY_SPACE) == true)
		{
			obj_ball.pos = { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 };
			obj_ball.frame = 0;
			Play::StopAudio("music");
			Play::StartAudioLoop("music");
			if (gameState.scoreP1 > gameState.scoreP2)
			{
				obj_ball.velocity = { 1, 1 };
			}
			else
			{
				obj_ball.velocity = { -1, -1 };
			}
		}
		break;

	case STATE_RESET_RIGHT:
		if (Play::KeyPressed(Play::KEY_SPACE) == true)
		{
			obj_ball.pos = { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 };
			obj_ball.frame = 0;
			Play::StopAudio("music");
			Play::StartAudioLoop("music");
			if (gameState.scoreP2 > gameState.scoreP1)
			{
				obj_ball.velocity = { -1, -1 };
			}
			else
			{
				obj_ball.velocity = { 1, 1 };
			}
		}
		break;
	}

	Play::UpdateGameObject(obj_ball);

	Play::DrawObjectRotated(obj_ball);
}