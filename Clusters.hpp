#include <opencv2/opencv.hpp>
#include <vector>

class Clusters {
public:
    static std::vector<Clusters> findClusters(cv::Mat const& image) {
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        std::vector<Clusters> clusters;
        for (const auto& contour : contours) {
            if (cv::contourArea(contour) > 1) { // Фильтруем слишком маленькие контуры
                clusters.emplace_back(contour, cv::Scalar(0, 255, 0));
            }
        }

        return clusters;
    }

    static std::vector<Clusters> findClusters__(cv::Mat const& image) {
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(image, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        std::vector<Clusters> clusters;
        for (const auto& contour : contours) {
            Clusters cluster(contour, cv::Scalar(0, 255, 0)); // Задаем цвет для каждого кластера
            clusters.push_back(cluster);
        }

        return clusters;
    }

    std::vector<cv::Point> contour;
    cv::Scalar color;

    Clusters(const std::vector<cv::Point>& contour, cv::Scalar color) : contour(contour), color(color) {}

    // Возвращает площадь кластера
    double area() const {
        return cv::contourArea(contour);
    }

    // Возвращает центроид кластера
    cv::Point2f centroid() const {
        cv::Moments m = cv::moments(contour, true);
        return cv::Point2f(m.m10 / m.m00, m.m01 / m.m00);
    }

    // Зарисовывает кластер на изображении заданным цветом
    void draw(cv::Mat& image) const {
        cv::drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, color, cv::FILLED);
    }
};

