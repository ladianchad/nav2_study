## Dependency
- ubuntu 20.04
- foxy
- ros navigation2
- etc

#### Install
```bash
sudo apt install ros-foxy-navigation2 ros-foxy-nav2-bringup ros-foxy-turtlebot3*
```
#### build
```bash
cd ~/{FOXY_WS}
colcon build
```

## Docker ( for build test )
```bash
docker build -t navigation
docker run -it --name ros -v $(pwd):/root/foxy_ws/src navigation
cd ..
colcon build
```
