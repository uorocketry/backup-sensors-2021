#include <ICM_20948.h>
#include <math.h>


#define SERIAL Serial
#define WIRE Wire

#define AD0_VALUE 1 //Set AD0

ICM_20948_I2C imu;




void setup() {
  // put your setup code here, to run once:
  SERIAL.begin(9600);
  WIRE.begin();
  imu.begin(WIRE, AD0_VALUE);

}

void loop() {
  imu.getAGMT();  //Refresh imu data

  SERIAL.print("X: ");
  SERIAL.print(imu.accX());
  SERIAL.print(", ");
  SERIAL.print("Y: ");
  SERIAL.print(imu.accY());
  SERIAL.print(", ");
  SERIAL.print("Z: ");
  SERIAL.print(imu.accZ());
  SERIAL.print(", ");
  SERIAL.print("Temp: ");
  SERIAL.print(imu.temp());
  SERIAL.println();
}
