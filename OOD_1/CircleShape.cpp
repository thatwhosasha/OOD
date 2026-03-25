

class Circle : public ShapeDecorator 
{
private:
    sf::CircleShape circle; // Декорируем объект sf::CircleShape
    float radius;

public:
    Circle(float x, float y, float radius) : radius(radius) {
        circle.setRadius(radius);
        circle.setPosition(x - radius, y - radius);
        circle.setFillColor(sf::Color::Blue);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(circle);
    }

    float calculateArea() const override {
        return 3.14159f * radius * radius;
    }

    float calculatePerimeter() const override {
        return 2 * 3.14159f * radius;
    }
};