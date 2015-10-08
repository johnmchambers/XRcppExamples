#include <Rcpp.h>
using namespace Rcpp ;
#include "PopCount.h"

namespace module_PopCount_NS {

    std::vector<long> field_size_get(PopCount *obj) { return obj->size; }

    void method_evolve(PopCount *obj , int a1){ return obj->evolve(a1); }

} // module_PopCount_NS

RCPP_MODULE(class_PopCount) {


    class_<PopCount>("PopCount")

    .constructor()
    .constructor<NumericVector,NumericVector>()

    .property("size", &module_PopCount_NS::field_size_get, "read-only field")

    .method("evolve", &module_PopCount_NS::method_evolve)
    .method("table", &PopCount::table)
    ;
}
