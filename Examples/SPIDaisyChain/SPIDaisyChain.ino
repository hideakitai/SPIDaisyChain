#include "SPI.h"
#include "SPIDaisyChain.h"

const uint8_t PIN_CS = 10;
const uint8_t NUM_DEVICE = 3;
SPIDaisyChain spi(PIN_CS, NUM_DEVICE);	// CS pin, chained number

byte send_data[NUM_DEVICE] = {1, 2, 3};
byte* recv_data;

void setup()
{
}

void loop()
{
    // send data[0] to far device, data[1] to near device
    recv_data = spi.transferDaisyChain(send_data);

    for (uint8_t i = 0; i < NUM_DEVICE; ++i)
    {
        Serial.print(recv_data[i], HEX); Serial.print(" ");
    }
    Serial.println();
}
