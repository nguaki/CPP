////////////////////////////////////////////////////////////////////////////////
// Oct 5, 2016
//
// Demonstration of Polymorphism.
//
//         [ QUAD        ]
//         [virtual vDraw]
//          ^           ^
//          |           |
//     [SQUAR]       [PARALLELOGRAM]
//[virtual vDraw]    [virtual vDraw]
//
//
//OUTPUT
//Drawing Square
//Drawing Parallelogram
//
//June 20,18  Got rid of virtual on vDraw() function for derived classes.
//            This still works.
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

class Quad{
    private:
        int iL, iR, iB, iT;
    public:
        Quad( int L1, int R1, int B1, int T1){
            iL = L1;
            iR = R1;
            iB = B1;
            iT = T1;
        }
        virtual void vDraw(){
            cout << "Drawing Quad" << endl;
        }
};

class Parallelogram: public Quad{
    
    public:
        Parallelogram(int L,int R, int T, int B):Quad(L,R,T,B){
            
        }
        //virtual void vDraw(){
        void vDraw(){
            cout << "Drawing Parallelogram" << endl;
        }
};

class Square : public Quad{
    public:
        Square( int L): Quad(L,L,L,L){}
        //virtual void vDraw(){
        void vDraw(){
            cout << "Drawing Square" << endl;
        }
};

int
main()
{
    Quad quad(2,2,2,2);
    Square s(5);
    Parallelogram p(5,3,4,2);
    
    vector <Quad*> q;
    
    q.push_back(&quad);
    q.push_back(&s);
    q.push_back(&p);
    
    for(int i=0; i<q.size(); i++){
        q[i]->vDraw();
    }
    
    return 0;
    
}