#include <tbb/tbb.h>
#include <opencv2/opencv.hpp>

#include "pipeline.hh"
#include "filters.hh"

int main(void/*int argc, char** argv */)
{
  cv::namedWindow("Picture");
  tbb::pipeline pipeline;

  Initializer init;
  Blurr blurr;
  Contrast contrast;
  StrengthenEdge strengthen;
  DetectEdge detect;
  Emboss emboss;
  Terminator term;

  pipeline.add_filter(init);
  pipeline.add_filter(emboss);
  //pipeline.add_filter(detect);
  //pipeline.add_filter(strengthen);
  //pipeline.add_filter(contrast);
  //pipeline.add_filter(blurr);
  pipeline.add_filter(term);

  pipeline.run(3);

  printf("Over\n");

  return 0;
}
