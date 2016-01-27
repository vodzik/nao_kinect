REQUIREMENTS

Ths paskage reqiure NaoQI SDK, and basic nao/naoqi packages, and openni_tracker package. It was made for ROS hydro release. It haven't been tested on other versions. 

PREPERING NAO ----

Before you use nao_kinect node, you must first start topics that connect NAO to ROS.
The easyest way to do this is type:

LD_LIBRATY_PATH=~usr/naoqi-sdk-2.1.3.3-linux64/lib:$LD_LIBRARY_PATH NAO_IP=10.104.16.52 roslaunch nao_bringup nao_full.launch force_python:=true

But first you must change LD_LIBRATY_PATH value to directory of naoqisdk liblary on your computer and NAO_IP to ip adress of your NAO.

You can propably also start ROS nodes on NAO, but this metod wasnt tested with this package

NAO_KINECT_NODE ----
zbierać
nao_kinnect_node mirror user hands movement in NAO robot. It requires informations from openni_tracker to operate. 

You can crun openni_tracker node from openni_tracker package to collect information of user posture, or you can open both nodes via nao_kinnect.lanch file, but it is not reccomendet, because it dont display openni_tracker logs.

Bewere, becaus it will mirror only User 1 posture, so you sometimes have to restart openni_tracker

