
void MyLedInit() // LED 4 개를 모두 set 하는 함수 {
rRCC_APB2ENR = rRCC_APB2ENR | (1 << 4);
rGPIOC_CRL &= ~((0xf << 24) | (0xf << 28)); rGPIOC_CRL |= ((0x3 << 24) | (0x3 << 28));
rGPIOC_CRH &= ~((0xf << 0) | (0xf << 4));
rGPIOC_CRH |= ((0x3 << 0) | (0x3 << 4)); }
void MyJoyStickInit() // 조이스틱의 모든 스위치를 set 하는 함수 {
rRCC_APB2ENR = rRCC_APB2ENR | (1<<5) | (1<<6); rGPIOD_CRH &= ~((0xf << 16) | (0xf << 24) | (0xf << 0));
rGPIOD_CRH |= ((0x8 << 16) | (0x8 << 24) | (0x8 << 0));
rGPIOE_CRL &= ~((0xf << 0) | (0xf << 4));
rGPIOE_CRL |= ((0x8 << 0) | (0x8 << 4)); }
void MyGpioPollTest() {
MyLedInit();
MyJoyStickInit();
while(1){
if( !(rGPIOE_IDR & 0x01) )
순차적으로 깜빡임 */ break;
}
/* Right Key 를 눌러야만 while 문을 빠져나갈 수 있음,
while 문을 빠져나가고 다음 while 문을 만남으로써 LED 가
rGPIOC_ODR &= ~((1<<6) | (1<<7) | (1<<8) | (1<<9)); // 초기에는 LED 를 전부 OFF 상태로 만듬
while(1){ // 4 개의 LED 가 순차적으로 깜빡이도록 하는 부분 rGPIOC_ODR |= (1<<6); // LED 1 ON
rGPIOC_ODR &= ~(1<<9); // LED 4 OFF
Delay(100); /* 'Delay(n)' 에서 n=100 이면 1 초동안 대기를 함,
1 초 -> n=100 & 3 초 -> n=300 */
rGPIOC_ODR |= (1<<7); // LED 2 ON rGPIOC_ODR &= ~(1<<6); // LED 1 OFF Delay(100);
rGPIOC_ODR |= (1<<8); // LED 3 ON rGPIOC_ODR &= ~(1<<7); // LED 2 OFF Delay(100);
rGPIOC_ODR |= (1<<9); // LED 4 ON rGPIOC_ODR &= ~(1<<8); // LED 3 OFF Delay(100);

} }
// Test_Practice void BoardTest() {
STM3210B_LCD_Init();
MyGpioPollTest(); }
