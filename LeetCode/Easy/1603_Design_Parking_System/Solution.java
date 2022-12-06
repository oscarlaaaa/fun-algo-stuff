// 2021-02-10
class Solution {
    
    class ParkingSystem {
    
        int[] spots = new int[3];
        
        public ParkingSystem(int big, int med, int small) {
            spots[0] = big;
            spots[1] = med;
            spots[2] = small;
        }
        
        public boolean addCar(int carType) {
            int spottype = carType - 1;
            if (spots[spottype] == 0) {
                return false;
            } else {
                --spots[spottype];
                return true;
            }
        }
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */