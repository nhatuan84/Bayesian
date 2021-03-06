#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "bayesiannetwork.h"
#include "naivebayesian.h"

using namespace std;

int main(int argc, char **argv) {
  int method = 0;
  char *train;
  char *test;
  char *cfg;
  clock_t begin;
  clock_t end;
  double time_spent;
  vector<int> prediction_result;

  if (argc >= 5) {
    method = atoi(argv[4]);
    train = argv[1];
    test = argv[2];
    cfg = argv[3];
  } else if (argc == 4) {
    train = argv[1];
    test = argv[2];
    cfg = argv[3];
    std::cout << " use default naiveBayesian method" << std::endl;
  } else {
    std::cout << " You need to provide training data, test data, and "
                 "configuration for prediction. Please read README"
              << std::endl;
  }
  begin = clock();
  if (method == 0) {
    machinelearning::baysian::NaiveBayesian naive(cfg);
    naive.Train(train);
    prediction_result = naive.Predict(test, 1);
    // Call function to do prediction
    // Pass second argument "1" to denote that we will provide answer/truth for
    // this prediction. Pass second argument "0" to do real prediction.
  } else if (method == 1) {
    machinelearning::baysian::BayesianNetwork bnetwork(cfg);
    bnetwork.Train(train);
    prediction_result = bnetwork.Predict(test, 1);
  }

  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Time spent " << time_spent << " seconds " << std::endl;
  return 0;
}
