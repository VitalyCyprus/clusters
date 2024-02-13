#include <opencv2/opencv.hpp>

#include <iostream>

int main() {
    cv::Mat img = cv::imread("/Users/v.bezugly/lena.png");
    if (img.empty()) {
        std::cerr << "Image not found" << std::endl;
        return 1;
    }

    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}
