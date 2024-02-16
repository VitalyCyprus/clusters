#include <clusters.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

void findAllClusters(cv::Mat &img, int min_size = 100, int max_size = 200000, int d = 80);
size_t BfsBuild(int x, int y, cv::Mat &img, BFSCluster &cluster, int threshold);
void clickCluster(cv::Mat &img);

int main(int argc, char** argv) {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::string filename = "/Users/bvi/3d.png";
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
    cv::blur(img, img, cv::Size(3, 3));
    std::cout << "Image size: " << img.size() << std::endl;
    cv::namedWindow("Image", cv::WINDOW_NORMAL);

    //clickCluster(img);
    findAllClusters(img, 1, 2000000, 80);

    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}

void clickCluster(cv::Mat &img)
{
   cv::setMouseCallback("Image", [](int event, int x, int y, int, void* userdata)
    {
        if (event == cv::EVENT_LBUTTONDOWN)
        {
            cv::Mat* image = static_cast<cv::Mat*>(userdata);
            cv::Mat &img = *image; 
            std::cout << "Point: " << x << ", " << y << " = " << static_cast<int>(img.at<uchar>(y, x)) << std::endl;
            BFSCluster cluster(img.cols, img.rows);
            size_t count = BfsBuild(x, y, img, cluster, 1);
            // int count = cluster.build(img, p, [start_value, &img, threshold](cv::Point const& p)
            // {
            //     //std::cout << "compare: " << p << " -> " << (int) img.at<uchar>(p) << " - " << (int) start_value << " = " << std::abs(img.at<uchar>(p) - start_value) << " <= " << threshold << std::endl;
            //     std::cout.flush();
            //     return std::abs(img.at<uchar>(p) - start_value) <= threshold;
            // });

            auto const& points = cluster.points();
            std::cout << "cluster size: " << points.size() << ", " << count << std::endl;
            for (auto const& cur: points)
            {
                img.at<uchar>(cur) = 255;
                std::cout << cur << " ";
            }
            cv::imshow("Image", img);
        }
    }, &img);    
}

void findAllClusters(cv::Mat& img, int min_size, int max_size, int d)
{
    BFSCluster cluster(img.cols, img.rows);
    for (int y = d; y < img.rows; y+=d)
    {
        std::cout << "{[" << y << "]}: ";
        std::cout.flush();
        for (int x = d; x < img.cols; x+=d)
        {
            std::cout << ".";
            std::cout.flush();
            //BFSCluster cluster(img.cols, img.rows);
            size_t count = BfsBuild(x, y, img, cluster, 1);

            auto const& points = cluster.points();
            //if ((points.size() > min_size) && (points.size() < max_size))// 80000)
            {
                std::cout << "cluster size: " << points.size() << std::endl;
                for (auto const& p: points)
                {
                    img.at<uchar>(p) = 255;
                }
            }
            // else{
            //     std::cout << "cluster size: " << points.size() << " - skipped" << std::endl;  
            // }
        }
        std::cout << std::endl;
    }
}

size_t BfsBuild(int x, int y, cv::Mat &img, BFSCluster &cluster, int threshold)
{
    cv::Point p(x, y);
    uchar start_value = img.at<uchar>(p);
    return cluster.build(img, p, [start_value, &img, threshold](cv::Point const &p)
    {
        std::cout.flush();
        return std::abs(img.at<uchar>(p) - start_value) <= threshold; 
    });
}
