#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, q,i;

    cin>>n>>q;
    string temp;
    vector<string> hrml;
    vector<string> quer;
    cin.ignore();

    //Populate hrml tag lines 
    for(i=0;i<n;i++){
        getline(cin,temp);
        hrml.push_back(temp);
    }
    
    //Populate query lines
    for(i=0;i<q;i++){
        getline(cin,temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for(i=0;i<n;i++){
        temp=hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end()); //Remove all '\' character.
        temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());  //Remove all '>' character.

        //Ignore the lines that starts with "</"
        if(temp.substr(0,2)=="</"){
            tag.pop_back();
        }
        else{
            stringstream ss;
            ss.str(temp);

            //ss<<temp;  <=== This is another way of assignment.
            string t1,p1,v1;
            char ch;
            ss>>ch>>t1>>p1>>ch>>v1;  //split the string into char and strings.

            string temp1="";

            if(tag.size()>0){
                //temp1= *tag.rbegin();  
                temp1 = tag.back();
                temp1=temp1+"."+t1;
            }
            else
                temp1=t1;
            
            tag.push_back(temp1);
            //m[*tag.rbegin()+"~"+p1]=v1;    //Assign key and value.
            m[tag.back()+"~"+p1] = v1;
            //cout<<"Tag: "<<*tag.rbegin()<<endl;
            while(ss){
                ss>>p1>>ch>>v1;
                //m[*tag.rbegin()+"~"+p1]=v1;
                m[tag.back()+"~"+p1]=v1;
            }
        }
    }

    for(i=0;i<q;i++){
        if (m.find(quer[i]) == m.end())
            cout << "Not Found!\n";
        else
            cout<<m[quer[i]]<<endl;
    }

    return 0;
}
