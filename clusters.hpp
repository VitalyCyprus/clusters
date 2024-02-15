#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <queue>
#include <functional>

class Cluster
{
protected:
    using Points = std::vector<cv::Point2i>;
    Points points_;
public:
    Cluster() = default;
    virtual ~Cluster() = default;
    Cluster(Points const& points): points_(points.begin(), points.end()) {}
    Points const& points() const { return points_; }
    virtual size_t build(cv::Mat const& m, cv::Point const& start, std::function<bool (cv::Point const&)> compare) = 0;
};

class BFSCluster: public Cluster
{
    std::vector<std::vector<uchar>> visited_pixels_;
public:
    virtual ~BFSCluster() = default;
    using Cluster::Cluster;
    size_t build(cv::Mat const& m, cv::Point const& start, std::function<bool (cv::Point const&)> compare) override
    {
        std::array<cv::Point, 8> directions = {
            cv::Point(-1, 0),  cv::Point(0, -1), cv::Point(1, 0), cv::Point(0, 1),
            cv::Point(-1, -1), cv::Point(1, -1), cv::Point(1, 1), cv::Point(-1, 1)
        };

        VisitedMatrix visited(m.rows, m.cols);

        std::queue<cv::Point> queue;

        if (!isInBounds(m, start)) {
            return 0;
        }

        queue.push(start);

        while (!queue.empty())
        {
            cv::Point current = queue.front();
            queue.pop();

            points_.push_back(current);

            for (auto const& direction: directions)
            {
                cv::Point next = current + direction;
                std::cout << "next: " << next << std::endl;
                if (isInBounds(m, next) && !visited.isVisited(next)) 
                {
                    if(compare(next)) 
                    {
                        queue.push(next);
                        visited.setVisited(next);
                    }
                }
            }
        }

        return points_.size();
    }
protected:
    bool isInBounds(const cv::Mat& m, const cv::Point& p) {
        return cv::Rect(0, 0, m.cols, m.rows).contains(p);
    }
    class VisitedMatrix
    {
        std::vector<std::vector<bool>> visited_;
    public:
        VisitedMatrix(size_t rows, size_t cols): visited_(rows, std::vector<bool>(cols, false)) {}
        bool isVisited(cv::Point const& p) const {
            return visited_[p.y][p.x];
        }
        void setVisited(cv::Point const& p) {
            visited_[p.y][p.x] = true;
        }
        void reset() {
            for (auto& row: visited_) {
                std::fill(row.begin(), row.end(), false);
            }
        }
    };
};
