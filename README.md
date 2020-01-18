# ManualSegmentationTool
## Features
The main features of this simple tool are:
* Two different types of manual segmentation. 
* Single points may be added by left mouse button and mask is represented by this polygon.
* Continuous border depicting while right button pressed.
* Possibility to delete points, to make corrections before saving.
* 4 different views on the segmentation mask.
* All sizes of images may be processed.
* Scalable, tool is capable of processing a high number of images.

## Installation
### Ubuntu
On ubuntu, there are few things to install as prerequisites:
```
sudo apt install libglew3-dev libglu1-mesa-dev
```
Next, you have to install OpenCV, which is used to process images. You can use this tutorial, which is simple, but recommended:

[OpenCV installation](https://www.pyimagesearch.com/2018/05/28/ubuntu-18-04-how-to-install-opencv/)

Finally, please change the line 40 in **CMakeLists.txt** according to the compiler you are using.
```CMake
target_link_libraries(manual_segmentation_tool /usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a)
```

The main installation process:
```bash
git clone https://github.com/branislavhesko/Manual-Segmentation-Tool.git
cd Manual-Segmentation-Tool
```
Compilation:
```bash
mkdir build && cd build
cmake ..
make -j4
```

After successfull compilation, you may start your ManualSegmentation tool, but first:

* Create *images* dir in the build folder.
* Put your images, which you want to manually segment into this folder.
* Make a simple *categories.txt* file in your build folder and add there up to 10 different categories you want to segment.
* Start the program and prepare your data. 


**If you encounter any problem or something is not working, please contact me at branislav.hesko@protonmail.ch**


### Windows
The application is also supported on Windows 10. There are two prerequisites to compile the app. First you have to install DirectX9 runtime framework, download is available at:

[DirectX9](https://www.microsoft.com/en-US/download/details.aspx?id=34429).

Next, please compile OpenCV library and put binaries in you path. Some tutorial:

[OpenCV windows installation](https://www.learnopencv.com/install-opencv3-on-windows/).

Manual segmentation tool compiplation is then similar to ubuntu compilation, use CMakeLists.txt, which is adapted to both ubuntu and windows compilation.
The main installation process (you may also use IDEs like Visual Studio or Clion to compile the program):
```bash
git clone https://github.com/branislavhesko/Manual-Segmentation-Tool.git
cd Manual-Segmentation-Tool
```
Compilation:
```bash
mkdir build && cd build
cmake ..
make -j4
```

**If you encounter any problem or something is not working, please contact me at branislav.hesko@protonmail.ch**

## Usage
There are few keyboard shortcuts you should know and use:
* **A** - fill polygon and add it into segmentation mask.
* **E** - remove a single point from the contour.
* **D** - remove multiple points from the contour.
* **ESC* - when focused on the segmentation window, image segmentation is saved and program continues to the next image.

## TODO:
- [] Add better program exiting.
- [] Add support for image skipping.