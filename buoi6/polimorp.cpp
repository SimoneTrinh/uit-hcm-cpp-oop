#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal
{
protected:
    float weight;
    float height;
    string color;

public:
    Animal(float w, float h, string c) : weight(w), height(h), color(c) {}

    virtual void makeSound()
    {
        cout << "Some generic animal sound" << endl;
    }

    virtual float getWeight()
    {
        return weight;
    }

    virtual float getHeight()
    {
        return height;
    }

    virtual string getColor()
    {
        return color;
    }

    virtual ~Animal()
    {
        cout << "Animal destructor called" << endl;
    }
};

// Derived class
class Dog : public Animal
{
public:
    Dog(float w, float h, string c) : Animal(w, h, c) {}

    void makeSound()
    {
        cout << "Woof!" << endl;
    }

    ~Dog()
    {
        cout << "Dog destructor called" << endl;
    }
};

// Derived class
class Cat : public Animal
{
public:
    Cat(float w, float h, string c) : Animal(w, h, c) {}

    void makeSound()
    {
        cout << "Meow!" << endl;
    }

    ~Cat()
    {
        cout << "Cat destructor called" << endl;
    }
};

int main()
{
    // Create objects dynamically using new keyword
    Animal *animal1 = new Dog(25.0f, 60.0f, "Brown"); // Dog weighs 25.0 units, 60.0 units tall, Brown color
    Animal *animal2 = new Cat(10.5f, 30.0f, "Black"); // Cat weighs 10.5 units, 30.0 units tall, Black color

    // Polymorphism in action
    animal1->makeSound(); // Outputs: Woof!
    animal2->makeSound(); // Outputs: Meow!

    cout << "Dog weight: " << animal1->getWeight() << " units, height: " << animal1->getHeight() << " units, color: " << animal1->getColor() << endl; // Outputs: Dog weight: 25.0 units, height: 60.0 units, color: Brown
    cout << "Cat weight: " << animal2->getWeight() << " units, height: " << animal2->getHeight() << " units, color: " << animal2->getColor() << endl; // Outputs: Cat weight: 10.5 units, height: 30.0 units, color: Black

    // Clean up
    delete animal1; // Calls Dog destructor, then Animal destructor
    delete animal2; // Calls Cat destructor, then Animal destructor

    return 0;
}
