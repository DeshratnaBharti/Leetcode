class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunk = numBottles;
        int empty = numBottles;

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            totalDrunk += newBottles;
            empty = newBottles + (empty % numExchange);
        }

        return totalDrunk;
    }
};
