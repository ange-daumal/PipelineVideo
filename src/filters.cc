#include "filters.hh"

int correct(int avg)
{
  if (avg < 0)
    return 0;
  return avg > 255 ? 255 : avg;
}

cv::Mat* convolution(cv::Mat& p, int kernel[])
{
  int div = 0;
  for (int i = 0; i < 9; ++i)
    div += kernel[i];

  printf("div = %d\n", div);
  cv::Mat* res = new cv::Mat(p);

  for (int i = 1; i < p.rows - 1; ++i)
    for (int j = 1; j < p.cols - 1; ++j)
    {
      int red = 0;
      int green = 0;
      int blue = 0;

      for (int x = -1; x < 2; ++x)
        for (int y = -1; y < 2; ++y)
        {
          Vec3b px = p.at<Vec3b>(i + x, j + x);

          red += px[0] * kernel[(1 + x) * 3 + y];
          green += px[1] * kernel[(1 + x) * 3 + y];
          blue += px[2] * kernel[(1 + x) * 3 + y];
        }

        Vec3b avg = Vec3b();
        avg[0] = correct(red);
        avg[1] = correct(green);
        avg[2] = correct(blue);

        (*res).at<Vec3b>(i, j) = (avg);
    }

  return res;
}
