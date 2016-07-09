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

tbb::pipeline create_pipeline()
{
  tbb::pipeline ThreeStage;
  Filter1 f1;
  Filter2 f2;
  Filter3 f3;
  ThreeStage.add_filter(f1);
  ThreeStage.add_filter(f2);
  ThreeStage.add_filter(f3);
  return ThreeStage;
}

