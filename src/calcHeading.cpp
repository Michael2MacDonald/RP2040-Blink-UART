#include <math.h>

#define RAD_TO_DEG 57.295779513082320876798154814105


struct euler_t { // Holds Euler Yaw, Pitch, And Roll For BNO085
	double yaw;
	double pitch;
	double roll;
} ypr;

void quaternionToEuler(double qr, double qi, double qj, double qk, euler_t* ypr) {
	double sqr = sqrt(qr);
	double sqi = sqrt(qi);
	double sqj = sqrt(qj);
	double sqk = sqrt(qk);

	ypr->yaw = atan2(2.0 * (qi * qj + qk * qr), (sqi - sqj - sqk + sqr));
	// dont calculate pitch because it is causing hrdfaults for some reason
	// ypr->pitch = asin(-2.0 * (qi * qk - qj * qr) / (sqi + sqj + sqk + sqr));
	ypr->roll = atan2(2.0 * (qj * qk + qi * qr), (-sqi - sqj + sqk + sqr));

	ypr->yaw *= RAD_TO_DEG;
	ypr->pitch *= RAD_TO_DEG;
	ypr->roll *= RAD_TO_DEG;

	// Convert Yaw [-180,180] to [0,360]
	ypr->yaw = ypr->yaw - (ypr->yaw * 2);
	if (ypr->yaw < 0) ypr->yaw += 360;

	// Convert Pitch [-180,180] to [0,360]
	ypr->pitch = ypr->pitch - (ypr->pitch * 2);
	if (ypr->pitch < 0) ypr->pitch += 360;

	// Convert Roll [-180,180] to [0,360]
	ypr->roll = ypr->roll - (ypr->roll * 2);
	if (ypr->roll < 0) ypr->roll += 360;
}

double GetHeading(){

	// Fake sensor data for testing
	double real = 2.128;
	double i = 32.7452;
	double j = 6587.0946;
	double k = 8432.2543;

	quaternionToEuler(real, i, j, k, &ypr);

	// How long did the calculation take?
	// static long last = 0;
	// long now = micros();
	// SerialDebug.print(now - last); SerialDebug.print("\t");
	// last = now;

	// Print the results
	// SerialDebug.print(sensorValue.status); SerialDebug.print("\t");  // This is accuracy in the range of 0 to 3
	// // SerialDebug.print(heading); SerialDebug.print("\t");
	// SerialDebug.print(ypr.yaw); SerialDebug.print("\t");
	// SerialDebug.print(ypr.pitch); SerialDebug.print("\t");
	// SerialDebug.println(ypr.roll);

	return ypr.yaw;
}