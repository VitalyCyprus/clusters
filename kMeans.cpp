#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

cv::Mat KMeans(cv::Mat const& image, const int K) 
{
    // Преобразование изображения для использования в K-means
    cv::Mat image_flattened = image.reshape(1, image.total());
    image_flattened.convertTo(image_flattened, CV_32F); // Преобразование в формат с плавающей точкой

    Mat labels, centers;
    // Применение K-means
    kmeans(image_flattened, K, labels, TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0), 3, KMEANS_PP_CENTERS, centers);

    // Преобразование результатов обратно в изображение
    cv::Mat clustered_image = labels.reshape(0, image.rows);
    clustered_image.convertTo(clustered_image, CV_8U);
    clustered_image *= 85; // Умножаем на 85 для визуализации, если K=3 (можете адаптировать под ваше количество кластеров)

    // Отображение результата
    return clustered_image;
}

cv::Mat KMeansWithMorphology(cv::Mat const& image, const int K, int morph_size) {
    // Преобразование изображения для использования в K-means
    cv::Mat image_flattened = image.reshape(1, image.total());
    image_flattened.convertTo(image_flattened, CV_32F); // Преобразование в формат с плавающей точкой

    cv::Mat labels, centers;
    // Применение K-means
    cv::kmeans(image_flattened, K, labels, cv::TermCriteria(cv::TermCriteria::EPS+cv::TermCriteria::COUNT, 10, 1.0), 3, cv::KMEANS_PP_CENTERS, centers);

    // Преобразование результатов обратно в изображение
    cv::Mat clustered_image = labels.reshape(0, image.rows);
    clustered_image.convertTo(clustered_image, CV_8U);
    clustered_image *= 85; // Умножаем для визуализации

    // Постобработка с морфологическими операциями
    cv::Mat morph_result;

    // Создание структурирующего элемента
    //int morph_size = 2; // Размер структурирующего элемента
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT,
                                                 cv::Size(2 * morph_size + 1, 2 * morph_size + 1),
                                                 cv::Point(morph_size, morph_size));

    // Расширение
    cv::dilate(clustered_image, morph_result, element);

    // Сужение
    cv::erode(morph_result, morph_result, element);

    // Отображение результата
   return morph_result;
}

cv::Mat foobar(cv::Mat const& gray)
{
    // Применение алгоритма Собеля
    cv::Mat grad_x, grad_y;
    cv::Mat abs_grad_x, abs_grad_y;
    cv::Mat grad;

    int ddepth = CV_16S; // Глубина изображения
    int ksize = 3; // Размер ядра Собеля
    double scale = 1;
    double delta = 0;

    // Градиент по X
    cv::Sobel(gray, grad_x, ddepth, 1, 0, ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_x, abs_grad_x);

    // Градиент по Y
    cv::Sobel(gray, grad_y, ddepth, 0, 1, ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_y, abs_grad_y);

    // Объединение градиентов
    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);    

    return grad;
}