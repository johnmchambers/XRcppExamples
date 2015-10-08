#include <Rcpp.h>
using namespace Rcpp ;
typedef std::vector<double> vec; //convenience typedef
#include "PopBD.h"

PopBD::PopBD () {

}

PopBD::PopBD(NumericVector initBirth, NumericVector initDeath) {

    birth = vec(initBirth.size());
    death = vec(initDeath.size());
    lineage = std::vector<int>(initBirth.size());
    for(int i = 0; i < birth.size(); i++) {
	birth[i] = initBirth[i];
	death[i] = initDeath[i];
	lineage[i] = i;
    }
    size = std::vector<long>(1); size[0] = birth.size();
    
}

void PopBD::evolve(int nstep = 1) {
    // get some probabilities
    RNGScope();

    for(int step = 0; step < nstep; step++) {

    int n = lineage.size(), i;
    NumericVector unifs = runif(2*n);

    // kill some off
    int bodies = 0;
    for(i = 0; i < n; i++)
	if(unifs[i] <= death[lineage[i]]) {
	    lineage[i] = -1;
	    bodies++;
	}

    // get rid of the bodies
    if(bodies) {
	int to=0;
	for(int from = 0; from < n; from++)
	    if(lineage[from] >= 0) { // still alive
		lineage[to] = lineage[from];
		to++;
	    }
	n -= bodies;
	lineage.resize(n, 0);
    }

    // look for births, using the rest of the probabilities
    for(int j = 0; j < n; j++, i++)
	if(unifs[i] <= birth[lineage[j]])
	    lineage.push_back(lineage[j]);
    // append the new population size
    size.push_back(lineage.size());
    }

}
