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
  for (int c = 0; c < p.channels(); ++c)
    for (int i = 1; i < p.rows - 1; ++i)
      for (int j = 1; j < p.cols - 1; ++j)
      {
        int avg = p.at<unsigned char>(i - 1, j - 1, c) * kernel[0] +
          p.at<unsigned char>(i - 1, j, c) * kernel[1] +
          p.at<unsigned char>(i - 1, j + 1, c) * kernel[2] +
          p.at<unsigned char>(i, j - 1, c) * kernel[3] +
          p.at<unsigned char>(i, j, c) * kernel[4] +
          p.at<unsigned char>(i, j + 1, c) * kernel[5] +
          p.at<unsigned char>(i + 1, j - 1, c) * kernel[6] +
          p.at<unsigned char>(i + 1, j, c) * kernel[7] +
          p.at<unsigned char>(i + 1, j + 1, c) * kernel[8];

        (*res).at<unsigned char>(i, j, c) = correct(avg);
      }
  return res;
}
