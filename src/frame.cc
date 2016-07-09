#include <tbb/tbb.h>
#include <opencv2/opencv.hpp>

#include "pipeline.hh"


int main(void/*int argc, char** argv */)
{
  cv::namedWindow("Picture");

  tbb::pipeline pipeline;
  Filter1 f1;
  Filter2 f2;
  Filter3 f3;
  pipeline.add_filter(f1);
  pipeline.add_filter(f2);
  pipeline.add_filter(f3);

  //tbb::pipeline pipeline = create_pipeline();
  pipeline.run(20);

  return 0;
}
