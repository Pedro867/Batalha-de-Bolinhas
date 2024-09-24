#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Bola.hpp"
#include "Quadrado.hpp"

using namespace std;

void testaColisao1(vector<Quadrado> &quad, Bola &bola) {
	sf::FloatRect hitBola = bola.bounds();

	for (int i = 0; i <= 25; ++i) {
		if (quad[i].getAtivado()) {
			if (hitBola.intersects(quad[i].bounds())) {
				//usando essa logica de bater no top e left eh possivel
				//determinar quando a bola bate em uma parte especifica do quad
				if (bola.getBaixo() >= quad[i].bounds().top) {
					bola.inverteVelX();
				} else if (bola.getDireita() >= quad[i].bounds().left) {
					bola.inverteVelY();
				}
				quad[i].bateu();
			}
		}
	}
}

void testaColisao2(vector<Quadrado> &quad, Bola &bola) {
	sf::FloatRect hitBola = bola.bounds();

	for (int i = 0; i <= 25; ++i) {
		if (!quad[i].getAtivado()) {
			if (hitBola.intersects(quad[i].bounds())) {
				//usando essa logica de bater no top e left eh possivel
				//determinar quando a bola bate em uma parte especifica do quad
				float baixo = quad[i].bounds().top + quad[i].bounds().height;
				float direita = quad[i].bounds().left + quad[i].bounds().width;
				if (bola.getTopo() <= baixo) {
					bola.inverteVelX();
				} else if (bola.getEsquerda() <= direita) {
					bola.inverteVelY();
				}
				quad[i].bateuContrario();
			}
		}
	}
}

int main(int argc, char **argv) {
	sf::VideoMode video(800, 600);
	sf::RenderWindow window(video, "Bolas que Batem");
	window.setFramerateLimit(60);
	sf::Event event;

	Bola bola1(10, 10, 1.5, 1, sf::Color::Red, 20, window);
	Bola bola2(window.getSize().x - 10, window.getSize().y - 10, -1, -1,
			sf::Color::Green, 20, window);

	vector<Quadrado> quad;
	for (int i = 0; i <= 25; ++i) {
		quad.push_back(Quadrado(window));
		quad[i].setQuadrante(i);

		if (i == 5) {
			quad[i].mudaCor(sf::Color::Red);
			quad[i].setAtivado(true);
		}
		if (i == 9 || i == 10) {
			quad[i].mudaCor(sf::Color::Red);
			quad[i].setAtivado(true);
		}
		if (i == 13 || i == 14 || i == 15) {
			quad[i].mudaCor(sf::Color::Red);
			quad[i].setAtivado(true);
		}
		if (i == 17 || i == 18 || i == 19 || i == 20) {
			quad[i].mudaCor(sf::Color::Red);
			quad[i].setAtivado(true);
		}
		if (i == 21 || i == 22 || i == 23 || i == 24 || i == 25) {
			quad[i].mudaCor(sf::Color::Red);
			quad[i].setAtivado(true);
		}
	}

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		//Mover elementos
		testaColisao1(quad, bola1);
		testaColisao2(quad, bola2);
		bola1.mover();
		bola2.mover();

		//Desenha na tela
		for (int i = 0; i <= 25; ++i) {
			quad[i].draw();
		}
		bola1.draw();
		bola2.draw();

		window.display();
	}
}
