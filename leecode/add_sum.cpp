#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        vector<int> X;
        short sFound = 0;
        
        for( i = 0; i <nums.size(); i++ ){
            
            for( j = i+1; j<nums.size(); j++ ){
                if(target == (nums[i]+nums[j])){
                    sFound = 1;
                    X.push_back(i);
                    X.push_back(j);
                    break;
                }
            }
            if( sFound ) break;
            //cout << nums[i] << endl;
        }

    return X;
    }
};

int
main()
{
  vector<int> viArray, viAnswer;
  int i;
  
  Solution *objSol = new Solution();
  
  viArray.push_back(1);
  viArray.push_back(3);
  viArray.push_back(5);
  
  int target = 8;
  
  //viAnswer = twoSum(viArray, target);
  viAnswer = objSol->twoSum(viArray, target);
  
  for( i=0; i<viAnswer.size(); i++){
      cout << viAnswer[i] << endl;
  }
  
}
