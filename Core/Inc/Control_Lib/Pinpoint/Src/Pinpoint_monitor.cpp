#include <Control_Lib/Pinpoint/Inc/Pinpoint.hpp>
#include <Control_Lib/Pinpoint/Inc/Pinpoint_monitor.hpp>
#define update_period 50

extern PinpointI2C pinpoint;
extern PinpointI2C::BulkData bd;
extern int sec;

void pinpoint_init(){
	pinpoint.Pinpoint_Init();
}
void pinpoint_monitor(){
	if (sec == update_period){
		pinpoint.Pinpoint_TaskLoop();
		sec = 0;
	}
}
