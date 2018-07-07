//Hackerrank
//
// 2 dimensional array whern each row has distinct size.
//

#include <iostream>
using namespace std;

int main() {
    int N, Q;

    cin >> N >> Q;
    int *ip[N];

    for( int i = 0; i < N;i++ ){
        int iMaxIndex, iNum;
        cin >> iMaxIndex;
        ip[i] = (int *)malloc(iMaxIndex*sizeof(int));
        for( int j=0; j < iMaxIndex; j++ ){
            cin >> iNum;
            ip[i][j] = iNum;
        }
    }

    for( int i = 0; i< Q; i++ ){
        int a, b;
        cin >> a >> b;
        cout << ip[a][b] << endl;
    }

    for( int i = 0; i < N; i ++ )
        free(ip[i]);
	return 0;
}
