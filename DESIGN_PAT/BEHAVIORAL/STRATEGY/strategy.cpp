//Sep 26, 2018
//Wiki:
//Defines a family of algorithms, encapsulates each one, and make them interchangeable. Strategy lets the algorithm 
//vary independently from clients who use it.
//Each stragegy is a class.
//
//Called ConcreteStrategyA execute method
//Called ConcreteStrategyB execute method
//Called ConcreteStrategyC execute method
//Called ConcreteStrategyB execute method
//Called ConcreteStrategyC execute method
//
// ConcreteStrategyA is  StrategyInterface
// ConcreteStrategyB is  StrategyInterface
// ConcreteStrategyC is  StrategyInterface
// Context           has StrategyInterface
//
//                    [StrategyInterface]<>------------[Context      ]
//                             ^                       [setStrategy()]
//                             |                       
//                             |                    
//          |------------------|----------------------|
//  [ConcreteStrategyA]  [ConcreteStrategyB]  [ConcreteStrategyC]
//
// Note that Context has StrategyInterface relationship is really same
// as having all sub-classes due polymorphism.
//
// Basically, this strategy allows each client to change the strategy encapsulated from each other.
//
#include <iostream>
using namespace std;

class StrategyInterface
{
    public:
        virtual void execute() const = 0;
};

class ConcreteStrategyA: public StrategyInterface
{
    public:
        //void execute() const override
        //void execute()
        void execute() const 
        {
            cout << "Called ConcreteStrategyA execute method" << endl;
        }
};

class ConcreteStrategyB: public StrategyInterface
{
    public:
        void execute() const override
        {
            cout << "Called ConcreteStrategyB execute method" << endl;
        }
};

class ConcreteStrategyC: public StrategyInterface
{
    public:
        void execute() const override
        {
            cout << "Called ConcreteStrategyC execute method" << endl;
        }
};

class Context
{
    private:
        StrategyInterface * strategy_;

    public:
        //Sets one of the three strategies.
        //This is polymorphic assignment.
        explicit Context(StrategyInterface *strategy):strategy_(strategy)
        {
        }

        void set_strategy(StrategyInterface *strategy)
        {
            strategy_ = strategy;
        }

        void execute() const
        {
            strategy_->execute();
        }
};


int main(int argc, char *argv[])
{
    ConcreteStrategyA concreteStrategyA;
    ConcreteStrategyB concreteStrategyB;
    ConcreteStrategyC concreteStrategyC;

    Context contextA(&concreteStrategyA);
    Context contextB(&concreteStrategyB);
    Context contextC(&concreteStrategyC);

    contextA.execute(); // output: "Called ConcreteStrategyA execute method"
    contextB.execute(); // output: "Called ConcreteStrategyB execute method"
    contextC.execute(); // output: "Called ConcreteStrategyC execute method"
    
    contextA.set_strategy(&concreteStrategyB);   //Now contextA changes strategy.
    contextA.execute(); // output: "Called ConcreteStrategyB execute method"
    
    contextA.set_strategy(&concreteStrategyC);   //Now contextB changes stragegy.
    contextA.execute(); // output: "Called ConcreteStrategyC execute method"

    return 0;
}