//Hacker Rank
//Get Imaginary numbers
//
//Input
//3+i4
//5+i6
//
//Output
//8+i10
//

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator + (const Complex &obj1, const Complex &obj2) {
    Complex objTemp;
    
    objTemp.a = obj1.a + obj2.a;
    objTemp.b = obj1.b + obj2.b;
    
    return objTemp;
    /*... body ...*/ 
}


ostream &operator << ( ostream &ostr, const Complex  &obj) {
    return ostr << obj.a << "+i" << obj.b;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

