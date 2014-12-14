#include "SPI.h"
#include "SPIDaisyChain.h"

SPIDaisyChain spi(10, 2);	// CS pin, chained number

byte data[2] = {1, 2};

void setup()
{
}

void loop()
{
	// send data[0] to far device, data[1] to near device
	spi.transferDaisyChain(data);
}
