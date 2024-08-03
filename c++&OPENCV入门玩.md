# c++&OPENCV入门玩

[4h上手C++版Opencv_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV11A411T7rL/?spm_id_from=333.1007.top_right_bar_window_history.content.click&vd_source=45cf0df1cf29fd12377b442a74b95876)

[OpenCV download | SourceForge.net](https://sourceforge.net/projects/opencvlibrary/)

## 环境搭建

### 解压opencv

![image-20231112152731934](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112152731934.png) 

### 添加环境变量

![image-20231112152702587](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112152702587.png)

### 创建Vs项目

![image-20231112152814854](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112152814854.png) 

### 添加库和链接 

都是![image-20231112161133000](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112161133000.png) 

![image-20231112152837731](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112152837731.png) 

> E:\PROPORECODE\opencv\build\include
>
> E:\PROPORECODE\opencv\build\include\opencv2
>
> E:\PROPORECODE\opencv\build\x64\vc16\bin
>
> E:\PROPORECODE\opencv\build\x64\vc16\lib

1. 包含目录

   E:\PROPORECODE\opencv\build\include

   E:\PROPORECODE\opencv\build\include\opencv2

   ![image-20231112154054341](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112154054341.png) 

2. 库目录

   E:\PROPORECODE\opencv\build\x64\vc16\lib

3. 链接器

4. ![image-20231112154224607](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112154224607.png) 

   ![image-20231112160855470](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112160855470.png) 

> d是debug
>
> 默认是发布realse的，用带d的

### 导入资源问价

![image-20231112161054188](C:/Users/%E8%AE%B8%E9%97%B0%E5%8D%9A/AppData/Roaming/Typora/typora-user-images/image-20231112161054188.png) 

右键项目，拖入Resources目录

### 然后测试

```c++
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,char** argv)
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	imshow("image", img);
	waitKey(0);
	return 0;

}
```

