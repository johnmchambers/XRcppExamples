#include <Rcpp.h>
using namespace Rcpp ;

#include "PopBD.h"

class PopCount: public PopBD {

  public:
    PopCount(void);
    PopCount(NumericVector initBirth, NumericVector initDeath);

    std::vector<long> table();
    
};
