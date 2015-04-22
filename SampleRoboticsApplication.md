# Introduction #

Imagine a simple robot with one camera sensor and two tank-drive wheels.  This document describes an example architecture using agent-based programming.


# Vision #

We will call the first agent Frame Grabber and put him in charge of reading frames from the camera.  Frame Grabber needs to do a little processing in order to combine the RGB color planes into a jpeg.  The resulting compressed images are sent out to the Agent Network.

Another agent, Line Detector, reads a compressed image from the network and uses a line detection algorithm to find white lines on the ground.  The lines are encoded in slope-intercept form and sent to the network.

Object Detector filters for orange to detect cones in each image.  These objects are encoded as points and sent to the network.


# Planning #

The Environment Model agent keeps track of objects and boundary lines and stores them in a data structure.  Model also reads potential paths and sends out good paths if they do not intercept an obstacle or line.

The Path Generator agent reads target waypoints and generates possible ways to get there.  Path Generator first tries a straight-line path, and then branches out to many variants.  Each potential path is sent to the network.

The Navigator agent reads waypoints from a file and sends them to the network.


# Control #

The Driver agent reads the latest unobstructed path and generates left and right wheel speeds.

Left Wheel and Right Wheel read wheel speeds and send control signals to the actuators.


# Conclusion #

Notice how none of the agents in the above system (Frame Grabber, Path Generator, etc) are defined in terms of other agents.  Each agent is entirely independent.  Only datagrams (line, waypoint, wheel speed, etc) are understood by multiple agents.