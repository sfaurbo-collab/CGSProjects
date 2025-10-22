#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"

int DISPLAY_WIDTH = 1280;
int DISPLAY_HEIGHT = 720;
int DISPLAY_SCALE = 1;

enum Agent8State
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
//void UpdateFan();
void UpdateTools();
void UpdateCoinsandStars();
//void UpdateLasers();
//void UpdateDestroyed();
//void UpdateAgent8();

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
	Play::CentreAllSpriteOrigins();
	Play::LoadBackground("Data\\Backgrounds\\background.png");
	Play::StartAudioLoop("music");
	//Play::CreateGameObject(TYPE_AGENT8, { 115, 600 }, 50, "agent8");
	//int id_fan = Play::CreateGameObject(TYPE_FAN, { 1140, 503 }, 0, "fan");
	//Play::GetGameObject(id_fan).velocity = { 0, -3 };
	//Play::GetGameObject(id_fan).animSpeed = 1.0f;
	Play::CreateGameObject(TYPE_PADDLEL, { 100, DISPLAY_HEIGHT / 2 }, 50, "PaddleL");
	Play::CreateGameObject(TYPE_PADDLER, { 1180, DISPLAY_HEIGHT / 2 }, 50, "PaddleR");
	int id_ball = Play::CreateGameObject(TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, 50, "ball");
	Play::GetGameObject(id_ball).velocity = { 2, 1 };
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{	
	Play::DrawBackground();
	//UpdateAgent8();
	//UpdateFan();
	HandlePlayerControls();
	UpdateBall();
	UpdateTools();
	UpdateCoinsandStars();
	//UpdateLasers();
	//UpdateDestroyed();
	Play::DrawFontText("32px", "LEFT SIDE: W = UP, S = DOWN. RIGHT SIDE: ARROW KEYS TO MOVE UP AND DOWN",
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
	//GameObject& obj_agent8 = Play::GetGameObjectByType(TYPE_AGENT8);
	//if (Play::KeyDown(Play::KEY_UP))
	//{
	//	obj_agent8.velocity = { 0, 4 };
	//	Play::SetSprite(obj_agent8, "agent8_climb", 0.25f);
	//}
	//else if (Play::KeyDown(Play::KEY_DOWN))
	//{
	//	obj_agent8.acceleration = { 0, -1 };
	//	Play::SetSprite(obj_agent8, "agent8_fall", 0);
	//}
	//else
	//{
	//	if (obj_agent8.velocity.y < -5)
	//	{
	//		gameState.agentState = STATE_HALT;
	//		Play::SetSprite(obj_agent8, "agent8_halt", 0.333f);
	//		obj_agent8.acceleration = { 0, 0 };
	//	}
	//	else
	//	{
	//		Play::SetSprite(obj_agent8, "agent8_hang", 0.02f);
	//		obj_agent8.velocity *= 0.5f;
	//		obj_agent8.acceleration = { 0, 0 };
	//	}
	//}
	//if (Play::KeyPressed(Play::KEY_SPACE))
	//{
	//	Vector2D firePos = obj_agent8.pos + Vector2D(155, 75);
	//	int id = Play::CreateGameObject(TYPE_LASER, firePos, 30, "laser");
	//	Play::GetGameObject(id).velocity = { 32, 0 };
	//	//Play::PlayAudio("shoot");
	//}
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

	if (Play::IsLeavingDisplayArea(obj_ball))
	{
		obj_ball.pos = obj_ball.oldPos;

		double minX = obj_ball.radius;
		double maxX = 1280.0 - obj_ball.radius;
		double minY = obj_ball.radius;
		double maxY = 720.0 - obj_ball.radius;

		if (obj_ball.pos.x < minX || obj_ball.pos.x > maxX)
		{
			obj_ball.velocity.x *= -1;
			//if (obj_ball.pos.x < minX) obj_ball.pos.x = minX;
			//if (obj_ball.pos.x > maxX) obj_ball.pos.x = maxX;
		}

		if (obj_ball.pos.y < minY || obj_ball.pos.y > maxY)
		{
			obj_ball.velocity.y *= -1;
			//if (obj_ball.pos.y < minY) obj_ball.pos.y = minY;
			//if (obj_ball.pos.y > maxY) obj_ball.pos.y = maxY;
		}
	}
	Play::DrawObject(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleL))
	{
		obj_ball.velocity = { -1, -1 };
		//obj_ball.velocity.x *= -1;
		//obj_ball.velocity.y *= -1;
	}
	Play::UpdateGameObject(obj_ball);

	if (Play::IsColliding(obj_ball, obj_paddleR))
	{
		obj_ball.velocity = { -1, -1 };
		//obj_ball.velocity.x *= 1;
		//obj_ball.velocity.y *= -1;
	}
	Play::UpdateGameObject(obj_ball);
}


