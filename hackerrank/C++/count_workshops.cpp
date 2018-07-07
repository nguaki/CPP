//
// Hackerrank
//
// count max number of attentable workshops.
//
#include<bits/stdc++.h>

using namespace std;
#include<algorithm>


struct Workshop{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int n;
    Workshop* buf;
    Available_Workshops(int n):n(n),buf(new Workshop[n]){
    }  //weird but a struct has a constructor.
};

///////////////////////////////////////////////////////////////////////////////////
//Description:  Initialize workshops.
//
//      Input:  start time of each workshop
//              duration of eahc workshop
// 
//      output: Initialized workshops
Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops* res = new Available_Workshops(n);
    for(int i = 0;i < n;++i){
        res->buf[i].start_time = start_time[i];
        res->buf[i].duration   = duration[i];
        res->buf[i].end_time   = start_time[i] + duration[i];
    }
    return res;
}
//////////////////////////////////////////////////////////////////////////////////////
//Description: Call back function for sort().
//             Sort by end time.
//             This is the key of this algorithm problem.
//
//   Input   : 2 distinct workshops
//   
//   Output  : true  if a.end_time is less than b.end_time
//             false if a.end time is greater or equal to b.end_time
//
bool bSortCondition(Workshop &a,Workshop &b){
    return a.end_time < b.end_time;
}

///////////////////////////////////////////////////////////////////////////////////
//Description: Count the max number of attentable workshops.
//
//    Input  : available workshops
//
//    Output : max number of attentable workshops
//
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->buf,(ptr->buf)+ptr->n, &bSortCondition);  //This more readable.
    int curEnd = 0;  //Initialize the end time to zero.
    int res = 0;

    for(int i = 0; i < ptr->n; ++i){  //Again this will increment by the size of WorkShop struct.
        if(ptr->buf[i].start_time >= curEnd){ //Key is to compare if work shop start time is later than current time.
            res++;
            curEnd = ptr->buf[i].end_time;
        }
    }
    
    return res;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}