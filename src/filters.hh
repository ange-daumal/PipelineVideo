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

class Filter2 : public tbb::filter
{
  public:
    Filter2()
      : tbb::filter(tbb::filter::parallel) {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      //TODO FIXME
      return (void*) picture;
    }
};

class Filter3 : public tbb::filter
{
  public:
    Filter3()
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
      : tbb::filter(tbb::filter::parallel),
        anchor_(Point(-1, -1)),
        delta_(0),
        ddepth_(-1),
        kernel_(Mat::ones(9, 9, CV_32F ) / 81.0)
    {}

    void* operator()(void* token) override
    {
      Mat* picture = (Mat*) token;
      anchor_ = Point( -1, -1 );
      delta_ = 0;
      ddepth_ = -1;

      filter2D(*picture, *picture, ddepth_, kernel_, anchor_, delta_,
          BORDER_DEFAULT);
      return (void*) picture;
    }

  private:
      Point anchor_;
      double delta_;
      int ddepth_;
      Mat kernel_;
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

#endif /* _FILTERS_HH_ */
