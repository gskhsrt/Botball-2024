#include <kipr/wombat.h>
// future us fix the servo claw

void line_follow(int, int, int, int, int, int, int);

int main()
{

   // printf("Hello World\n");
    //variables
    int black = 2000;
    int servo = 0;
    int tophat = 0;
    int right = 1;
    int left = 0;
    int white = 190;
    int power = 27;
    int et = 1;
    int distance = 900;


    /*backing up
    motor(0,-100);
    motor(1,-100);
    msleep(3000);
    ao();
    */
    //drop the cubes
    enable_servos();
    
    printf("(set servo)");
    set_servo_position(0,0);
    msleep(1000);
    disable_servos(); 
    motor(0,80);
    motor(1,72);
    msleep(4000);

    // driving forward to catch the middle line
    printf("tophat start");
    while (analog(tophat) < black)
    {
        motor(0,80);
        motor(1,72);
        msleep(100);

    };
    
    //forwar tiny bit
    printf("(forward tiny bit)");
    motor(left,80);
    motor(right,72);
    printf("FORWARD TINY BIT");
    msleep(4000);

    // turn left toward the line
    printf("turn Left");
 motor(left,0);
    motor(right,50);
    msleep(500);
    
    // forward toward the line
    printf("FORWARD LINE");
    while (analog(et) > distance)
    {
    	motor(0,80);
    	motor(1,72);
    	msleep(250);
    }

    // left right to align to blocks
    printf("Align To Blocks");
    motor(left, 80);
    motor(right, 0);
    msleep(3400);
    
    // forward to the blocks
    printf("BLOCKS");
    motor(left, 80);
    motor(right, 72);
    msleep(900);
    
    ao();
    
    // turn on servos
    enable_servos();
    // opens the servo for the block
    msleep(1000);
    set_servo_position(servo,0);
    
    // closes the servo for the blocks
    msleep(1000);
    set_servo_position(0,700);
    msleep(1000);
    
    //backup
    printf("backup");
    motor(0,-80);
    motor(1,-72);
    msleep(1000);
    
    // turn right
    motor(0,-80);
        motor(1,0);
    msleep(1000);
    
    //forward minuscual
    motor(0,80);
    motor(1,72);
    msleep(500);
    
    //let blocks go
    set_servo_position(0,0);
    msleep(400);
    disable_servos();
    
    // line follow to the solar panel
    // line_follow(right, left, power, black, tophat, et, distance);

    /* left turn to straighten for the solar panel
    motor(left, 80);
    motor(right, 0);
    msleep(300); */
    
    
    return 0;
}

//-------------------------------------------------------------------
/*
- line follow accepts port numbers and the power value
- to either back up or go forward in the line following
- line follows
*/

void line_follow(int right, int left, int power, int black, int tophat, int et, int distance)
{
    int checker = 0;
    
    while (analog(et) < distance)
    {
        // if sees black goes forward, turn left
        if (analog(tophat) >= black)
        {
            /* motor(left, power);
            motor(right, power);
            msleep(300); */

            motor(left, 0);
            motor(right, power);
            msleep(400);
        }
        // if sees white turns right
        else
        {
            motor(left, power);
            motor(right, 0);
            msleep(400);
        }
        
        // do I need to turn left?
        if (checker == 1)
        {
            // turns left
            motor(left, 0);
            motor(right, power);
            msleep(400);
            
            // changes the checker number so it turns every other time
            checker = 0;
        }
        
        else
        {
            // changes the checker number so it turns every other time
            checker = 1;
        }
        
    }
    
    printf("I got to the end\n");
}
