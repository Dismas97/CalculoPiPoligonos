#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(800, 600), "PIoligonos");
    window.setVerticalSyncEnabled(true);
    Font arial;
    arial.loadFromFile("arial.ttf");

    Text text1;
    text1.setFont(arial);
    text1.setCharacterSize(20);
    text1.setFillColor(Color::White);
    text1.setPosition(0,0);

    int anchoV = window.getSize().x, largoV = window.getSize().y;
    float radioPol = anchoV*anchoV + largoV*largoV;
    int lados =3;

    radioPol = sqrt(radioPol)/4;
    CircleShape poligono((int)radioPol, lados);
    poligono.setOrigin(poligono.getRadius(), poligono.getRadius());
    poligono.setPosition(anchoV/2 ,largoV/2);

    string texto;

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed || event.key.code==Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(event.key.control){
                    if(event.key.code == Keyboard::Add){
                        radioPol++;
                        poligono.setRadius(radioPol);
                        poligono.setOrigin(poligono.getRadius(), poligono.getRadius());
                        poligono.setPosition(anchoV/2 ,largoV/2);
                        poligono.setOutlineColor(Color(1+rand()%255,1+rand()%255,1+rand()%255));
                        poligono.setOutlineThickness (radioPol/8);
                    }
                    if(event.key.code == Keyboard::Subtract && radioPol>0){
                        radioPol--;
                        poligono.setRadius(radioPol);
                        poligono.setOrigin(poligono.getRadius(), poligono.getRadius());
                        poligono.setPosition(anchoV/2 ,largoV/2);
                        poligono.setOutlineColor(Color(1+rand()%255,1+rand()%255,1+rand()%255));
                        poligono.setOutlineThickness (radioPol/8);
                    }
                }
                else if (event.key.code == Keyboard::Add){
                    poligono.setPointCount(poligono.getPointCount()+1);
                    lados++;
                    poligono.setFillColor(Color(1+rand()%255,1+rand()%255,1+rand()%255));
                }
                else if (event.key.code == Keyboard::Subtract && poligono.getPointCount()>3){
                    poligono.setPointCount(poligono.getPointCount()-1);
                    lados--;
                    poligono.setFillColor(Color(1+rand()%255,1+rand()%255,1+rand()%255));
                }
            }
        }
        texto = "Cant lados: "+to_string(lados)+"\nRadio Cir: "+to_string((int)radioPol);
        text1.setString(texto);
        window.clear();
        window.draw(poligono);
        window.draw(text1);
        window.display();
    }
    return 0;
}
