#include <Rcpp.h>
using namespace Rcpp ;

#include "PopCount.h"

PopCount::PopCount () {

}

PopCount::PopCount(NumericVector initBirth, NumericVector initDeath) : 
    PopBD(initBirth, initDeath) {


}

std::vector<long> PopCount::table() {

    std::vector<long> count = std::vector<long>(birth.size());

    for(int i = 0; i < lineage.size(); i++)
	count[lineage[i]]++;

    return count;

}
