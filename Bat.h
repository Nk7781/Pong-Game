#include<SFML/Graphics.hpp>
using namespace sf;

class Bat {
	private:
		Vector2f m_Position;
		RectangleShape m_Shape;
		
		//for bat movement 
		float m_Speed = 600.0f;
		bool m_MovingLeft = false;
		bool m_MovingRight = false;
		
	public:
		Bat(float startX, float startY);
		FloatRect getPosition();
		RectangleShape getShape();
		
		//for bat movement
		void moveLeft();
		void moveRight();
		void stopLeft();
		void stopRight();
		
		//for updating bat position
		void update(Time dt);
		
		
};
