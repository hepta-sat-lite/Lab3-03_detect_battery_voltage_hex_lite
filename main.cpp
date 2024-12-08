#include "mbed.h"
#include "LITE_EPS.h"
 
RawSerial pc(USBTX,USBRX,9600);
LITE_EPS eps(PA_0,PA_4);
 
int main()
{
    float bt_dec;
    char bt_hex[4];
    for(int i = 0; i < 10; i++) {
        eps.vol(&bt_dec);
        eps.vol_u16(bt_hex);
        pc.printf("Vol = %f\r\n",bt_dec);
        pc.printf("Vol_hex = %c%c%c%c\r\n",bt_hex[0],bt_hex[1],bt_hex[2],bt_hex[3]);
        wait_ms(1000);
    }
}