void MyLedInit()
{
 rRCC_APB2ENR = rRCC_APB2ENR | (1 << 4); // enable Port C

 rGPIOC_CRL = rGPIOC_CRL & ~(0xf << 24);
 rGPIOC_CRL = rGPIOC_CRL | (0x3 << 24); // set LED 1

 rGPIOC_CRL = rGPIOC_CRL & ~(0xf << 28);
 rGPIOC_CRL = rGPIOC_CRL | (0x3 << 28); // set LED 2

 rGPIOC_CRH = rGPIOC_CRH & ~(0xf << 0);
 rGPIOC_CRH = rGPIOC_CRH | (0x3 << 0); // set LED 3

 rGPIOC_CRH = rGPIOC_CRH & ~(0xf << 4);
 rGPIOC_CRH = rGPIOC_CRH | (0x3 << 4); // set LED 4
}
void MyGpioPollTest()
{
 MyLedInit();

 rRCC_APB2ENR = rRCC_APB2ENR | (1<<5) | (1<<6); // enable Port D, E

 rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 16);
 rGPIOD_CRH = rGPIOD_CRH | (0x8 << 16); // set Select Key

 rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 24);
 rGPIOD_CRH = rGPIOD_CRH | (0x8 << 24); // set Down Key
 
 rGPIOD_CRH = rGPIOD_CRH & ~(0xf << 0);
 rGPIOD_CRH = rGPIOD_CRH | (0x8 << 0); // set Up Key

 rGPIOE_CRL = rGPIOE_CRL & ~(0xf << 0);
 rGPIOE_CRL = rGPIOE_CRL | (0x8 << 0); // set Right Key

 rGPIOE_CRL = rGPIOE_CRL & ~(0xf << 4);
 rGPIOE_CRL = rGPIOE_CRL | (0x8 << 4); // set Left Key

 while(1){
 if( !(rGPIOE_IDR & 0x01) ) // if Right Key is pressed
 {
 rGPIOC_ODR |= (1<<6); // LED 1 ON
 }
 else
 {
 rGPIOC_ODR &= ~(1<<6); // LED 1 OFF
 }
 if( !(rGPIOE_IDR & (0x1 << 1)) ) // if Left Key is pressed
 {
 rGPIOC_ODR |= (1<<7); // LED 2 ON
 }
 else
 {
 rGPIOC_ODR &= ~(1<<7); // LED 2 OFF
 }
 if( !(rGPIOD_IDR & (0x1 << 8)) ) // if Up Key is pressed
 {
 rGPIOC_ODR |= (1<<8); // LED 3 ON
 }
 else
 {
 rGPIOC_ODR &= ~(1<<8); // LED 3 OFF
 }
 if( !(rGPIOD_IDR & (0x1 << 14)) ) // if Down Key is pressed
 {
 rGPIOC_ODR |= (1<<9); // LED 4 ON
 }
 else
 {
 rGPIOC_ODR &= ~(1<<9); // LED 4 OFF
 }
 if( !(rGPIOD_IDR & (0x1 << 12)) ) // if Select Key is pressed
 {
 rGPIOC_ODR |= ((0x1<<6) | (0x1<<7) | (0x1<<8) | (0x1<<9)); // All LED ON
 }
 else
 {
 rGPIOC_ODR &= ~((0x1<<6) | (0x1<<7) | (0x1<<8) | (0x1<<9)); // All LED OFF
 }
 }
}
