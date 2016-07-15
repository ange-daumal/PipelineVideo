#include <tbb/tbb.h>
#include <opencv2/opencv.hpp>
#include <chrono>

#include "pipeline.hh"
#include "filters.hh"

using htp = std::chrono::high_resolution_clock::time_point;
using hn = std::chrono::high_resolution_clock;
using namespace std::chrono;

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

  htp t1 = hn::now();
  //serial version
  htp t2 = hn::now();

  htp t3 = hn::now();
  //parallel version
  htp t4 = hn::now();

  auto s_time = duration_cast<milliseconds>(t2-t1).count();
  auto p_time = duration_cast<milliseconds>(t4-t3).count();

  pipeline.add_filter(init);
  //pipeline.add_filter(emboss);
  //pipeline.add_filter(detect);
  //pipeline.add_filter(strengthen);
  //pipeline.add_filter(contrast);
  pipeline.add_filter(blurr);
  pipeline.add_filter(term);

  pipeline.run(3);

  printf("Over\n");

  return 0;
}
