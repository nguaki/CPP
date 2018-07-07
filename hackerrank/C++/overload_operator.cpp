#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box 
{ 
    private: 
        long l,b,h;

    public:
        Box():l(0),b(0),h(0)
        {
            BoxesCreated++;
        }

        Box(int length,int breadth,int height):l(length),b(breadth),h(height)
        {
            BoxesCreated++;
        }
    
        Box(const Box &B):l(B.l),b(B.b),h(B.h)
        {
            BoxesCreated++;
        }
        ~Box()
        {
            BoxesDestroyed++;
        }
        int getLength()
        {
            return l;
        }
        int getBreadth()
        {
            return b;
        }
        int getHeight()
        {
            return h;
        }
        unsigned long long CalculateVolume()
        { 
            unsigned long long volume=(unsigned long long)l*(unsigned long long)b*(unsigned long long)h; 
            return volume; 
        }
              

        //Overloading < operator.
        bool operator <(const Box &B){ 
            if( l < B.l) return true;
        
            if( (b < B.b) && (l == B.l) ) return true;
        
            if( (h < B.h) && (l == B.l && b == B.b) ) return true;
        
            return false;   
        } 

        //Overloading << operator.
        friend ostream &operator<<( ostream &output, Box D)  //<==This didn't work if it wasn't for friend declaration.
                                                    //    I don't understand the reason.
        { 
            output << D.getLength()<<" " <<D.getBreadth() << " " << D.getHeight();
            return output;            
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;

	for(int i=0;i<n;i++)
    	{
    		int type;
    		cin>>type;
    		if(type ==1)
        	{
            		cout<<temp<<endl;
        	}
        
		if(type == 2)
        	{
            		int l,b,h;
            		cin>>l>>b>>h;
            		Box NewBox(l,b,h);
            		temp=NewBox;
            		cout<<temp<<endl;   //Uses overload << operator
        	}
        	if(type==3)
        	{
            		int l,b,h;
            		cin>>l>>b>>h;
            		Box NewBox(l,b,h);
            		if(NewBox<temp)   //Uses overload < operator
            		{
                		cout<<"Lesser"<<endl;
        		}
            		else
            		{
                		cout<<"Greater"<<endl;
            		}
        	}
        	if(type==4)
        	{
            		cout<<temp.CalculateVolume()<<endl;
        	}
        	if(type==5)
        	{
            		Box NewBox(temp);
            		cout<<NewBox<<endl;
        	}

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