//void UpdateFan()
//{
//	GameObject& obj_fan = Play::GetGameObjectByType(TYPE_FAN);
//	if (Play::RandomRoll(50) == 50)
//	{
//		int id = Play::CreateGameObject(TYPE_TOOL, obj_fan.pos, 50, "driver");
//		GameObject& obj_tool = Play::GetGameObject(id);
//		obj_tool.velocity = Point2f(-8, Play::RandomRollRange(-1, 1) * 6);
//		
//		if (Play::RandomRoll(2) == 1)
//		{
//			Play::SetSprite(obj_tool, "spanner", 0);
//			obj_tool.radius = 100;
//			obj_tool.velocity.x = -4;
//			obj_tool.rotSpeed = 0.1f;
//		}
//		//Play::PlayAudio("tool");
//	}
//	if (Play::RandomRoll(150) == 1)
//	{
//		int id = Play::CreateGameObject(TYPE_COIN, obj_fan.pos, 40, "coin");
//		GameObject& obj_coin = Play::GetGameObject(id);
//		obj_coin.velocity = { -3, 0 };
//		obj_coin.rotSpeed = 0.1f;
//	}
//	Play::UpdateGameObject(obj_fan);
//	
//	if (Play::IsLeavingDisplayArea(obj_fan))
//	{
//		obj_fan.pos = obj_fan.oldPos;
//		obj_fan.velocity.y *= -1;
//	}
//	Play::DrawObject(obj_fan);
//}

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

//void UpdateLasers()
//{
//	std::vector<int> vLasers = Play::CollectGameObjectIDsByType(TYPE_LASER);
//	std::vector<int> vTools = Play::CollectGameObjectIDsByType(TYPE_TOOL);
//	std::vector<int> vCoins = Play::CollectGameObjectIDsByType(TYPE_COIN);
//	
//	for (int id_laser : vLasers)
//	{
//		GameObject& obj_laser = Play::GetGameObject(id_laser);
//		bool hasCollided = false;
//		for (int id_tool : vTools)
//		{
//			GameObject& obj_tool = Play::GetGameObject(id_tool);
//			if (Play::IsColliding(obj_laser, obj_tool))
//			{
//				hasCollided = true;
//				obj_tool.type = TYPE_DESTROYED;
//				gameState.scoreP1 += 100;
//			}
//		}
//		
//		for (int id_coin : vCoins)
//		{
//			GameObject& obj_coin = Play::GetGameObject(id_coin);
//			if (Play::IsColliding(obj_laser, obj_coin))
//			{
//				hasCollided = true;
//				obj_coin.type = TYPE_DESTROYED;
//				//Play::PlayAudio("error");
//				gameState.scoreP1 -= 300;
//			}
//		}
//		if (gameState.scoreP1 < 0)
//			gameState.scoreP1 = 0;
//		
//		Play::UpdateGameObject(obj_laser);
//		Play::DrawObject(obj_laser);
//		
//		if (!Play::IsVisible(obj_laser) || hasCollided)
//			Play::DestroyGameObject(id_laser);
//	}
//}
//
//void UpdateDestroyed()
//{
//	std::vector<int> vDead = Play::CollectGameObjectIDsByType(TYPE_DESTROYED);
//	
//	for (int id_dead : vDead)
//	{
//		GameObject& obj_dead = Play::GetGameObject(id_dead);
//		obj_dead.animSpeed = 0.2f;
//		Play::UpdateGameObject(obj_dead);
//		
//		if (obj_dead.frame % 2)
//			Play::DrawObjectRotated(obj_dead, (10 - obj_dead.frame) / 10.0f);
//		
//		if (!Play::IsVisible(obj_dead) || obj_dead.frame >= 10)
//			Play::DestroyGameObject(id_dead);
//	}
//}
//void UpdateAgent8()
//{
//	GameObject& obj_agent8 = Play::GetGameObjectByType(TYPE_AGENT8);
//	
//	switch (gameState.agentState)
//	{
//	case STATE_APPEAR:
//		obj_agent8.velocity = { 0, -12 };
//		obj_agent8.acceleration = { 0, -0.5f };
//		Play::SetSprite(obj_agent8, "agent8_fall", 0);
//		obj_agent8.rotation = 0;
//		if (obj_agent8.pos.y <= DISPLAY_HEIGHT * 0.66f)
//			gameState.agentState = STATE_PLAY;
//		break;
//	
//	case STATE_HALT:
//		obj_agent8.velocity *= 0.9f;
//		if (Play::IsAnimationComplete(obj_agent8))
//			gameState.agentState = STATE_PLAY;
//		break;
//	
//	case STATE_PLAY:
//		HandlePlayerControls();
//		break;
//	
//	case STATE_DEAD:
//		obj_agent8.acceleration = { -0.3f , 0.5f };
//		obj_agent8.rotation += 0.25f;
//		if (Play::KeyPressed(Play::KEY_SPACE) == true)
//		{
//			gameState.agentState = STATE_APPEAR;
//			obj_agent8.pos = { 115, 600 };
//			obj_agent8.velocity = { 0, 0 };
//			obj_agent8.frame = 0;
//			Play::StartAudioLoop("music");
//			gameState.scoreP1 = 0;
//			
//			for (int id_obj : Play::CollectGameObjectIDsByType(TYPE_TOOL))
//				Play::GetGameObject(id_obj).type = TYPE_DESTROYED;
//		}
//		break;
//	
//	} // End of switch on Agent8State
//	
//	Play::UpdateGameObject(obj_agent8);
//	
//	if (Play::IsLeavingDisplayArea(obj_agent8) && gameState.agentState != STATE_DEAD)
//		obj_agent8.pos = obj_agent8.oldPos;
//	
//	Play::DrawLine({ obj_agent8.pos.x, 720 }, obj_agent8.pos, Play::cWhite);
//	Play::DrawObjectRotated(obj_agent8);
//}