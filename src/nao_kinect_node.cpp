#include "ros/ros.h"
#include "std_msgs/String.h"
#include "tf/transform_listener.h"
#include "naoqi_msgs/JointAnglesWithSpeedActionGoal.h"



#include <sstream>
#include <iostream>
#include <string>
#include <vector>



int main(int argc, char **argv)
{
ros::init(argc, argv, "nao_kinect_node");
    ros::NodeHandle node;


    tf::TransformListener listener;

    tf::StampedTransform R01;
    tf::StampedTransform R02;
    tf::StampedTransform R03;
    tf::StampedTransform R10;
    tf::StampedTransform R12;
    tf::StampedTransform R13;

    tf::StampedTransform L01;
    tf::StampedTransform L02;
    tf::StampedTransform L03;
    tf::StampedTransform L10;
    tf::StampedTransform L12;
    tf::StampedTransform L13;


    ros::Rate rate(20.0);
    double a,b,angle;
    double X1,Y1,Z1,X2,Y2,Z2;
    double qr1,ql1,qr2,ql2,qr3,ql3,qr4,ql4;

    double x1,x2;


    naoqi_msgs::JointAnglesWithSpeedActionGoal msg1;
    ros::Publisher publisher = node.advertise<naoqi_msgs::JointAnglesWithSpeedActionGoal>("/joint_angles_action/goal", 1000);


    //initialization ofmsg1 goal vectors

   msg1.goal.joint_angles.joint_names.push_back("LShoulderPitch");
    msg1.goal.joint_angles.joint_names.push_back("LShoulderRoll");
     msg1.goal.joint_angles.joint_names.push_back("LElbowYaw");
      msg1.goal.joint_angles.joint_names.push_back("LElbowRoll");



      msg1.goal.joint_angles.joint_names.push_back("RShoulderPitch");
       msg1.goal.joint_angles.joint_names.push_back("RShoulderRoll");
        msg1.goal.joint_angles.joint_names.push_back("RElbowYaw");
         msg1.goal.joint_angles.joint_names.push_back("RElbowRoll");







    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);

    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);
    msg1.goal.joint_angles.joint_angles.push_back(0);


    msg1.goal.joint_angles.speed=0.5;









    while (node.ok())
    {

       //seveing transforms from tf topic

        try{
          listener.lookupTransform("/neck_1", "/right_shoulder_1",
                                   ros::Time(0), R01);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }


        try{
          listener.lookupTransform("/right_shoulder_1","/neck_1",
                                   ros::Time(0), R10);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/neck_1", "/right_elbow_1",
                                   ros::Time(0), R02);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/neck_1", "/right_hand_1",
                                   ros::Time(0), R03);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/right_shoulder_1", "/right_elbow_1",
                                   ros::Time(0), R12);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }


        try{
          listener.lookupTransform("/right_shoulder_1", "/right_hand_1",
                                   ros::Time(0), R13);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/neck_1", "/left_shoulder_1",
                                   ros::Time(0), L01);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }


        try{
          listener.lookupTransform("/left_shoulder_1","/neck_1",
                                   ros::Time(0), L10);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/neck_1", "/left_elbow_1",
                                   ros::Time(0), L02);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }


        try{
          listener.lookupTransform("/neck_1", "/left_hand_1",
                                   ros::Time(0), L03);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/left_shoulder_1", "/left_elbow_1",
                                   ros::Time(0), L12);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }

        try{
          listener.lookupTransform("/left_shoulder_1", "/left_hand_1",
                                   ros::Time(0), L13);
        }
        catch (tf::TransformException ex){
          ROS_ERROR("%s",ex.what());
          ros::Duration(1.0).sleep();
        }


        ///////CALCULATING VALUES OF ANGLES


        a=-R02.getOrigin().y();
        b=R02.getOrigin().z();



        angle=atan(a/b)*180/(3.141592);

        if(b>0)
        {
            if(a>0)angle=-(180-angle);
            else angle=180+angle;

        }
        qr1=angle;



        a=-L02.getOrigin().y();
        b=L02.getOrigin().z();



        angle=atan(a/b)*180/(3.141592);

        if(b>0)
        {
            if(a>0)angle=-(180-angle);
            else angle=180+angle;

        }
        ql1=angle;





        a=-R02.getOrigin().x()+R01.getOrigin().x();
        b=sqrt(R02.getOrigin().y()*R02.getOrigin().y()+R02.getOrigin().z()*R02.getOrigin().z());



        angle=atan(a/b)*180/(3.141592);

        qr2=angle;



        a=L02.getOrigin().x()-L01.getOrigin().x();
        b=sqrt(L02.getOrigin().y()*L02.getOrigin().y()+L02.getOrigin().z()*L02.getOrigin().z());



        angle=atan(a/b)*180/(3.141592);

        ql2=angle;








               a=-R13.getOrigin().x()+R12.getOrigin().x();
               b=sqrt(R13.getOrigin().y()*R13.getOrigin().y()+R13.getOrigin().z()*R13.getOrigin().z());



               angle=80-atan(a/b)*180/(3.141592);
               if (angle<0) angle=-angle;
        qr3=angle;



        a=L13.getOrigin().x()-L12.getOrigin().x();
        b=sqrt(L13.getOrigin().y()*L13.getOrigin().y()+L13.getOrigin().z()*L13.getOrigin().z());



         angle=80-atan(a/b)*180/(3.141592);
        if (angle<0) angle=-angle;
        ql3=angle;



        X1=R02.getOrigin().x()-R01.getOrigin().x();
        Y1=R02.getOrigin().y()-R01.getOrigin().y();
        Z1=R02.getOrigin().z()-R01.getOrigin().z();


        X2=R03.getOrigin().x()-R01.getOrigin().x();
        Y2=R03.getOrigin().y()-R01.getOrigin().y();
        Z2=R03.getOrigin().z()-R01.getOrigin().z();

        qr4=atan2(R10.getBasis()[2].z() , R10.getBasis()[3].z())*180/(3.141592);

        ql4=atan2(L10.getBasis()[2].z() , L10.getBasis()[3].z())*180/(3.141592);







        //SAVEING ANGLES VALUES IN msg1
        msg1.goal.joint_angles.joint_angles[0]= -ql1/70;
        msg1.goal.joint_angles.joint_angles[1]= ql2/70;
        msg1.goal.joint_angles.joint_angles[3]= -ql3/70;
        msg1.goal.joint_angles.joint_angles[2]= ql4/70-2;

        msg1.goal.joint_angles.joint_angles[4]= -qr1/70;
        msg1.goal.joint_angles.joint_angles[5]= -qr2/70;
        msg1.goal.joint_angles.joint_angles[7]= qr3/70;
        msg1.goal.joint_angles.joint_angles[6]= -qr4/70+2;

        //std::cout <<  msg1.goal.joint_angles.joint_angles[0]<< "  " << msg1.goal.joint_angles.joint_angles[1]<< "  " << msg1.goal.joint_angles.joint_angles[2]<<"  " << msg1.goal.joint_angles.joint_angles[3]<<std::endl;



        publisher.publish(msg1); //Publishing msg1




    rate.sleep();
    }

}
