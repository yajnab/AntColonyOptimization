#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_CONSTRAINT 20
#define problem

/*
 * Author - Yajnavalkya Bandyopadhyay
 * email- 	yajnab@gmail.com
 * Civil Engineering Student
 * Techno India College of Technology
 */
struct funcinfo{
				double *cns; //Store the values of constraints
				double value; //Value of Objective function
				double *xv; //Equation variables
				int validation; //1 if constraints are satisfied else a 0; A boolean but to support all C it is made integer type.
};

struct funcinfo func(double *x){
 double val; double ctr[20];
  
  /*The Function Goes Here*/
  val= 2*x[0] + 4*x[1]/x[0]; //Function goes here



 /* Normalized constraints g(x)=>0*/
 ctr[0] = x[0]*x[1] - 1;
 ctr[1] = 2*x[0] + x[1];

 int ctr_count = sizeof(ctr)/sizeof(ctr[0]);
 int validation=1;
 for(int i=0;i<ctr_count;i++){
	 if(ctr[i]<0)validation =0;}
		
 struct funcinfo ret;
 ret.cns = ctr;
 ret.value = val;
 ret.xv = x;
 ret.validation = validation;
 return  ret;//Array it
}

void main(){ 
		printf("Enter the number of Variables \t");
		int n;
		scanf("%d",&n);
		printf("%d",n);
		double bound[n][2];
		for(int i=0;i<n;i++){
			printf("Enter the %d th variable lower and upper limit \t",i);
			scanf("%lf %lf",&bound[i][0],&bound[i][1]);
			} 
		srand(time(0));//Randomizing srand time -> 0

		printf("\n Enter Phermone evaporation rate range - 0.1-0.5 \t");
		float phe;
		scanf("%f",&phe); //Phermone Evaporation rate

		struct funcinfo minv;
		int gstr=0;
		
		int maxiter;//Maximum number of iteration
		printf("\n Enter the number of iteration \t");
		scanf("%d",&maxiter);
		int nor;//Number of routes
		printf("\n Enter the number of routes \t");
		scanf("%d",&nor);
		for(int gi=0;gi<maxiter;gi++){
			int str=0;
				
			struct route{
				double value;//Value of the minimized function or the length of the route
				double ph;// Phermone Count
				double *rx;//Array
			}r[nor];// Initialize an array of routes
		
			int cnt =0;
			
			struct mins{
			double value;
			int ps;
			double xval[n];} min;
			
			for(int counter = 0;counter <nor; counter++){//Generate Random Variable, i.e Indivisual Ant
				double tx[n]; //test variables
				//Upper and lower bound Constraint Handling
				for(int i=0;i<n;i++){
					tx[i] = round((bound[i][0] + (double)rand() / (double)((double)RAND_MAX / (bound[i][1] - bound[i][0] + 1) + 1))*10)/10;//For each variable
					//printf("\n %f \n",tx[i]);
					}

					struct funcinfo funcval = func(tx);
					//printf("\n %lf %d",funcval.value, funcval.validation);
					if(funcval.validation==1){ // Checking the condition
						double m1 = funcval.value; // Calculate the route length						
						//printf("\n %lf", m1);
						double m = round(m1*10)/10;
						if(str==0){					
							min.value=m;
							if(gstr==0){minv.value=m;gstr++;}
							min.ps= cnt;
							r[cnt].value=m;
							r[cnt].rx=tx;
							for(int i=0;i<n;i++)
								min.xval[i]=tx[i];
							r[cnt].ph=1;
							//printf("%f \t %f \n", r[min.ps].value, r[min.ps].ph);	
							//printf("%f \t %d \n", min.value, min.ps);	
							cnt++;str++;								
							}
							else{
								int l1=0;
								for(int lc=0;lc<cnt;lc++){
									if(r[lc].value==m){l1++;break;}
									}
								if(l1==0){
									r[cnt].value=m;
									r[cnt].ph=1.0;
									r[cnt].rx=tx;
										//printf("%f \t %d \t %d\n", r[cnt].value, r[cnt].ph, cnt); 
										//printf("%f \t %f \n", r[min.ps].value, r[min.ps].ph); //Debugging Line

									if (r[min.ps].value<r[cnt].value){// If current route is larger than the minimum route
										r[min.ps].ph=r[min.ps].ph*(1-phe)+1;
									//printf("%f dingdong %f\n", min.value, r[min.ps].ph); //Debugging Line
									}
									if (r[min.ps].value>r[cnt].value){// If current route is smaller than the minimum route
										r[cnt].ph=r[min.ps].ph*(1-phe)+1;
										r[min.ps].ph=1;
										min.ps=cnt;
										for(int i=0;i<n;i++)
											min.xval[i]=r[min.ps].rx[i];										
										min.value=r[cnt].value;
										//printf("%f \n %d %f", min.value, min.ps, r[min.ps].ph); //Debugging Line
									}
									
									cnt++;
								}
								
						}
					}for(int i=0;i<n;i++){
							printf("\n Variables %dth variable %f",i, r[min.ps].rx[i]);
						}
					
					}
					if(minv.value>min.value){
						minv.xv = min.xval;
						for(int i=0;i<n;i++){
				printf("\n %dth variable %f",i, minv.xv[i]);
				}
						minv.value=min.value;
				}
			printf("\n Minimum Value %f", minv.value);
		}printf("\n Smallest value%f", minv.value);
}
							
		
