class ParkingSystem {
public:
    vector<int> a;
    ParkingSystem(int big, int medium, int small) {
        a = {big, medium, small};
    }
    
    bool addCar(int carType) {
        --carType;
        if (!a[carType]) return false;
        --a[carType];
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */