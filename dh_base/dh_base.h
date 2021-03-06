#ifndef DH_BASE_H__
#define DH_BASE_H__

#include "Stream.h"

class Module
{
  public:
	attachDevice(LocalDevice *pDevice, uint8_t id)
	{
		clock = pDevice->getClock();
		logger = pDevice->getLogger();

		init();
	}

	virtual bool write(uint16_t pVariableID) = 0;

	virtual Result read(utin16_t pVariableID) = 0;

  protected:
	virtual void init() = 0;

	uint32_t getNetworkTime()
	{
		if (clock != NULL)
		{
			return clock.getNetworkTime();
		}else{
			return 0;
		}
	}

	uint32_t getDeviceTime()
	{
		if (clock != NULL)
		{
			return clock.getDeviceTime();
		}else{
			return 0;
		}
	}

	Logger* getLogger(){ return logger;}

  private:
	uint8_t id;
	DeviceClock *clock = NULL;
	Logger *logger = NULL;
}

#endif
