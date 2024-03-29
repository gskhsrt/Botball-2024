#include <kipr/wombat.h>
// port 0 red port 1 black top
// right port 1 needs more power to drive straight
int main()
{
    ///variables
    int black = 2000;
    int servo = 0;
    int tophat = 0;
    int right = 2;
    int left = 0;
    int power = 27;
    int white = 190;
    int et = 1;
    int distance = 900;
    
    //drop the cubes
    enable_servos();
    
    printf("(set servo)");
    set_servo_position(0,0);
    msleep(1000);
    disable_servos(); 
    motor(left,72);
    motor(right,82);
    msleep(4000);

    // driving forward to catch the middle line
    printf("tophat start");
    while (analog(tophat) < black)
    {
        motor(left,72);
        motor(right,82);
        msleep(100);

    };
    
    ao();
    
    //forwar tiny bit
    motor(left,72);
    motor(right,82);
    msleep(2000);
    
    // turn left toward tower
    motor(left,0);
    motor(right,82);
    msleep(2400);
    
    // forward to reach the blocks
    motor(left,72);
    motor(right,82);
    msleep(600);
    
    ao();
    msleep(3000);

    // closes the servo for the blocks
    enable_servos();
    msleep(1000);
    set_servo_position(0,800);
    msleep(1000);
    
    //backup
    printf("backup");
    motor(left,-80);
    motor(right,-72);
    msleep(1000);
    
    // turn right
    motor(left,72);
    motor(right,0);
    msleep(1000);
    
    ao();
    
    //let blocks go
    set_servo_position(0,0);
    msleep(400);
    disable_servos();
    
    return 0;
}
