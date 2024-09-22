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
	altura = window.getSize().y / 3;
	largura = window.getSize().x / 3;
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
		posX = window.getSize().x / 6;
		posY = window.getSize().y / 6;
		break;
	case 2:
		posX = 3 * (window.getSize().x / 6);
		posY = window.getSize().y / 6;
		break;
	case 3:
		posX = 5 * (window.getSize().x / 6);
		posY = window.getSize().y / 6;
		break;
	case 4:
		posX = window.getSize().x / 6;
		posY = 3 * (window.getSize().y / 6);
		break;
	case 5:
		posX = 3 * (window.getSize().x / 6);
		posY = 3 * (window.getSize().y / 6);
		break;
	case 6:
		posX = 5 * (window.getSize().x / 6);
		posY = 3 * (window.getSize().y / 6);
		break;
	case 7:
		posX = window.getSize().x / 6;
		posY = 5 * (window.getSize().y / 6);
		break;
	case 8:
		posX = 3 * (window.getSize().x / 6);
		posY = 5 * (window.getSize().y / 6);
		break;
	case 9:
		posX = 5 * (window.getSize().x / 6);
		posY = 5 * (window.getSize().y / 6);
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
	quadrado.setFillColor(sf::Color::Magenta);
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
