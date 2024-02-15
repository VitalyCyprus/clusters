#include <clusters.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

int main(int argc, char** argv) {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::string filename = "/home/bvi/d3.png";
    if(argc > 1) 
    {
        filename = argv[1];
    }
    std::cout << "Image: " << filename << std::endl;
    cv::Mat img = cv::imread(filename, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Image not found" << std::endl;
        return 1;
    }
    //cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    cv::blur(img, img, cv::Size(3, 3));
    std::cout << "Image size: " << img.size() << std::endl;
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::setMouseCallback("Image", [](int event, int x, int y, int, void* userdata)
    {
        if (event == cv::EVENT_LBUTTONDOWN)
        {
            cv::Mat* image = static_cast<cv::Mat*>(userdata);
            cv::Mat img = *image;   //->clone();
            //cv::rectangle(img, cv::Rect(x-1, y-1, 100, 100), cv::Scalar(255));
            cv::Point p(x, y);
            std::cout << "Point: " << x << ", " << y << " = " << static_cast<int>(img.at<uchar>(p)) << std::endl;
            BFSCluster cluster;
            uchar start_value = img.at<uchar>(p);
            int threshold = 3;
            int count = cluster.build(img, p, [start_value, &img, threshold](cv::Point const& p)
            {
                //std::cout << "compare: " << p << " -> " << (int) img.at<uchar>(p) << " - " << (int) start_value << " = " << std::abs(img.at<uchar>(p) - start_value) << " <= " << threshold << std::endl;
                std::cout.flush();
                return std::abs(img.at<uchar>(p) - start_value) <= threshold;
            });

            auto const& points = cluster.points();
            std::cout << "cluster size: " << points.size() << ", " << count << std::endl;
            for (auto const& p: points)
            {
                img.at<uchar>(p) = 255;
                //std::cout << p << " = " << static_cast<int>(img.at<uchar>(p)) << std::endl;
            }
            //std::cout << "drawing result..." << std::endl;
            //cv::namedWindow("Result", cv::WINDOW_NORMAL);
            //cv::imshow("Result", img);
            cv::imshow("Image", img);
            // std::cout << "showing result..." << std::endl;
            // //cv::waitKey(0);
            // std::cout << "done" << std::endl;
        }
    }, &img);

/*
    int d = 80;

    BFSCluster cluster;
    for (int i = d; i < img.rows; i+=d)
    {
        std::cout << "[" << i << "]: ";
        std::cout.flush();
        for (int j = d; j < img.cols; j+=d)
        {
            std::cout << ".";
            std::cout.flush();
            cluster.build(img, cv::Point(j, i), 1);
            auto const& points = cluster.points();
            //cv::circle(img, cv::Point(j, i), 3, cv::Scalar(255));
            if (points.size() < 100)// || points.size() > 80000)
            {
                continue;
            }
            //cv::Rect rect = cv::boundingRect(points);
            //cv::rectangle(img, rect, cv::Scalar(255));
            std::cout << "cluster size: " << points.size() << std::endl;
            //cv::imshow("Image", img);
            for (auto const& p: points)
            {
                img.at<uchar>(p) = 255;
            }
        }
        std::cout << std::endl;
    }
*/
    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}
