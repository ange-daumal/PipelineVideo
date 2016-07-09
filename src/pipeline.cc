#include <opencv2/opencv.hpp>


using namespace cv;

Mat takeOneFrame(VideoCapture& cap)
{
  Mat frame;

  if (waitKey(2) != 'q' && cap.isOpened())
      cap.operator >> (frame);

  return frame;
}

int main(void/*int argc, char** argv */)
{
  namedWindow("Video");
  namedWindow("Picture");
  VideoCapture cap(0);

  while (1)
  {
      Mat picture = takeOneFrame(cap);
      imshow("Picture", picture);
  }

  cap.release();
  return 0;
}
