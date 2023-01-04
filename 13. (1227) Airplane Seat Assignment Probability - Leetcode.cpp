/*
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of the passengers will:

    * Take their own seat if it is still available, and
    * Pick other seats randomly when they find their seat occupied
Return the probability that the nth person gets his own seat.*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        return 1.0/2.0;
    }
};