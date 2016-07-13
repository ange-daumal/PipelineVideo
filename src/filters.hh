/* filters.hh: Filters definitions */
#ifndef _FILTERS_HH_
#define _FILTERS_HH_

#include <opencv2/opencv.hpp>
#include <tbb/tbb.h>

using namespace cv;

cv::Mat* convolution(Mat& p, int kernel[]);

class Filter1 : public tbb::filter
{
  public:
    Filter1()
      : tbb::filter(tbb::filter::parallel) {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      //TODO FIXME
      return (void*) picture;
    }
};

class Blurr : public tbb::filter
{
  public:
    Blurr()
      : tbb::filter(tbb::filter::parallel)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      int kernel[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
      Mat* res = convolution(*picture, kernel);
      delete picture;
      return (void*) res;
    }

};

class Contrast : public tbb::filter
{
  public:
    Contrast()
      : tbb::filter(tbb::filter::parallel)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      int kernel[] = { 0, -1, 0, -1, 5, -1, 0, -1, 0 };
      Mat* res = convolution(*picture, kernel);
      delete picture;
      return (void*) res;
    }
};

class StrengthenEdge : public tbb::filter
{
  public:
    StrengthenEdge()
      : tbb::filter(tbb::filter::parallel)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      int kernel[] = { 0, 0, 0, -1, 1, 0, 0, 0, 0 };
      Mat* res = convolution(*picture, kernel);
      delete picture;
      return (void*) res;
    }
};

class DetectEdge : public tbb::filter
{
  public:
    DetectEdge()
      : tbb::filter(tbb::filter::parallel)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      int kernel[] = { 0, 1, 0, 1, -4, 1, 0, 1, 0 };
      Mat* res = convolution(*picture, kernel);
      delete picture;
      return (void*) res;
    }
};


class Emboss : public tbb::filter
{
  public:
    Emboss()
      : tbb::filter(tbb::filter::parallel)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      int kernel[] = { -2, -1, 0, -1, 1, 1, 0, 1, 2 };
      Mat* res = convolution(*picture, kernel);
      delete picture;
      return (void*) res;
    }
};
#endif /* _FILTERS_HH_ */
