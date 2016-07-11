#include "filters.hh"

int correct(int avg)
{
  if (avg < 0)
    return 0;
  return avg > 255 ? 255 : avg;
}

cv::Mat* convolution(cv::Mat& p, int kernel[])
{
  //  cv::Mat* res = new cv::Mat(p.rows, p.cols, p.type());
  cv::Mat* res = new cv::Mat(p);
  for (int i = 1; i < p.rows - 1; ++i)
    for (int j = 1; j < p.cols - 1; ++j)
    {
      Vec3b avg = p.at<Vec3b>(i - 1, j - 1) * kernel[0] +
        p.at<Vec3b>(i - 1, j) * kernel[1] +
        p.at<Vec3b>(i - 1, j + 1) * kernel[2] +
        p.at<Vec3b>(i, j - 1) * kernel[3] +
        p.at<Vec3b>(i, j) * kernel[4] +
        p.at<Vec3b>(i, j + 1) * kernel[5] +
        p.at<Vec3b>(i + 1, j - 1) * kernel[6] +
        p.at<Vec3b>(i + 1, j) * kernel[7] +
        p.at<Vec3b>(i + 1, j + 1) * kernel[8];

      //Vec3b pix = Vec3b(p.at<Vec3b>(x + x_conv, y + y_conv));
      (*res).at<Vec3b>(i, j) = avg;
    }
  return res;
}
