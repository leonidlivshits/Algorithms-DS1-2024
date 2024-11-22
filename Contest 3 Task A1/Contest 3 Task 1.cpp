#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

bool isInsideCircle(double x, double y, double cx, double cy, double r) {
  return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}

int main() {
  double cx1, cy1, r1;
  double cx2, cy2, r2;
  double cx3, cy3, r3;

  std::cin >> cx1 >> cy1 >> r1;
  std::cin >> cx2 >> cy2 >> r2;
  std::cin >> cx3 >> cy3 >> r3;

  double xmin = std::min({ cx1 - r1, cx2 - r2, cx3 - r3 });
  double xmax = std::max({ cx1 + r1, cx2 + r2, cx3 + r3 });
  double ymin = std::min({ cy1 - r1, cy2 - r2, cy3 - r3 });
  double ymax = std::max({ cy1 + r1, cy2 + r2, cy3 + r3 });

  int N = 200000;
  int M = 0;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis_x(xmin, xmax);
  std::uniform_real_distribution<> dis_y(ymin, ymax);

  for (int i = 0; i < N; ++i) {
    double x = dis_x(gen);
    double y = dis_y(gen);

    if (isInsideCircle(x, y, cx1, cy1, r1) &&
      isInsideCircle(x, y, cx2, cy2, r2) &&
      isInsideCircle(x, y, cx3, cy3, r3)) {
      M++;
    }
  }


  double Srec = (xmax - xmin) * (ymax - ymin);
  double Se = (double)M / N * Srec;

  std::cout.precision(6);
  std::cout << Se << std::endl;

  return 0;
}

