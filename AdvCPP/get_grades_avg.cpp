//Aug 21, 2016
//Utilizes stringstream to temporarily storages.
//
//OUTPUT
//Average : 80
//
//grades.txt has the following line:
//60 70 80 90 100
//

 #include <iostream>
 #include <sstream>
 #include <fstream>
 
 using namespace std;
 
 int
 main(){
  ifstream fGrades;
  stringstream ssGrades;
  string sLine;
  int iGrade, iTotal;
  
  //grades.txt has following data: 60  70 80 90 100
  fGrades.open("grades.txt");
  getline(fGrades, sLine);  //Reads entire line.
  ssGrades << sLine; //Transfers the entire line to stringstream type.
                     //Remember that this text file only contains one line.
  fGrades.close();
  
  iTotal = 0;
  for( int i=0; i<5; i++ ){   //5 is already know number.
                              //Goes each loop and sets each value to variable iGrade.
    ssGrades >> iGrade;
    iTotal += iGrade; 
  }
  
  cout << "Average : "  << iTotal / 5;
  
  return 0;
 }