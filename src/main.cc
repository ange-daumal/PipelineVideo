#include <tbb/tbb.h>
#include <opencv2/opencv.hpp>

#include "pipeline.hh"
#include "filters.hh"

int main(void/*int argc, char** argv */)
{
  cv::namedWindow("Picture");

  tbb::pipeline pipeline;
  Initializer init;

  Filter1 f1;
  Filter2 f2;
  Filter3 f3;
  Blurr blurr;
  Contrast contrast;
  Terminator term;

  pipeline.add_filter(init);
  pipeline.add_filter(f1);
  pipeline.add_filter(f2);
  pipeline.add_filter(f3);
  pipeline.add_filter(contrast);
  //pipeline.add_filter(blurr);
  pipeline.add_filter(term);

  pipeline.run(20);

  return 0;
}
