#include <Rcpp.h>
using namespace Rcpp ;
#include "PopBD.h"

RCPP_MODULE(class_PopBD) {


    class_<PopBD>("PopBD")

    .constructor()
    .constructor<NumericVector,NumericVector>()

    .field_readonly("lineage", &PopBD::lineage)
    .field_readonly("size", &PopBD::size)

    .method("evolve", &PopBD::evolve)
    ;
}
