/* pipeline.hh: Generate pipeline */
#ifndef _PIPELINE_HH_
#define _PIPELINE_HH_

using namespace cv;

tbb::pipeline create_pipeline(void);
Mat takeOneFrame(VideoCapture& cap);

class Filter1 : public tbb::filter
{
  public:
    Filter1()
  : tbb::filter(tbb::filter::serial_in_order),
    cap_(0)
  {}

    ~Filter1()
  {
      cap_.release();
  }

  // Generate tokens
  void* operator()(void*) override
  {
      Mat* picture = new Mat(takeOneFrame(cap_));
      return (void*) picture;
  }

  private:
    VideoCapture cap_;
};

class Filter2 : public tbb::filter
{
  public:
    Filter2()
  : tbb::filter(tbb::filter::parallel) {}

  // Process and output tokens
  void* operator()(void* token) override
  {
      Mat* picture = (Mat*) token;
      return (void*) picture;
  }
};

class Filter3 : public tbb::filter
{
  public:
    Filter3()
  : tbb::filter(tbb::filter::serial_in_order) {}

  // Process tokens
  void* operator()(void* token) override
  {
      Mat* picture = (Mat*) token;
      imshow("Picture", *picture);
      delete picture;
      return nullptr;
  }
};

#endif /* _PIPELINE_HH_ */
