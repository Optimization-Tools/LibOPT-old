#include "numerical.h"

/* It executes optimization through Batch Gradient Descent
Parameters: [X, Y, alpha, ...]
X: dataset
Y: target values
alpha: learning rate
EvaluateFun: function to be optimized
FUNCTION_ID: identifier of the function to be optimized
remaining parameters of the function to be optimized */
void GradientDescent(gsl_matrix *X, gsl_vector *Y, double alpha, int FUNCTION_ID, ...){
    va_list arg;
    gsl_vector *w = NULL, *w_tmp = NULL;
    double error = 0.0, old_error = DBL_MAX, tmp;
    int i, j;
		
    va_start(arg, FUNCTION_ID);
	w = va_arg(arg, gsl_vector *);
    w_tmp = gsl_vector_calloc(w->size);
	
	if(X && Y && w){
    
		switch (FUNCTION_ID){
			case 7: /* Linear Regression*/
				w = va_arg(arg, gsl_vector *);
				while(abs(error-old_error) > 0.00001){
					old_error = error;
				
					for(j = 0; j < X->size2; j++){
						tmp = alpha*(1/(double)X->size1); // tmp = alpha*1/m
						tmp+=Linear_RegressionPartialDerivative(X, w, Y, j); //tmp = alpha*1/m*sum(h(x_i)-y_i)x_i^j
						gsl_vector_set(w_tmp, j, tmp);
					}
					
					gsl_mem_cpy(w, w_tmp);
					error = Linear_Regression(X, w, Y);
				}               
			break;
		}
	}else fprintf(stderr,"\n.There is no X and/or Y and/or w allocated @GradientDescent\n");
    
    va_end(arg);
    gsl_vector_free(w_tmp);
}
