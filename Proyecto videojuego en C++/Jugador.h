#include"SFML\Graphics.hpp"
#include<iostream>
#include"Plataforma.h"
using namespace sf;

class Jugador : public Plataforma{
	
	private:
		
		RectangleShape player;
		float bottom,left,right,top;
		 Color color;
		
	public:
		Jugador();
		Jugador(Vector2f tam,sf::Color color);
		
		void mostrar(RenderWindow &window);
		void move(Vector2f distance);
		void setPos(Vector2f newPos);
		void setOrigin(Vector2f _origin);
		void update();
		bool colision(Jugador j1);
		FloatRect coli();
		bool colision2(Plataforma p2);
		
		int getX();
		int getSizeY(); 
		int getY();
	 //   ~Jugador();
 
     
};

Jugador::Jugador(){
	
}

Jugador::Jugador(Vector2f tam, sf::Color color){ //Sobrecarga de constructor

player.setSize(tam);

player.setFillColor(color);

}

void Jugador::mostrar(RenderWindow &window){

window.draw(player);

}

void Jugador::move(Vector2f distance){

player.move(distance);

}

void Jugador::setPos(Vector2f newPos){

player.setPosition(newPos);

}

int Jugador::getY(){

return player.getPosition().y;

}

int Jugador::getX(){
	return player.getPosition().x;
}

int Jugador::getSizeY(){
	return player.getSize().y;
}

/*Jugador::~Jugador(){
	cout<< "se ejecuta el destructor" <<endl;
	 
}*/

void Jugador::setOrigin(Vector2f _origin){
	player.setOrigin(_origin);
}

void Jugador::update(){
	bottom=player.getPosition().y + player.getSize().y;
	left=player.getPosition().x;
	right=player.getPosition().x + player.getSize().x;
	top=player.getPosition().y;
}

/*bool Jugador::colision(Jugador j1){
	if(right<j1.right || left > j1.right ||
	top > j1.bottom || bottom < j1.top){

		return false;
	}
	return true;
}*/

FloatRect Jugador::coli(){
	return player.getGlobalBounds(); 
	
}

bool Jugador::colision2(Plataforma p2){
	 return player.getGlobalBounds().intersects(p2.pcoli());
}




