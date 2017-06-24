#ifndef HARDPOINT_H_
#define HARDPOINT_H_

// Fixed - direct fire, entire ship/hardpoint must be pointed (Usually used on ships)
// 2-Axis Gimbal - XY rotation for the turret


enum HPTYPE {HPT_FIXED, HPT_2GIMBAL, HPT_3GIMBAL};

// Generic Fixed hardpoint
class HardPoint{
public:
	HardPoint();
};


class HardPoint2Gimbal : public HardPoint{
public:
	HardPoint2Gimbal();
	
	float angleX; // Angle turret yaw  (Max is 180 degrees)
	float angleY; // Angle turret pitch (Max is 359.999~ degrees)
	
	// Torque in newton-meter (N·m)
	float torqueX; // Torque also includes the Y-axis turning mechanism's mass.
	float torqueY; // Torque only includes the weapon's mass.
	
	void tick2(double time); // tick amount of time
};


#endif