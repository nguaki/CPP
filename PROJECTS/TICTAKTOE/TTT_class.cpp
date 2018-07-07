#include <iostream>
#include "ttt.h"
using namespace std;

TTT::TTT()
{ 
        for( iRow=0; iRow<3; iRow++)
            for( iCol=0; iCol <3; iCol++ )
                caChartData[iRow][iCol] = ' ';
        
        iCurrPlayer = 0;
        iPlayCnt = 0;
}

void TTT::vSwitchPlayer()
{
    (iCurrPlayer == 0 ) ? iCurrPlayer = 1 :iCurrPlayer = 0;
}
bool TTT::bCheckWinningMove()
{
    for( iRow = 0; iRow < 3; iRow++ )
        if( (caChartData[iRow][0] == caChartData[iRow][1]) && 
                (caChartData[iRow][1]==caChartData[iRow][2]) && 
                    caChartData[iRow][0] != ' ' ) 
        return true;
    for( iCol = 0; iCol < 3; iCol++ )
        if( (caChartData[0][iCol] == caChartData[1][iCol]) && 
                (caChartData[1][iCol]==caChartData[2][iCol]) && 
                    caChartData[0][iCol] != ' ' ) 
        return true;
        
    if( (caChartData[0][0] == caChartData[1][1] ) &&
            (caChartData[1][1] == caChartData[2][2] &&
                    caChartData[0][0] != ' ' ) )
    return true;
    if( (caChartData[0][2] == caChartData[1][1] ) &&
            (caChartData[1][1] == caChartData[2][0] &&
                    caChartData[0][2] != ' ' ) )
    return true;
            
    return false;
        
}
bool TTT::bStartGame()
{
    DrawChart();
    
    do{
        GetCoordinate();
    }while( bCheckSpaceIsTaken() == false );
    
    vAssignData();
    
    if ( bCheckWinningMove() ){
        vPrintPlayer(); 
        cout << " wins!!!";
        return true;
    };
    
    vSwitchPlayer();
    DrawChart();

    return false;

}
void TTT::vAssignData()
{
     ( iCurrPlayer == 0 ) ? caChartData[iYCoordinate][iXCoordinate] = 'O' : caChartData[iYCoordinate][iXCoordinate] = 'X';
}

bool TTT::bCheckSpaceIsTaken()
{
    if(caChartData[iYCoordinate][iXCoordinate] != ' '){
        cout << "Sorry, the space is already take!!!"  << endl;
        return false;
    }
    else return true;
}
bool TTT::bCheckXOutOfRange()
{
    if( iXCoordinate < 0 || iXCoordinate > 2 ) return true;
    else return false;
}
bool TTT::bCheckYOutOfRange()
{
    if( iYCoordinate < 0 || iYCoordinate > 2 ) return true;
    else return false;
}

void TTT::vPrintPlayer()
{
    if(iCurrPlayer == 0) cout << "Player O ";
    else cout << "Player X ";
}

void TTT::GetCoordinate()
{
    do{
        vPrintPlayer();
        cout << "Enter [0,1,2] for X coordiate ";
        cin >> iXCoordinate;
         if( bCheckXOutOfRange() ) cout << "OUT OF RANGE!!! " << endl;
    }while( bCheckXOutOfRange());
   
    do{
        vPrintPlayer();
        cout << "Enter [0,1,2] for Y coordiate ";
        cin >> iYCoordinate;
        if( bCheckYOutOfRange() ) cout << "OUT OF RANGE!!! " << endl;
    }while( bCheckYOutOfRange());

}    
bool TTT::bCheckEmptySpace()
{
    for( iRow = 0; iRow<=2; iRow++)
        for( iCol = 0; iCol<=2; iCol++)
            if( caChartData[iRow][iCol] == ' ')
            return true;
    return false;
}
void TTT::DrawChart()
{
  
  for( iRow=0; iRow<3; iRow++)
  {
    for( iCol=0; iCol <3; iCol++ )
    {
        cout << caChartData[iRow][iCol] << ' ';
    } 
    cout << endl;
  }     
}
