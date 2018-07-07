#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > noOverlaps(vector<pair<int, int> >& input) {
    if (input.size() <= 1) {
        return input;
    }
    vector<pair<int, int> > result;
    result.push_back(input[0]);

    for (int i = 1; i < input.size(); ++i) {
        //If overlap
        if (input[i].first < result.back().second) {
            //auto lastOne = result.back();
            pair<int, int> lastOne = result.back();
            result.pop_back();
            result.push_back(make_pair(lastOne.first, input[i].first));
            if (lastOne.second > input[i].second) {
                result.push_back(make_pair(input[i].first, input[i].second));
                result.push_back(make_pair(input[i].second, lastOne.second));
            } else {
                result.push_back(make_pair(input[i].first, lastOne.second));
                result.push_back(make_pair(lastOne.second, input[i].second));
            }
        } else {
            result.push_back(input[i]);
        }
    }
    return result;
}

int
main()
{
// [1,3],[2,5],[7,15],[8,9],[12,19]
    vector<pair<int,int> > vecData, vecResult;
    pair<int, int> pData;
    vector<pair<int,int> >::iterator itVec;
    
    pData = make_pair(1,3);
    vecData.push_back(pData );
    pData = make_pair(2,5);
    vecData.push_back(pData );
    pData = make_pair(7,15);
    vecData.push_back(pData );
    pData = make_pair(8,9);
    vecData.push_back(pData );
    pData = make_pair(12,19);
    vecData.push_back(pData );
   
    for( itVec=vecData.begin(); itVec!=vecData.end(); itVec++)
    {
        //cout << itVec.first << "  "  << itVec.second << endl;
        cout << itVec->first << "  "  << itVec->second << endl;
    }
    
    cout << "==================================================" << endl;
    vecResult = noOverlaps(vecData);
    for( itVec=vecResult.begin(); itVec!=vecResult.end(); itVec++)
    {
        //cout << itVec.first << "  "  << itVec.second << endl;
        cout << itVec->first << "  "  << itVec->second << endl;
    }
    
    
    return 0;
}