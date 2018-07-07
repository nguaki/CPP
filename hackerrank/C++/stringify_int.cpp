// Hackerank
//
// Converts integer overflow into string
//
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#include <sstream>

std::ostringstream oss;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
        int t;
    int a[100]; //array will have the capacity to store 1000 digits.
    //string cpp_a;
    int n,i,j,temp,m,x, k;
    int iBase;
    vector<string> vPowerOf2;
    int T;
    string str;

    
    //scanf("%d",&t);
    for( n = 0; n <= 800; n++)
    {
        //cpp_a.clear();
        a[100] = {0};
        //strcpy(a, "");
       //a.clear();
       //scanf("%d",&n);// n is the power.
       a[0]=1;  //initializes array with only 1 digit, the digit 1.
       m=1;    // initializes digit counter
       iBase=2;// i is base 2
       int k=1;//k is a counter that goes from 1 to  n.
       temp = 0; //Initializes carry variable to 0.
       while(k<=n)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*iBase+temp; //x contains the digit by digit product
               a[j]=x%10; //Contains the digit to store in position j
               temp = x/10; //Contains the carry value that will be stored on later indexes
            }
             while(temp>0) //while loop that will store the carry value on array.
             { 
               a[m]=temp%10;
               temp = temp/10;
               m++; // increments digit counter
             }
             k++;
      }
      
      oss.str("");
      for(i=m-1;i>=0;i--) //printing answer
      {
       oss << a[i];  // <== This was the only way make int capture into string. 
      }
        
       vPowerOf2.push_back(oss.str());
    }

    int iPos;
    int iMaxBinaryCnt = 801;
    cin >> T;
    int iFound, iTotalFound = 0;
    while( T-- )
    {
        cin >> str;
        
        //cout << "str = " << str << endl;
        i = 0;
        int iCount = 0;
        size_t size_t_k;
        //cout << " i = " << i << endl;
        
        int iStrSize = str.size();
        
        while( vPowerOf2[i].size() <= iStrSize && i < iMaxBinaryCnt){
            
            string key = vPowerOf2[i];
           iPos = 0;

            iFound = 0;
              for (size_t offset = str.find(key); offset != std::string::npos;
	                                               offset = str.find(key, offset + key.length()))
              {
                    ++iCount;
               }

           i++;
        }
        cout << iCount << endl;
        
    }
    
    return 0;
}
