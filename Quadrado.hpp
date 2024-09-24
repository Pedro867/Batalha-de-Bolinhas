#ifndef QUADRADO_HPP_
#define QUADRADO_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Quadrado {
private:
	sf::RectangleShape quadrado;
	sf::Vector2f tamanho;
	sf::RenderWindow &window;
	float altura, largura;
	bool ativado;
public:
	Quadrado(sf::RenderWindow &janela);
	void setQuadrante(int quadrante);
	void mudaCor(sf::Color cor);
	void bateu();
	void bateuContrario();
	sf::FloatRect bounds();
	bool getAtivado();
	void setAtivado(bool valor);
	void draw();
};

Quadrado::Quadrado(sf::RenderWindow &janela) :
		window(janela) {
	altura = window.getSize().y / 5;
	largura = window.getSize().x / 5;
	tamanho.x = largura;
	tamanho.y = altura;
	quadrado.setSize(tamanho);
	quadrado.setOrigin(tamanho.x / 2, tamanho.y / 2);
	quadrado.setFillColor(sf::Color::Green);
	ativado = false;
}

void Quadrado::setQuadrante(int quadrante) {
	float posX, posY;
	switch (quadrante) {
	case 1:
		posX = window.getSize().x / 10;
		posY = window.getSize().y / 10;
		break;
	case 2:
		posX = 3 * (window.getSize().x / 10);
		posY = window.getSize().y / 10;
		break;
	case 3:
		posX = 5 * (window.getSize().x / 10);
		posY = window.getSize().y / 10;
		break;
	case 4:
		posX = 7 * (window.getSize().x / 10);
		posY = window.getSize().y / 10;
		break;
	case 5:
		posX = 9 * (window.getSize().x / 10);
		posY = window.getSize().y / 10;
		break;
	case 6:
		posX = window.getSize().x / 10;
		posY = 3 * (window.getSize().y / 10);
		break;
	case 7:
		posX = 3 * (window.getSize().x / 10);
		posY = 3 * (window.getSize().y / 10);
		break;
	case 8:
		posX = 5 * (window.getSize().x / 10);
		posY = 3 * (window.getSize().y / 10);
		break;
	case 9:
		posX = 7 * (window.getSize().x / 10);
		posY = 3 * (window.getSize().y / 10);
		break;
	case 10:
		posX = 9 * (window.getSize().x / 10);
		posY = 3 * (window.getSize().y / 10);
		break;
	case 11:
		posX = window.getSize().x / 10;
		posY = 5 * (window.getSize().y / 10);
		break;
	case 12:
		posX = 3 * (window.getSize().x / 10);
		posY = 5 * (window.getSize().y / 10);
		break;
	case 13:
		posX = 5 * (window.getSize().x / 10);
		posY = 5 * (window.getSize().y / 10);
		break;
	case 14:
		posX = 7 * (window.getSize().x / 10);
		posY = 5 * (window.getSize().y / 10);
		break;
	case 15:
		posX = 9 * (window.getSize().x / 10);
		posY = 5 * (window.getSize().y / 10);
		break;
	case 16:
		posX = window.getSize().x / 10;
		posY = 7 * (window.getSize().y / 10);
		break;
	case 17:
		posX = 3 * (window.getSize().x / 10);
		posY = 7 * (window.getSize().y / 10);
		break;
	case 18:
		posX = 5 * (window.getSize().x / 10);
		posY = 7 * (window.getSize().y / 10);
		break;
	case 19:
		posX = 7 * (window.getSize().x / 10);
		posY = 7 * (window.getSize().y / 10);
		break;
	case 20:
		posX = 9 * (window.getSize().x / 10);
		posY = 7 * (window.getSize().y / 10);
		break;
	case 21:
		posX = window.getSize().x / 10;
		posY = 9 * (window.getSize().y / 10);
		break;
	case 22:
		posX = 3 * (window.getSize().x / 10);
		posY = 9 * (window.getSize().y / 10);
		break;
	case 23:
		posX = 5 * (window.getSize().x / 10);
		posY = 9 * (window.getSize().y / 10);
		break;
	case 24:
		posX = 7 * (window.getSize().x / 10);
		posY = 9 * (window.getSize().y / 10);
		break;
	case 25:
		posX = 9 * (window.getSize().x / 10);
		posY = 9 * (window.getSize().y / 10);
		break;
	}

	quadrado.setPosition(posX, posY);

}

void Quadrado::mudaCor(sf::Color cor) {
	quadrado.setFillColor(cor);
}

void Quadrado::bateu() {
	ativado = false;
	quadrado.setFillColor(sf::Color::Green);
}

void Quadrado::bateuContrario() {
	ativado = true;
	quadrado.setFillColor(sf::Color::Red);
}

sf::FloatRect Quadrado::bounds() {
	return quadrado.getGlobalBounds();
}

bool Quadrado::getAtivado() {
	return ativado;
}

void Quadrado::setAtivado(bool valor) {
	ativado = valor;
}

void Quadrado::draw() {
	window.draw(quadrado);
}

#endif /* QUADRADO_HPP_ */
