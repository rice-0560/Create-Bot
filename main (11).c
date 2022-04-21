#include <kipr/wombat.h>
  int claw= 0;
  int open=1050;
  int close=100;
  int speed=-200;
  void drive_m_fwd(int m);
  void turnright(int degrees);
  void turnleft(int degrees);


int main()
{
    //wait_for_light(0);
    enable_servos(); 
    set_servo_position(claw, close);
    create_connect();
    //start game
   
    turnleft(110);
  
    disable_servos();
    return 0;
}

drive_m_fwd(int m)
{
    set_create_distance(0);
    while (abs(get_create_distance()) < m * 1000)
    {
        create_drive_straight(speed);
}
}
turnright(int degrees)
{
    set_create_total_angle(0);
    while (abs(get_create_total_angle()) < degrees)
    {
        create_drive_direct(-speed, speed);
    }
}
turnleft(int degrees)
{
    set_create_total_angle(0);
    while (abs(get_create_total_angle()) < degrees)
    {
        create_drive_direct(speed, -speed);
    }
}
