#include <R.h>
#include <Rinternals.h>

SEXP pointer_string(SEXP object) {
    char buffer[21];
    snprintf(buffer, 21, "<%p>", (void *) object);
    return mkString(buffer);
}
