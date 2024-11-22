#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <fstream>

bool isInsideCircle(double x, double y, double cx, double cy, double r) {
  return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}

double monteCarloArea(double xmin, double xmax, double ymin, double ymax, int N,
  double cx1, double cy1, double r1,
  double cx2, double cy2, double r2,
  double cx3, double cy3, double r3) {
  int M = 0;
  std::srand(std::time(0));

  for (int i = 0; i < N; ++i) {
    double x = xmin + (xmax - xmin) * (std::rand() / (double)RAND_MAX);
    double y = ymin + (ymax - ymin) * (std::rand() / (double)RAND_MAX);

    if (isInsideCircle(x, y, cx1, cy1, r1) &&
      isInsideCircle(x, y, cx2, cy2, r2) &&
      isInsideCircle(x, y, cx3, cy3, r3)) {
      M++;
    }
  }

  double Srec = (xmax - xmin) * (ymax - ymin);

  return (double)M / N * Srec;
}

int main() {
  std::ofstream outFile("results.txt");

  double cx1 = 1.0, cy1 = 1.0, r1 = 1.0;
  double cx2 = 1.5, cy2 = 2.0, r2 = std::sqrt(5) / 2;
  double cx3 = 2.0, cy3 = 1.5, r3 = std::sqrt(5) / 2;

  double theoreticalArea = 0.25 * std::acos(-1.0) + 1.25 * std::asin(0.8) - 1;

  int N_start = 100;
  int N_end = 100000;
  int N_step = 500;

  std::vector<std::pair<double, double>> bounds = {
      {0.0, 3.0},
      {0.7, 2.1}
  };

  outFile << "N\tScale\tApproxArea\tError\n";
  std::cout << std::fixed << std::setprecision(6);
  std::cout << "N\tScale\tApproxArea\tError\n";

  for (const auto& bound : bounds) {
    double xmin = bound.first, xmax = bound.second;
    double ymin = bound.first, ymax = bound.second;

    for (int N = N_start; N <= N_end; N += N_step) {
      double approxArea = monteCarloArea(xmin, xmax, ymin, ymax, N,
        cx1, cy1, r1,
        cx2, cy2, r2,
        cx3, cy3, r3);

      double error = std::abs(approxArea - theoreticalArea);
      outFile << N << "\t" << (xmax - xmin) << "x" << (ymax - ymin) << "\t"
        << approxArea << "\t" << error << "\n";
      std::cout << N << "\t" << (xmax - xmin) << "x" << (ymax - ymin) << "\t"
        << approxArea << "\t" << error << "\n";
    }
  }
  outFile.close();
  return 0;
}

