#include <Rcpp.h>
using namespace Rcpp ;

class PopBD {
  public:
    PopBD(void);
    PopBD(NumericVector initBirth, NumericVector initDeath);

    std::vector<double> birth;
    std::vector<double> death;
    std::vector<long> size;
    std::vector<int> lineage;
    void evolve(int);

};
