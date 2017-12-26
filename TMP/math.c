#include <stdio.h>
#include <math.h>
#define RAND_MAX 077777


double pow(double base, double exponent){
	if(exponent < 0){
		return pow((1/base), exponent);
	}
	
	int i;

	double ans = 1;
	for(i = 1;i <= exponent; i++){
		ans = base * ans;
	}

	return ans;
}



double log(double x){
//	printf("LOL\n");
	double ans = 0;
        double numerator = -1.0;
        int i;
        for(i = 1;i <= 20;i++){
                numerator = (-1.0) * numerator * (x - 1);
                ans = ans + (numerator / i);
        }

//	printf("ans = %f\n", ans);
        return ans;
}


double expdev(double lambda){
	double dummy;
	do{
		dummy = (double)rand() / RAND_MAX;
	}while(dummy == 0.0);
	
	return -1 *(log(dummy) / lambda);
}

/*
int main(){
	double x = log(2);
	printf("%f\n", x);
	x = log(4);
	printf("%f\n", x);
	x = log(10);
	printf("%f\n", x);
	x = log(20);
	printf("%f\n", x);
	
	x = pow(10, -5);
	printf("%f\n", x);
	return 0;
}*/
