
#include "GameManager.h"
#include "Player.h"
#include <string>
#include "Ground.h"
#include <vector>
#include "Coin.h"
#include "Enemy.h"
#pragma comment(lib, "winmm.lib") //MAKES IT SO SOUND CAN PLAY!



using namespace std;
using namespace sf;

static const float CAMERA_HEIGHT = 600.0f;

void ResizeCamera(const RenderWindow& window, View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	//set size
	view.setSize(CAMERA_HEIGHT * aspectRatio, CAMERA_HEIGHT);

}

int main()
{

	Clock clock;



	RenderWindow window(VideoMode(CAMERA_HEIGHT, CAMERA_HEIGHT), "John and Connor's game: Sonic");
	window.setFramerateLimit(60);

	//setting view
	View view(Vector2f(0.0f, 0.0f), Vector2f(CAMERA_HEIGHT, CAMERA_HEIGHT));


	Texture backgroundTexture;
	backgroundTexture.loadFromFile("background.png");
	RectangleShape background(Vector2f(12288, 728));
	background.setTexture(&backgroundTexture);
	background.setOrigin(700, 0);

	Font hud;


	if (!hud.loadFromFile("hud-font.ttf"))
	{
		std::cout << "Error loading file" << std::endl;
		system("pause");
	}


	Texture playerTexture;
	playerTexture.loadFromFile("sonicSprSheet.png");
	Player player(&playerTexture, Vector2u(3, 3), 0.3f, 400.0f, 200.0f);
	//^^Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	//ok so, the Vector 3,3 thing above shows that there are 3 sonics on the x axis and 3 on the y axis and splits them up equally, the 0.3f is about a frame per second at 60 fps
	// speed is the second to last variable if it does need changing/testing of use
	//sound that doesn't allow any other music to be played over it, so don't bother.

	//PlaySound("GreenHillZoneMUSIC.wav", NULL, SND_FILENAME | SND_ASYNC);

	


	//set sonics UI to put it in the already made ground format, so we dont have a redudant amount of garbo classes of stuff that doesn't warrent it.
	Texture sonicLivesUI;
	sonicLivesUI.loadFromFile("sonicLiveCount.png");
	//gameover ui
	Texture gameOverSpr;
	gameOverSpr.loadFromFile("GameOverScreen.png");
	//gameover ui
	Texture gameWonSpr;
	gameWonSpr.loadFromFile("GameWinScreen.png");
	//set floor textures with the wall also since they both do the same thing!
	Texture groundTexture;
	groundTexture.loadFromFile("groundTile.png");
	Texture wallTexture;
	wallTexture.loadFromFile("WallSprite.png");
	//set Ground floor
	vector<Ground> groundTiles;
	groundTiles.push_back(Ground(&groundTexture, Vector2f(1024.0f, 84.0f), Vector2f(512.0f, 768.0f))); //ground
	groundTiles.push_back(Ground(&groundTexture, Vector2f(1024.0f, 84.0f), Vector2f(1536.0f, 768.0f))); //ground
	groundTiles.push_back(Ground(&groundTexture, Vector2f(1024.0f, 84.0f), Vector2f(2536.0f, 768.0f))); //ground
	groundTiles.push_back(Ground(&wallTexture, Vector2f(159.0f, 562.0f), Vector2f(-55.0f, 528.0f))); //wall at start of level
	groundTiles.push_back(Ground(&wallTexture, Vector2f(159.0f, 562.0f), Vector2f(1024.0f, 828.0f))); //wall2
	groundTiles.push_back(Ground(&wallTexture, Vector2f(159.0f, 562.0f), Vector2f(1424.0f, 728.0f))); //wall3
	groundTiles.push_back(Ground(&wallTexture, Vector2f(159.0f, 562.0f), Vector2f(1724.0f, 928.0f))); //wall4
	groundTiles.push_back(Ground(&wallTexture, Vector2f(159.0f, 562.0f), Vector2f(2100.0f, 528.0f))); //wall at start of level
	groundTiles.push_back(Ground(&sonicLivesUI, Vector2f(96.0f, 32.0f), Vector2f(-75.0f, 775)));
	groundTiles.push_back(Ground(&groundTexture, Vector2f(1024.0f, 84.0f), Vector2f(-100, -402))); //makes player stuck where he dying location is at..
	groundTiles.push_back(Ground(&gameOverSpr, Vector2f(1024.0f, 728.0f), Vector2f(-100, -402))); //gamer over ui
	groundTiles.push_back(Ground(&gameWonSpr, Vector2f(1024.0f, 728.0f), Vector2f(-1000, -3820))); //gamer won ui

	//Set enemies up TESTING!!!!!!!!!!!!!!!!
	Texture enemyTexture;
	enemyTexture.loadFromFile("enemySpr.png");
	vector<Enemy*> enemyVector;
	Enemy enemy1(Enemy(&enemyTexture, Vector2f(123.0f, 90.0f),Vector2u(3, 1), 0.3f, 40.0f));
	Enemy enemy2(Enemy(&enemyTexture, Vector2f(123.0f, 90.0f),Vector2u(3, 1), 0.3f, 40.0f));
	//^^Enemy(Texture* texture, Vector2f size, Vector2u imageCount, float switchTime, float speed)
	enemy1.setPos({ 800, 685 });
	enemy2.setPos({ 300, 685 });
	
	enemyVector.push_back(&enemy1);
	enemyVector.push_back(&enemy2);

	// END TEST!!!!!!!!!!!!




	//set rings up in vector to prevent tedious code
	Texture ringTexture;
	ringTexture.loadFromFile("sprCoin.png");



	vector<Coin*> ringsVector;
	Coin coin1(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin2(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin3(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin4(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin5(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin6(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin7(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	Coin coin8(Coin(&ringTexture, Vector2f(50.0f, 50.0f)));
	coin1.setPos({ 600, 600 });
	coin2.setPos({ 500, 600 });
	coin3.setPos({ 700, 600 });
	coin4.setPos({ 800, 600 });
	coin5.setPos({ 1200, 600 });
	coin6.setPos({ 1300, 600 });
	coin7.setPos({ 1850, 600 });
	coin8.setPos({ 1950, 600 });
	ringsVector.push_back(&coin1);
	ringsVector.push_back(&coin2);
	ringsVector.push_back(&coin3);
	ringsVector.push_back(&coin4);
	ringsVector.push_back(&coin5);
	ringsVector.push_back(&coin6);
	ringsVector.push_back(&coin7);
	ringsVector.push_back(&coin8);
	//int for ring number this converts it into a string
	int RingCount = 0;

	std::ostringstream ssRing;
	ssRing << "RINGS: " << RingCount;
	Text ringsAmount;
	ringsAmount.setFont(hud);
	ringsAmount.setFillColor(Color::Yellow);
	ringsAmount.setString(ssRing.str());
	ringsAmount.setPosition(-125.0f, 600.0f);

	//for time incrementation below, do not mess with please
	int increSecs = 0; //incrementation seconds count of a second!
	int secs = 0;
	int mins = 0;
	//time implementation above, do not mess with plz

	//score after PWNING enemies
	int score = 0;
	Text scoreBoard;
	std::ostringstream ssScore;
	ssRing << "SCORE: " << score;
	scoreBoard.setFont(hud);
	scoreBoard.setFillColor(Color::Yellow);
	scoreBoard.setPosition(-125.0f, 700.0f);

	//amount of lives (just the number, not the pretty looking icon and stuff)
	int lives = 3;
	Text liveText;
	std::ostringstream ssLives;
	ssLives << lives;
	liveText.setFont(hud);
	liveText.setFillColor(Color::White);
	liveText.setString(ssLives.str());
	liveText.setPosition(-60.0f, 765.0f);


	//do not touch, connor :o
	float deltaTime = 0.0f;
	//do not touch, connor :o

	Vector2u EnemytextureSize = enemyTexture.getSize();
	EnemytextureSize.x /= 3;
	EnemytextureSize.y /= 4;
	


	Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 4;



	while (window.isOpen())
	{
		Event event;

		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f; //if you run at 10 fps it'll go at 20fps
		//this is to stop glitching of a movement bug when you fling the window around

	


		while (window.pollEvent(event))
		{
			//if window closed below
			if (event.type == Event::Closed)
				window.close();
			//if it's resized below
			if (event.type == Event::Resized)
				ResizeCamera(window, view);
		}






		player.Update(deltaTime);




		enemy1.Update(deltaTime);
		enemy2.Update(deltaTime);
		Vector2f direction; //direction into player on collision func

	


		for (Ground& ground : groundTiles)
			if (ground.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				enemy1.OnCollision(direction);
				enemy2.OnCollision(direction);
			}
		//make sure floor is after player update or it will give game JITTERS (FRIZZY)
		
		//gonna detect collisions for each coin (must do with each addition)
		for (Coin* rings : ringsVector)
		{
			if (coin1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin1.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin2.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin3.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin3.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin4.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin4.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin5.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin5.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin6.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin6.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin7.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin7.setPos({ 1000, 4002 }); //throws coin away
			}
			if (coin8.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
				RingCount = RingCount + 1;
				coin8.setPos({ 1000, 4002 }); //throws coin away
			}
			//updates coin count baby
			ssRing.str("");
			ssRing << "RINGS: " << RingCount;
			ringsAmount.setString(ssRing.str());
		}




		for (Enemy* enemies : enemyVector)
		{
			//very similar to the coin section, exception being these ARE enemies, so you should be in jumping motion to kill this SPECIFIC one (based off the original game, that is!)
			if (enemy1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f) )
			{
				if (player.canJump == false) {
					player.OnCollision(direction);
					score = score + 100;
					enemy1.setPos({ 1000, 4002 }); //throws enemy away
				}
				else {
					player.OnCollision(direction);
					score = 0;
					player.setPos({ 0, 685 });
					lives = lives - 1;
				}
			}


			if (enemy2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				if (player.canJump == false) {
					player.OnCollision(direction);
					score = score + 100;
					enemy2.setPos({ 1000, 4002 }); //throws enemy away
				}
				else {
					player.OnCollision(direction);
					score = 0;
					player.setPos({ 0, 685 });
					lives = lives - 1;
				}
			}

			//updates coin count baby
			ssScore.str("");
			ssScore << "SCORE: " << score;
			scoreBoard.setString(ssScore.str());
			//updates lives count baby
			ssLives.str("");
			ssLives << lives;
			liveText.setString(ssLives.str());
		}




		//time increment IMPLEMENTATION BELOW, NO TOUCH
		if (increSecs <= 60)
		{
			increSecs++;
			
		}
		if (increSecs == 60) {
			secs = secs + 1;
			increSecs = 0;
		}
		if (secs == 60) {
			mins = mins + 1;
			secs = 0;
		}
		string m = to_string(mins);
		string s = to_string(secs);
		string timer = m + ":" + s;
		//NO TOUCH ABOVE

		//make gameover screen

		
		if (RingCount == 8)
		{
			player.setPos({ -1000, -3820 });

		}
	

		std::ostringstream ssTime;
		ssTime << "TIME: " << timer;
		Text time;
		time.setFont(hud);
		time.setFillColor(Color::Yellow);
		time.setString(ssTime.str());
		time.setPosition(-125.0f, 650.0f);
		//GAMEOVER BELOW, FINALLY
		if (lives <= 0)
		{
			player.gameOver = 1;
			player.setPos({ -100, -382 }); //throws player away
		}
		//GAMEOVER ABOVE

		// ^^this flips whether he is facing right/left 
		window.clear();
		


	//set view with window
		window.setView(view);


		//must be after player updates (player.Update(deltaTime);
		view.setCenter(player.GetterPos());

		

		window.draw(background);
		for (Enemy* enemies : enemyVector)
			enemy1.Draw(window);
			enemy2.Draw(window);
		for (Coin* rings : ringsVector)
			coin1.Draw(window);
			coin2.Draw(window);
			coin3.Draw(window);
			coin4.Draw(window);
			coin5.Draw(window);
			coin6.Draw(window);
			coin7.Draw(window);
			coin8.Draw(window);
		for (Ground& ground : groundTiles)
			ground.Draw(window);
		player.Draw(window);
		window.draw(scoreBoard);
		window.draw(time);
		window.draw(ringsAmount);
		window.draw(liveText);
		window.display();
	}

	return 0;
}