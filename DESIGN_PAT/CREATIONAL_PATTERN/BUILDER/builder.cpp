#include <string>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;

//Spe 27, 2018
//According Wiki
//
//Purpose: separate the construction of complex object (in this case hawaiian and spicy pizza) from its representation (? WTF)
//Solution: Define intermediate object(is this PizzaBuilder) whose member functions define the desired object part by part.
//
//Derek Banas: Used to create objects made from a bunch of other objects.
//
//                  Abstract Class
//  [Cook]--------<>[Pizza Builder] ----------<> [Pizza]
//                          ^
//                          |
//          |---------------|------------|
//    [HawaiianPizzaBuilder]    [SpicyPizzaBuilder]
//
//  Cook has PizzaBuilder
//  PizzaBuilder has Pizza
//  HawaiianPizzaBuilder is PizzaBuilder
//  SpicyPizzaBuilder is PizzaBuilder
//
template<class T, class... ARGS>
unique_ptr<T>make_unique( ARGS&&... my_args)
{
	return unique_ptr<T>(new T(forward<ARGS>(my_args)...));
}

// "Product"
class Pizza
{
public:
	void setDough(const string& dough)
	{
		m_dough = dough;
	}
	void setSauce(const string& sauce)
	{
		m_sauce = sauce;
	}
	void setTopping(const string& topping)
	{
		m_topping = topping;
	}
	void open() const
	{
		cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce and "
			<< m_topping << " topping. Mmm." << endl;
	}
private:
	string m_dough;
	string m_sauce;
	string m_topping;
};

// "Abstract Builder"
class PizzaBuilder
{
public:
	virtual ~PizzaBuilder() {};

	Pizza* getPizza()
	{
		//Think this as return m_pizza;
		return m_pizza.release();
	}
	void createNewPizzaProduct()
	{
		//Think of it as Pizza* m_pizza = new Pizza;
		m_pizza = make_unique<Pizza>();
	}
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
protected:
	//Safer way of allocating memory.
	//Think this as Pizza* m_pizza;
	unique_ptr<Pizza> m_pizza;
};

//----------------------------------------------------------------

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~HawaiianPizzaBuilder() {};

	virtual void buildDough()
	{
		m_pizza->setDough("cross");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("mild");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("ham+pineapple");
	}
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
	virtual ~SpicyPizzaBuilder() {};

	virtual void buildDough()
	{
		m_pizza->setDough("pan baked");
	}
	virtual void buildSauce()
	{
		m_pizza->setSauce("hot");
	}
	virtual void buildTopping()
	{
		m_pizza->setTopping("pepperoni+salami");
	}
};

//----------------------------------------------------------------

class Cook
{
public:
	void openPizza()
	{
		m_pizzaBuilder->getPizza()->open();
	}
	//Polymorphic input.
	//This takes in PizzaBuilder object or any derived object.
	void makePizza(PizzaBuilder* pb)
	{
		m_pizzaBuilder = pb;
		m_pizzaBuilder->createNewPizzaProduct();
		m_pizzaBuilder->buildDough();
		m_pizzaBuilder->buildSauce();
		m_pizzaBuilder->buildTopping();
	}
private:
	PizzaBuilder* m_pizzaBuilder;
};

int main()
{
	Cook cook;
	HawaiianPizzaBuilder hawaiianPizzaBuilder;
	SpicyPizzaBuilder    spicyPizzaBuilder;

	cook.makePizza(&hawaiianPizzaBuilder);
	cook.openPizza();

	cook.makePizza(&spicyPizzaBuilder);
	cook.openPizza();
}