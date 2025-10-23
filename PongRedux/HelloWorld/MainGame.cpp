#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

enum Agent8State //StateOfGame. --> look at this to reset when a score is made
{
	STATE_APPEAR = 0,
	STATE_HALT,
	STATE_PLAY,
	STATE_DEAD,
};

struct GameState
{
	int scoreP1{ 0 };
	int scoreP2{ 0 };
	Agent8State agentState{ STATE_APPEAR };
};

GameState gameState;

enum GameObjectType
{
	TYPE_NULL = -1,
	TYPE_AGENT8,
	TYPE_FAN,
	TYPE_TOOL,
	TYPE_COIN,
	TYPE_STAR,
	TYPE_LASER,
	TYPE_DESTROYED,
	TYPE_PADDLEL,
	TYPE_PADDLER,
	TYPE_BALL,
};

void HandlePlayerControls();
void UpdateBall();
void UpdateTools();
void UpdateCoinsandStars();
void UpdateAgent8();

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
	UpdateCoinsandStars();
	UpdateAgent8();
	Play::DrawFontText("32px", "LEFT SIDE: W = UP, S = DOWN.                RIGHT SIDE: ARROW KEYS TO MOVE UP AND DOWN",
		{ DISPLAY_WIDTH / 2, 40 }, Play::CENTRE);
	Play::DrawFontText("32px", "Player 1 SCORE: " + std::to_string(gameState.scoreP1),
		{ 150, DISPLAY_HEIGHT - 40 }, Play::CENTRE);
	Play::DrawFontText("32px", "Player 2 SCORE: " + std::to_string(gameState.scoreP2),
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

	if (Play::RandomRoll(500) == 1)
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

	if (Play::RandomRoll(500) == 1)
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
			gameState.scoreP1 += 1;
			obj_ball.velocity = { 0, 0 };
		}
		else if (obj_ball.pos.x > maxX)
		{
			gameState.scoreP2 += 1;
			obj_ball.velocity = { 0, 0 };
		}
	}
	Play::DrawObjectRotated(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleL))
	{
		obj_ball.velocity = { -1, -1 };
	}
	Play::UpdateGameObject(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleR))
	{
		obj_ball.velocity = { -1, -1 };
	}
	Play::UpdateGameObject(obj_ball);
}

void UpdateTools()
{
	GameObject& obj_agent8 = Play::GetGameObjectByType(TYPE_AGENT8);
	std::vector<int> vTools = Play::CollectGameObjectIDsByType(TYPE_TOOL);
	
	for (int id : vTools)
	{
		GameObject& obj_tool = Play::GetGameObject(id);
		
		if (gameState.agentState != STATE_DEAD && Play::IsColliding(obj_tool, obj_agent8))
		{
			//Play::StopAudio("music");
			//Play::PlayAudio("die");
			gameState.agentState = STATE_DEAD;
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

void UpdateCoinsandStars()
{
	GameObject& obj_agent8 = Play::GetGameObjectByType(TYPE_AGENT8);
	std::vector<int> vCoins = Play::CollectGameObjectIDsByType(TYPE_COIN);
	
	for (int id_coin : vCoins)
	{
		GameObject& obj_coin = Play::GetGameObject(id_coin);
		bool hasCollided = false;
		
		if (Play::IsColliding(obj_coin, obj_agent8))
		{
			for (float rad{ 0.25f }; rad < 2.0f; rad += 0.5f)
			{
				int id = Play::CreateGameObject(TYPE_STAR, obj_agent8.pos, 0, "star");
				GameObject& obj_star = Play::GetGameObject(id);
				obj_star.rotSpeed = 0.1f;
				obj_star.acceleration = { 0.0f, -0.5f };
				Play::SetGameObjectDirection(obj_star, 16, rad * PLAY_PI);
			}
			
			hasCollided = true;
			gameState.scoreP1 += 500;
			Play::PlayAudio("collect");
		}

		Play::UpdateGameObject(obj_coin);
		Play::DrawObjectRotated(obj_coin);
		
		if (!Play::IsVisible(obj_coin) || hasCollided)
			Play::DestroyGameObject(id_coin);
	}

	std::vector<int> vStars = Play::CollectGameObjectIDsByType(TYPE_STAR);
	
	for (int id_star : vStars)
	{
		GameObject& obj_star = Play::GetGameObject(id_star);
		
		Play::UpdateGameObject(obj_star);
		Play::DrawObjectRotated(obj_star);
		
		if (!Play::IsVisible(obj_star))
			Play::DestroyGameObject(id_star);
	}
}

void UpdateAgent8()
{
	GameObject& obj_agent8 = Play::GetGameObjectByType(TYPE_AGENT8);

	switch (gameState.agentState)
	{
	case STATE_APPEAR:
		obj_agent8.velocity = { 0, -12 };
		obj_agent8.acceleration = { 0, -0.5f };
		Play::SetSprite(obj_agent8, "agent8_fall", 0);
		obj_agent8.rotation = 0;
		if (obj_agent8.pos.y <= DISPLAY_HEIGHT * 0.66f)
			gameState.agentState = STATE_PLAY;
		break;

	case STATE_HALT:
		obj_agent8.velocity *= 0.9f;
		if (Play::IsAnimationComplete(obj_agent8))
			gameState.agentState = STATE_PLAY;
		break;

	case STATE_PLAY:
		HandlePlayerControls();
		break;

	case STATE_DEAD:
		obj_agent8.acceleration = { -0.3f, 0.5f };
		obj_agent8.rotation += 0.25f;
		if (Play::KeyPressed(Play::KEY_SPACE) == true)
		{
			gameState.agentState = STATE_APPEAR;
			obj_agent8.pos = { 115, 600 };
			obj_agent8.velocity = { 0, 0 };
			obj_agent8.frame = 0;
			Play::StartAudioLoop("music");
			//gameState.score = 0;

			for (int id_obj : Play::CollectGameObjectIDsByType(TYPE_TOOL))
				Play::GetGameObject(id_obj).type = TYPE_DESTROYED;
		}
		break;
	}

	Play::UpdateGameObject(obj_agent8);

	if (Play::IsLeavingDisplayArea(obj_agent8) && gameState.agentState != STATE_DEAD)
		obj_agent8.pos = obj_agent8.oldPos;

	Play::DrawLine({ obj_agent8.pos.x, 720 }, obj_agent8.pos, Play::cWhite);
	Play::DrawObjectRotated(obj_agent8);
}