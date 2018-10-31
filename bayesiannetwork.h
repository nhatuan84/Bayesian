#ifndef BAYESIANNETWORK_H_
#define BAYESIANNETWORK_H_

#include "bayesian.h"

namespace baysian {

class BayesianNetwork : public Bayesian {
 public:
  BayesianNetwork(char *);
  ~BayesianNetwork();
  // initialize all the information we need from training data
  void Predict(char *);
  // calculate the probability of each choice and choose the greatest one as our
  // prediction
  void Train(char *);

 private:
  long double ***conditional_probability_table_;
  int **nodes_parents_;
};

template <class Type>
struct data {
  double key;
  Type value1;
  Type value2;
};

}  // namespace baysian

#endif