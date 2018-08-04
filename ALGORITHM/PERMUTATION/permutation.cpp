#include <iostream>
#include <cstring>

using namespace std;

int iCnt = 0;
void
vSwap( char *str, int i, int j )
{
    char cTemp;
    
    cTemp = str[i];
    str[i] = str[j];
    str[j] = cTemp;
}

void
vGetPermutation(char *str, int i, int N )
{
    int j;
    
    if( i == N )
    {
        //if (strlen(str) == N )
       // {
            cout << ++iCnt << ":" << str << endl;
            return;
        //}
    } 
    
    for( j = i; j <=N; j ++ )
    {
        if( j != i ) vSwap( str, j, i );
        vGetPermutation( str, i+1, N );
        if( j != i ) vSwap( str, i, j );
    }
}

int
main(void)
{

    char str1[4] = "MAN";
    //This part is very important.
    //Note that it is very important to send out 1 less than strlen.
    vGetPermutation(str1, 0, strlen(str1)-1 );
    
    char str2[5] = "ABCD";
    iCnt = 0;
    vGetPermutation(str2, 0, strlen(str2)-1);
    
    char str3[6] = "ABCDE";
    iCnt = 0;
    vGetPermutation(str3, 0, strlen(str3)-1 );
    
    return 0;
}
}