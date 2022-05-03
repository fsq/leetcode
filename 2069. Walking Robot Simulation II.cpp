class Robot {
public:
    
    int w, h, dir = 0, x, y;
    
    void move(int& x, int& y, int& dir, int& num) {
        int r = 0;
        if (dir == 0) {
            if (x+1==w) {
                dir = 1;
                return;
            }
            r = min(num, w - x - 1);
            x += r, num -= r;
        } else if (dir == 1) {
            if (y+1==h) {
                dir = 2; 
                return;
            }
            r = min(num, h - y - 1);
            y += r, num -= r;
        } else if (dir == 2) {
            if (x==0) {
                dir = 3;
                return;
            }
            r = min(num, x);
            x -= r, num -= r;
        } else {
            if (y==0) {
                dir = 0;
                return;
            }
            r = min(num, y);
            y -= r, num -= r;
        }
    }
    
    Robot(int width, int height) {
        w = width, h = height;
        x = 0, y = 0;
    }
    
    void step(int num) {
        int loop = num / ((w+h)*2-4);
        num -= (loop-1) * ((w+h)*2-4);
        while (num) {
            move(x, y, dir, num);
            
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        switch (dir) {
            case 0: return "East";
            case 1: return "North";
            case 2: return "West";
            default: return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */