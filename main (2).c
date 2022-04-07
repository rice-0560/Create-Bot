#include <kipr/wombat.h>
  int claw= 0;
  int open=1350;
  int close=2030;
  int speed=-200;
  void drive_m_fwd(int cm);
  void turnright(int degrees);
  void turnleft(int degrees);


int main()
{
    //wait_for_light(0);
    enable_servos(); 
    set_servo_position(claw, close);
    create_connect();
    //start game
    drive_m_fwd(120);
    msleep(300);
    turnleft(90);
    msleep(300);
    drive_m_fwd(80);
    msleep(300);
    turnright(90);
    msleep(300);
    set_servo_position(claw, open);
    msleep(300);
    drive_m_fwd(70);
    msleep(300);
    set_servo_position(claw, close);
    msleep(300);
    turnright(90);
    msleep(300);
    drive_m_fwd(55);
    msleep(300);
    turnright(90);
    //15-30 seconds
    drive_m_fwd(100);
    turnleft(40);
    drive_m_fwd(70);
    disable_servos();
    return 0;
}

drive_m_fwd(int m)
{
    set_create_distance(0);
    while (abs(get_create_distance()) < m * 10)
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
