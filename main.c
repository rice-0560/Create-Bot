#include <kipr/wombat.h>
  int claw= 0;
  int open=1350;
  int close=2030;
  int leftspeed=-102;
  int rightspeed=-99;
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
    drive_m_fwd(40);
    while(get_create_lcliff_amt() > 1000)
    {
        create_drive_direct(leftspeed,rightspeed);
        msleep(10);
    }
    create_stop();
    drive_m_fwd(20);
    turnleft(100);
    while(get_create_lfcliff_amt() > 1000)
    {
        create_drive_direct(leftspeed,rightspeed);
        msleep(10);
    }
    create_disconnect();
    return 0;
}

drive_m_fwd(int m)
{
    set_create_distance(0);
    while (abs(get_create_distance()) < m * 10)
    {
        create_drive_direct(leftspeed,rightspeed);
}
}
turnright(int degrees)
{
    set_create_total_angle(0);
    while (abs(get_create_total_angle()) < degrees)
    {
        create_drive_direct(-leftspeed, rightspeed);
        printf("angle = %d\n", get_create_total_angle());
    }
}
turnleft(int degrees)
{
    set_create_total_angle(0);
    while (abs(get_create_total_angle()) < degrees)
    {
        create_drive_direct(leftspeed, -rightspeed);
        printf("angle = %d\n", get_create_total_angle());
    }
}
