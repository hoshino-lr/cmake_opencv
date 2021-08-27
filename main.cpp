#include <iostream>
#include "config.h"
#include "opencv2/opencv.hpp"
#ifdef show_picture
#include "show_picture.h"
#endif
int main() {
    cv::Mat src = cv::imread("..\\cmake-logo-16.png");
#ifdef show_picture
show_pic(src);
#endif
    return 0;
}