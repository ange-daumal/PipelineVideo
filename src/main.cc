#include <tbb/tbb.h>
#include <opencv2/opencv.hpp>
#include <chrono>

#include "boost/program_options.hpp"
#include "pipeline.hh"
#include "filters.hh"

using htp = std::chrono::high_resolution_clock::time_point;
using hn = std::chrono::high_resolution_clock;
using namespace std::chrono;

// Program options
tbb::pipeline load_options(int argc, char** argv) {
  boost::program_options::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("blurr", "use blurr filter")
    ("contrast", "use contrast filter")
    ("strengthen", "strengthen edges")
    ("detect", "use edge detection filter")
    ("emboss", "use emboss filter")
    ;

  boost::program_options::variables_map vm;
  boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
  boost::program_options::notify(vm);

  if (vm.count("help")) {
    std::cout << desc << "\n";
    exit(1);
  }

  cv::namedWindow("Picture");
  tbb::pipeline pipeline;

  Initializer init;
  pipeline.add_filter(init);

  if (vm.count("blurr")) {
    Blurr blurr;
    pipeline.add_filter(blurr);
  }

  if (vm.count("contrast")) {
    Contrast contrast;
    pipeline.add_filter(contrast);
  }

  if (vm.count("strengthen")) {
    StrengthenEdge strengthen;
    pipeline.add_filter(strengthen);
  }

  if (vm.count("detect")) {
    DetectEdge detect;
    pipeline.add_filter(detect);
  }

  if (vm.count("emboss")) {
    Emboss emboss;
    pipeline.add_filter(emboss);
  }

  Terminator term;
  pipeline.add_filter(term);

  return pipeline;
}

int main(int argc, char** argv)
{
  auto pipeline = load_options(argc, argv);

  htp t1 = hn::now();
  //serial version
  htp t2 = hn::now();

  htp t3 = hn::now();
  //parallel version
  htp t4 = hn::now();

  auto s_time = duration_cast<milliseconds>(t2-t1).count();
  auto p_time = duration_cast<milliseconds>(t4-t3).count();

  pipeline.run(3);

  return 0;
}
