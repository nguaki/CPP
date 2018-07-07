class TTT{
    private:
        char caChartData[3][3];
        int iRow, iCol;
        int iCurrPlayer;
        int iXCoordinate, iYCoordinate;
         
    public:
        int iPlayCnt;
        TTT();
        void DrawChart();
        bool bStartGame();
        void GetCoordinate();
        bool bCheckSpaceIsTaken();
        void vPrintPlayer();
        bool bCheckXOutOfRange();
        bool bCheckYOutOfRange();
        void vAssignData();
        bool bCheckWinningMove();
        void vSwitchPlayer();
        bool bCheckEmptySpace();
};
