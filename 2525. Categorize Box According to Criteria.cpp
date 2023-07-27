class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long v = (long long)length * width * height;
        bool bk = v>=1e9 || (length>=1e4 || width>=1e4 || height>=1e4);
        bool hv = mass >= 100;
        if (bk && hv)
            return "Both";
        else if (bk)
            return "Bulky";
        else if (hv)
            return "Heavy";
        else 
            return "Neither";
    }
};