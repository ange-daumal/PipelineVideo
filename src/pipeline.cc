#include <opencv2/opencv.hpp>
#include <tbb/pipeline.h>

#include "pipeline.hh"

Mat takeOneFrame(VideoCapture& cap)
{
  Mat frame;
  if (waitKey(2) != 'q' && cap.isOpened())
      cap.operator >> (frame);
  return frame;
}
