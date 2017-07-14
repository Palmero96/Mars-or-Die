#include "Phase2.h"
#define asteroid2 125
#define fuel 250
#define alien 325
#define asteroid1 50
#define asteroid3 175
#define life 360
#define bonus 400

Phase2::Phase2()
{
	spacecraft = new Ship2("textures/phase2/spacecraft.png");

	for (int i = 0; i < asteroid1; i++) List[i] = new Elements(ASTEROID1, "textures/phase2/Asteroid1.png");
	for (int i = asteroid1; i < asteroid2; i++) List[i] = new Elements(ASTEROID2, "textures/phase2/Asteroid2.png");
	for (int i = asteroid2; i < asteroid3; i++) List[i] = new Elements(ASTEROID3, "textures/phase2/Asteroid3.png");
	for (int i = asteroid3; i < fuel; i++) List[i] = new Elements(FUEL, "textures/phase2/Fuel.png");
	for (int i = fuel; i < alien; i++) List[i] = new Alien("textures/phase2/Alien.png");
	for (int i = alien; i < life; i++)List[i] = new Elements(LIFE, "textures/phase2/life.png");
	for (int i = life; i <bonus; i++) List[i] = new Elements(BONUS, "textures/phase2/Bonus.png");

	explosion = new ETSIDI::SpriteSequence("textures/phase2/Explosion.png", 5, 3, 25, true, 0, 0, 20, 20);
	elim = 0;
	boom = false;
	explosion_time = 0;
	tutorial = true;
	game_status = succes = game_over = false;
	invincible = false;
}

Phase2::~Phase2() 
{
	for(int i=0;i<MAX;i++)
	delete List[i];
}

void Phase2::Initialize()
{
	x_eye = 0;
	y_eye = 0;
	z_eye = 100;
	spacecraft->Initialize();

}

void Phase2::Draw() {

	Vector2 aux;
	aux = spacecraft->GetPos();
	gluLookAt(aux.x, aux.y, z_eye,  // posicion del ojo
		aux.x, aux.y, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("textures/phase1/space1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);

	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);  glVertex3f(-80, 500, -50);
	glTexCoord2d(1, 1);  glVertex3f(-80, -500, -50);
	glTexCoord2d(1, 0);  glVertex3f(2000, -500, -50);
	glTexCoord2d(0, 0);  glVertex3f(2000, 500, -50);

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	if (tutorial)
	{
		spacecraft->Draw();
		punt.Draw(1);
	}

	else
	{
		punt.Draw(2);
		spacecraft->Draw();
		for (int i = 0; i < MAX - elim; i++)List[i]->draw();
		if (boom)	explosion->draw();
		if (explosion_time > 15) 
		{
			boom = false;
			explosion_time = 0;
		}
	}
	if (succes) {
		punt.Draw(4);
		spacecraft->reset();
	}
	if (punt.Die())
	{
		game_status = false;
		game_over = true;
		punt.Draw(3);
		ETSIDI::Vector2D aux1, aux2;
		aux1 = spacecraft->getPos();
		aux2 = spacecraft->getCenter();
		explosion->setPos(aux1.x, aux1.y);
		explosion->setCenter(aux2.x, aux2.y);
		boom = true;
		spacecraft->stop();
	}
}

void Phase2::Timer() 
{
	if (game_status || succes||game_over)
	{
		float t = 0.25;
		ETSIDI::Vector2D aux1, aux2;
		spacecraft->Move(t);
		punt.move(succes);

		if (boom) 
		{
			explosion->draw();
			explosion->loop();
			explosion_time++;
			ETSIDI::play("music/alienExplosion.wav");
		}

		if (invincible) invincible_time++;
		
		if (invincible_time > 500)
		{
			invincible = false;
			invincible_time = 0;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("music/phase2.wav",true);
		}

		for (int i = 0; i < MAX - elim; i++) 
		{
			List[i]->move();

			if (Interaction::Colision(*spacecraft, List[i]))
			{
				switch (List[i]->getType())
				{
				case FUEL:
					punt.addFuel();
					break;

				case BONUS:
					invincible = true;
					ETSIDI::playMusica("music/bonus_phase2.wav", false);
					invincible_time = 0;
					break;

				case LIFE:
					punt.addLife();
					break;
				default:
					if (!invincible)	punt.substractlife();
					aux1 = List[i]->getPos();
					aux2 = List[i]->getCenter();
					explosion->setPos(aux1.x, aux1.y);
					explosion->setCenter(aux2.x, aux2.y);
					boom = true;
				}
				elim++;
				punt.addPoints();
				Elements *aux = List[i];
				for (int j = i; j < (MAX - elim - 1); j++)	List[j] = List[j + 1];
				List[MAX - elim] = aux;
			}
		}

		if (spacecraft->Win()) 
		{
			succes = true;
			game_status = false;
		}
	}
}

void Phase2::Key(unsigned char key, int x_t, int y_t) {
	
	if (key == 's') 
	{
		game_status = true;
		tutorial = false;
		spacecraft->reset();
	}
	if (key == 'f') {
		punt.addFuel();
		ETSIDI::play("music/cheat.wav");
	}
	if (key == 'l') {
		punt.addLife();
		ETSIDI::play("music/cheat.wav");
	}
}
void Phase2::SpecialKey(int key)
{
	spacecraft->SpecialKey(key);
}