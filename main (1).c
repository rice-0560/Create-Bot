#include <kipr/wombat.h>
  int claw= 0;
  int open=1050;
  int close=100;
  int speed=-1000;
  void drive_m_fwd(float m);
  void turnright(int degrees);
  void turnleft(int degrees);


int main()
{
    enable_servos(); 
    create_connect();
    drive_m_fwd(1);
    turnleft(70);
    drive_m_fwd(0.8);
    turnright(70);
    
    disable_servos();
    return 0;
}

drive_m_fwd(float m)
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
