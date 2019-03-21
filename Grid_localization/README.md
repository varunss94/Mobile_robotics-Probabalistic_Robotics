Command to run the code:

cd ~/catkin_ws
$ source devel/setup.bash
cd catkin_make

run   roslaunch uml_hmm hmm.launch ( sepearate terminal) 

open a new terminal

$ source devel/setup.bash

for forward     rosrun uml_hmm localizer +
for backward    rosrun uml_hmm localizer - 


Also the outputs are stored in a text file. Please find output_forward.txt and output_backward.txt for finding this.
The screenshots are named as forward_1,forward_2,backward1-4. please find the same.

Note:
1. The robot will show the high confidence in position when it comes near to the first door, and then it subsequently shows confidence when it moves near to the next door and then the third. Since we strengthen the probabality when it sees the door by 0.8 it shows high confidence.  

2. The robot will show high confidence once again when it comes near to the first door from the left then it subsequently shows confidence when it moves near to the next door and then the third. Since we strengthen the probabality when it sees the door by 0.8 it shows high confidence.  

3. The robot is moved using the command line argument command ' rostopic pub /robot/cmd_vel geometry_msgs/Twist -r 10 [5,0,0] [0,0,0]' to the middle of the world. At this point it dosent know where it is. After this it is moved right where it meets the first door. As discussed above, it shows the high confidence in position when it comes near to the door. Since we strengthen the probabality when it sees the door by 0.8 it shows high confidence.

4. The velocity is fixed at 4ms and the motion model updates are being done at every 8 time steps.This seemed optimal for the detection of door with high confidence.

