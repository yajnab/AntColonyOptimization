#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
 * Author - Yajnavalkya Bandyopadhyay
 * email- 	yajnab@gmail.com
 * Civil Engineering Student
 * Techno India College of Technology
 */


double f(double p, double q, double r, double s){
 return (3*p*q*q*s + 2*p*q + 3*s*q + 4*s*p*r)/(2*p*r+3*q*r+4*q*s+1);
 }
void main(){ 
		int xM =2, xN = 5;
		int yM =3, yN = 10;
		int zM =2, zN = 5;
		int pM =2, pN = 18;
		srand(time(0));//Randomizing srand time -> 0
		
		int phe = 0.22154; //Phermone Evaporation rate
		
		struct minimum{
				double value;
				double p,q,r,s;
				} minv;
		int gstr=0;
		
		
		for(int gi=0;gi<5000;gi++){
			int str=0;
		
		//double s[5];s[0]=0;s[1]=0;s[2]=0;s[3]=0;s[4]=0;
			struct route{
				double value;//Value of the minimized function or the length of the route
				double ph;// Phermone Count
				double p,q,r,s;
			}r[10000];// Initialize an array of routes
		
			int cnt =0;
			
			struct mins{
			double value;
			int ps;} min;
			
			for(int counter = 0;counter <10000; counter++){
			//Generate Random Variable, i.e Indivisual Ant
				double i = round((xM + (double)rand() / (double)((double)RAND_MAX / (xN - xM + 1) + 1))*10)/10;//For p
				double j = round((yM + (double)rand() / (double)((double)RAND_MAX / (yN - yM + 1) + 1))*10)/10;//For q
				double k = round((zM + (double)rand() / (double)((double)RAND_MAX / (zN - zM + 1) + 1))*10)/10;//For r
				double l = round((pM + (double)rand() / (double)((double)RAND_MAX / (pN - pM + 1) + 1))*10)/10;//For s
				//printf("\n %f %f %f \n", i, j, k);
					if((abs(i*j*l +j*j*l +i*k) ==69)&& (abs(i*j+i*k+j*l==37))){ // Checking the condition
						double m1 = f(i,j,k,l); // Calculate the route length
						double m = round(m1*10)/10;
						if(str==0){					
							min.value=m;
							if(gstr==0){minv.value=m;gstr++;}
							min.ps= cnt;
							r[cnt].value=m;
							r[cnt].p=i;
							r[cnt].q=j;
							r[cnt].r=k;
							r[cnt].s=l;
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
									r[cnt].p=i;
									r[cnt].q=j;
									r[cnt].r=k;
									r[cnt].s=l;
					
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
					minv.p=r[min.ps].p;
					minv.q=r[min.ps].q;
					minv.r=r[min.ps].r;
					minv.s=r[min.ps].s;
					
				}
			printf("%f %f %f %f %f %f\n", min.value,r[min.ps].p,r[min.ps].q,r[min.ps].r,r[min.ps].s,  r[min.ps].ph);
		}printf("\n %f %f %f %f %f \n", minv.value, minv.p, minv.q, minv.r, minv.s);
		//printf("%f \n", ((double)minv/100));
		}
							
		
