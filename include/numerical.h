#ifndef HS_H
#define HS_H

#include "opt.h"

/* It executes optimization through Batch Gradient Descent */
void GradientDescent(Subgraph *g, double alpha, prtFun EvaluateFun, int FUNCTION_ID, ...);

#endif