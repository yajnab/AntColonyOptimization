#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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
				double *x; //Equation variables
				int validation; //1 if constraints are satisfied else a 0; A boolean but to support all C it is made integer type.
}
#ifdef problem
struct funcinfo func(double *x){
 return 0; //Array it
 }
#endif
void main(){ 
		printf("Enter the number of Variables");
		int n = scanf("%d",&n);
		int bound[n][2];
		for(int i=0;i<n;i++){
			printf("Enter the %d th variable lower and upper limit");
			scanf("%f %f",&bound[i][0],&bound[i][1]);} 
		srand(time(0));//Randomizing srand time -> 0
		
		System.out.printf("Enter Phermone evaporation rate range - 0.1-0.5")
		int phe;
		scanf("%f",phe); //Phermone Evaporation rate
		
		struct funcinfo minv;
		int gstr=0;
		
		int maxiter;//Maximum number of iteration
		printf("Enter the number of iteration")
		scanf("%d",&maxiter);
		int nor;//Number of routes
		printf("Enter the number of routes");
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
			int ps;} min;
			
			for(int counter = 0;counter <nor; counter++){//Generate Random Variable, i.e Indivisual Ant
				int *tx; //test variables
				//Upper and lower bound Constraint Handling
				for(int i=0;i<n;i++)
					double tx[i] = round((bound[i] + (double)rand() / (double)((double)RAND_MAX / (bound[i][1] - bound[i][0] + 1) + 1))*10)/10;//For each variable
			
				//printf("\n %f %f %f \n", i, j, k);
					if(func(*tx).validation){ // Checking the condition
						double m1 = func(*tx).value; // Calculate the route length
						double m = round(m1*10)/10;
						if(str==0){					
							min.value=m;
							if(gstr==0){minv.value=m;gstr++;}
							min.ps= cnt;
							r[cnt].value=m;
							r[cnt].rx=tx;
							r[cnt].ph=1;
							//printf("%f \t %f \n", r[min.ps].value, r[min.ps].ph);	
							//printf("%f \t %d \n", min.value, min.ps);	
							cnt++;str++;								
							}
					
											//s[0]=m;s[1]=i;s[2]=j;s[3]=k;s[4]=l;str++;}//Initialize Phermone
						else{
								int l1=0;
								for(int lc=0;lc<cnt;lc++){
									if(r[lc].value==m){l1++;break;}
									}
								if(l1==0){
									r[cnt].value=m;
									r[cnt].ph=1.0;
									r[cnt].rx=tx;
					
										/*printf("%f \t %d \t %d\n", r[cnt].value, r[cnt].ph, cnt); 
										*printf("%f \t %d \n", r[min.ps].value, r[min.ps].ph);*/ //Debugging Line
							
							
									if (r[min.ps].value<r[cnt].value){// If current route is larger than the minimum route
										r[min.ps].ph=r[min.ps].ph*(1-phe)+1;
									//printf("%f dingdong %d\n", min.value, r[min.ps].ph); //Debugging Line
									}
									/*if (r[min.ps].value==r[cnt].value){// If current route is Equal than the minimum route though this is never going to happen due to exception handling already done above
										r[min.ps].ph+=1;
										//printf("%f dingdong2 %d\n", min.value, r[min.ps].ph); //Debugging Line
									}*/
									if (r[min.ps].value>r[cnt].value){// If current route is smaller than the minimum route
										r[cnt].ph=r[min.ps].ph*(1-phe)+1;
										r[min.ps].ph=1;
										min.ps=cnt;
										min.value=r[cnt].value;
										//printf("%f \n %d", min.value, r[min.ps].ph); //Debugging Line
									}
									cnt++;
						//s[0]=m;s[1]=i;s[2]=j;s[3]=k;s[4]=l;
						//printf (" \n Found here %f %f %f %f %f\n", s[0],s[1],s[2], s[3], s[4]);}
								}
						}
					}
					}
			if(minv.value>min.value){
					minv.value=min.value;
					minv.x=r[min.ps].rx;					
				}
			//printf("%f %f %f %f %f %f\n", min.value,r[min.ps].p,r[min.ps].q,r[min.ps].r,r[min.ps].s,  r[min.ps].ph);
		}//printf("\n %f %f %f %f %f \n", minv.value, minv.p, minv.q, minv.r, minv.s);
		//printf("%f \n", ((double)minv/100));
		}
							
		
