#include "Ball.h"
Ball :: Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;
	m_Shape.setRadius(10);
	m_Shape.setPosition(m_Position);
	m_DirectionX = (rand() % 2?0.2f: -0.2f);
	m_DirectionY = 0.2f;
}

FloatRect Ball::getPosition() {
	return m_Shape.getGlobalBounds();
} 

void Ball::setPosition(float x, float y){
	m_Position.x = x;
	m_Position.y = y;
	m_Shape.setPosition(m_Position);
}

CircleShape Ball::getShape() {
	return m_Shape;
}

void Ball::reboundSides() {
	m_DirectionX = -m_DirectionX;
	if (abs(m_DirectionX) < 0.2f)
		m_DirectionX = (m_DirectionX < 0? -0.2f:0.2f);
}

void Ball::reboundBatOrTop() {
	m_DirectionY = -m_DirectionY;
	if (abs(m_DirectionY) < 0.2f)
		m_DirectionY = (m_DirectionY < 0 ? -0.3f : 0.3f);
}

// void Ball::reboundBottom() {
// 	m_Position.x = 11;
// 	m_Position.y = 500;
// }

void Ball :: start(){
	m_Speed = 1000.0f;
}

void Ball::stop(){
    m_Speed = 0.0f;
}

void Ball::reset(float x, float y){
    m_Position.x = x;
	m_Position.y = y;
	m_Shape.setPosition(m_Position);
	m_DirectionX = (rand() % 2 ? 0.2f : -0.2f);
	m_DirectionY = 0.5f;
	start();
}

void Ball::update(Time dt){
	
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	
	m_Shape.setPosition(m_Position);
}
