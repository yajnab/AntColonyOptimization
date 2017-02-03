/*
 * Author - Yajnavalkya Bandyopadhyay
 * email- 	yajnab@gmail.com
 * Civil Engineering Student
 * Techno India College of Technology
 */

#define problem

#ifdef problem
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
 ret = (struct funcinfo){ ctr, val, x, validation };
 return  ret;//Array it
}
#endif
