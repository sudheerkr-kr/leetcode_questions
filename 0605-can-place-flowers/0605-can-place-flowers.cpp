class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int count = 0;

        for(int i = 0; i < flowerbed.size(); i++) {

            bool left = (i == 0) || (flowerbed[i-1] == 0);
            bool right = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);

            if(flowerbed[i] == 0 && left && right) {

                flowerbed[i] = 1;
                count++;

                if(count >= n)
                    return true;
            }
        }

        return count >= n;
    }
};