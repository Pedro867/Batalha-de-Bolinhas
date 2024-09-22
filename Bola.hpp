#ifndef BOLA_HPP_
#define BOLA_HPP_
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

class Bola {
private:
	sf::CircleShape shape;
	sf::Color cor;
	sf::RenderWindow &window;
	float x, y, vx, vy;
	int raio;
public:

	//Bola();
	Bola(float x, float y, float vx, float vy, sf::Color cor, int raio,
			sf::RenderWindow &janela);
	void mover();
	void draw();
	void testaColisao(Bola &outra);
	sf::FloatRect bounds();
	void inverteVelX();
	void inverteVelY();
	float getDireita();
	float getBaixo();
	float getEsquerda();
	float getTopo();
};

/*Bola::Bola() {
 x = y = vx = vy = 0;
 raio = 30;
 cor = sf::Color::White;
 this->shape.setRadius(raio);
 this->shape.setPosition(x, y);
 this->shape.setFillColor(cor);
 //Define a borda da bolinha para torn�-la vis�vel se ela for da mesma cor do fundo.
 this->shape.setOutlineColor(sf::Color::White);
 this->shape.setOutlineThickness(0.6f);
 }*/

Bola::Bola(float x, float y, float vx, float vy, sf::Color cor, int raio,
		sf::RenderWindow &janela) :
		window(janela) {
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->raio = raio;
	this->cor = cor;
	this->shape.setRadius(raio);
	this->shape.setPosition(x, y);
	this->shape.setFillColor(cor);
}

void Bola::mover() {
	//Testa os limites e inverte as velocidades
	if (x >= window.getSize().x - 2 * raio) {
		vx = -vx;
	} else if (x <= 0) {
		vx = -vx;
	}

	if (y >= window.getSize().y - 2 * raio) {
		vy = -vy;
	} else if (y <= 0) {
		vy = -vy;
	}

	//Incrementa as posi��es
	x = x + vx;
	y = y + vy;

	//Testa se depois do incremento ela sai da tela e ent�o volta a bolinha
	x = (x > window.getSize().x - 2 * raio) ? window.getSize().x - 2 * raio : x;
	y = (y > window.getSize().y - 2 * raio) ? window.getSize().y - 2 * raio : y;

	x = (x < 0) ? 0 : x;
	y = (y < 0) ? 0 : y;

	//Muda a posi��o do shape.
	this->shape.setPosition(x, y);
}

void Bola::draw() {
	//Desenha ao shape na janela.
	window.draw(shape);
}

void Bola::testaColisao(Bola &outra) {
	if (shape.getGlobalBounds().intersects(outra.shape.getGlobalBounds())) {
		this->vx *= -1;
		this->vy *= -1;
		outra.vx *= -1;
		outra.vy *= -1;
	}
}

sf::FloatRect Bola::bounds() {
	return shape.getGlobalBounds();
}

void Bola::inverteVelX() {
	vx = -vx;
}

void Bola::inverteVelY() {
	vy = -vy;
}

float Bola::getDireita() {
	float direita = shape.getPosition().x + raio;
	return direita;
}

float Bola::getBaixo() {
	float baixo = shape.getPosition().y + raio;
	return baixo;
}

float Bola::getEsquerda() {
	float direita = shape.getPosition().x - raio;
	return direita;
}

float Bola::getTopo() {
	float baixo = shape.getPosition().y - raio;
	return baixo;
}

#endif /* BOLA_HPP_ */
