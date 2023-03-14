#include"SFML\Graphics.hpp"
#include<iostream>

#include"Limite.h"
#include"Jugador.h"
#include"Plataforma.h"


using namespace sf;
using namespace std;


int main(){

	  //		Variables 	 
    float moveSpeed = 30;
    float gravitySpeed = 30;
    
	const int ALTO= 800;
	const int ANCHO= 600;
	const int pared_izq=1;
    const int pared_der=1023;
    const int piso = 490;
    const float pixel = 10;

    bool saltar = false; 
    bool colision = false;
	
	Event event;
	
	//			Window 
 	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(VideoMode(ALTO,ANCHO), "Plataformas");
	window.setFramerateLimit(35);
    window.setKeyRepeatEnabled(false); 
    
    Texture background;
    background.loadFromFile("img/background.png");
    
    Sprite fondo;
    fondo.setTexture(background);
     
   
    
    // 		Objetos de limites		 
	Limite limiteLeft({2,798}), limiteRight({2,798}), limiteUp({798,2});
	limiteLeft.setPos(Vector2f(0,0));
	limiteRight.setPos(Vector2f(798,2));
	limiteUp.setPos(Vector2f(0,1));
	
	

	//		Objeto de jugador			 
    Jugador player({ 40, 40 },sf::Color::Blue);
    player.setPos({ 200, 10 });
    
    
    
    
    //		Objeto plataforma
    Plataforma plataforma(Vector2f(200,2),Color::Transparent), plataforma2(Vector2f(200,2),Color::Transparent), plataforma3(Vector2f(200,2),Color::Transparent);
    plataforma.setPos(Vector2f(95,400));
    plataforma2.setPos(Vector2f(495,400));
    plataforma3.setPos(Vector2f(295,200));


    
    while (window.isOpen())
{
	//  		EVENTO				 
    while (window.pollEvent(event)){

    switch (event.type)	{
	
	case Event::Closed:
	window.close();
	break;
		
	case sf::Event::KeyReleased:
    saltar = true;
    break;
				
	case Event::KeyPressed:
    if (event.key.code==Keyboard::Escape){
    window.close();
    
    return EXIT_SUCCESS;} } 
}
	  
	// Movimiento de Jugador			     													
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
	player.move({ 0, -moveSpeed });
    saltar = true;																					    }	 
	else 
	saltar=false; 
	
	     
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    player.move({ moveSpeed, 0 });  
	colision = true;
													   	 }
	else 
	colision=false;
 
         
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    player.move({ -moveSpeed, 0 });					    }  
 
	 
		// Colision con limites
		if ( player.getX() <= ( limiteLeft.getX()  ) + pixel*4 ){
		cout<<"Limite izquierdo"<<endl; 
		player.move({moveSpeed,0});								}
	
	
		if ( player.getX() >= ( limiteRight.getX() ) - pixel*7 ){
		player.move({-moveSpeed,0});
		cout<<"Limite derecho"<<endl;							} 
	 
	
 		if ( player.getY() < ( limiteUp.getX() ) + pixel*2 )	{
		player.move({0,moveSpeed});
		cout<<"Limite superior"<<endl; 							}						
	 
 	
		// Logica de gravedad					 
		if (player.getY() < piso && saltar == false) {
    	player.move({ 0, gravitySpeed }); 			 }
      
	
   	 
    
    
   
   // Posicion mouse X,Y		      
   Vector2i position = Mouse::getPosition(window);
   //cout<<"Mouse  X: "<<position.x<<"   Mouse  Y: "<<position.y<<endl; ACA LA POSICION DEL MOUSE (FUNCIONA)
   
 	 
 	 
 	 	 
	 
	 
   //		Dibujar  
   player.update();
   
   
	   	//PLATAFORMA IZQUIERDA
		if(player.colision2(plataforma))		  {
 
		if(player.getY()<=plataforma.getY()){

		player.move({0, -moveSpeed});
		cout<<"Plataforma 1"<<endl;    } 		  }
			 
		 
	 
		//PLATAFORMA DERECHA
		if(player.colision2(plataforma2))			{
		 
		if(player.getY()<=plataforma2.getY()){
			
			player.move({0, -moveSpeed});
			cout<<"Plataforma 2"<<endl;		 }
		 
													}
		//PLATAFORMA SUPERIOR
		if(player.colision2(plataforma3))		    {
		 
		if(player.getY()<=plataforma3.getY()){
		player.move({0, -moveSpeed});
		cout<<"Plataforma 3"<<endl;
										     }
													}
	

   //		WINDOW CLEAR
   window.clear();
 

	

        
   //		Fondo pantalla 
   window.draw(fondo);
   
   //		Limites mapa    
   limiteLeft.mostrarLimite(window);
   limiteRight.mostrarLimite(window);
   limiteUp.mostrarLimite(window);
   
   //		Jugadores       
   player.mostrar(window);
  
	
   //		Plataforma
   plataforma.mostrar(window);
   plataforma2.mostrar(window);
   plataforma3.mostrar(window);
   
   window.display();
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}//MAIN
