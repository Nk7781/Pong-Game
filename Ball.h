#include<SFML/Graphics.hpp>
using namespace sf;

class Ball {
	private:
		Vector2f m_Position;
		CircleShape m_Shape;
		
		//for ball movement 
		float m_Speed = 0.0f;
		float m_DirectionX = 0.2f;
		float m_DirectionY = 0.2f;
		
	public:
		Ball(float startX, float startY);
		FloatRect getPosition();
		void setPosition(float x, float y);
		CircleShape getShape();
		
		//ball movement
		void reboundSides();
		void reboundBatOrTop();
		
		void start();
        void stop();
        void reset(float x, float y);

		//for updating ball position
		void update(Time dt);
		
		
};
