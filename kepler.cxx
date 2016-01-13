#include <iostream>
#include <cmath>

using namespace std;

 struct two_body{
    double p[2],q[2];
  };

  void initial_values(two_body * a, double & H );

int main(){
  
  double H;
  const double dt=0.0005;
  const double tEnd=20*M_PI;
  two_body a;
  initial_values(& a, H );

  cout<<'0'<<'\t'<<H<<'\t'<<a.p[0]<<'\t'<<a.p[1]<<'\t'<<a.q[0]<<'\t'<<a.q[1]<<endl;
  
  for(double t=dt; t<tEnd; t+=dt){
   double qsum=pow((a.q[0]*a.q[0]+a.q[1]*a.q[1]),-3.0/2.0);
    
    for(int i=0;  i<2; i++){
      
      a.p[i]-= dt * a.q[i]* qsum;
      a.q[i]+= dt * a.p[i];
      
    }
  
     H=(1.0/2.0)*(a.p[0]*a.p[0]+a.p[1]*a.p[1]-1.0/sqrt(a.q[0]*a.q[0]+a.q[1]*a.q[1]));
    
    cout<<t<<'\t'<<H<<'\t'<<a.p[0]<<'\t'<<a.p[1]<<'\t'<<a.q[0]<<'\t'<<a.q[1]<<endl;
    
  }
    
return 0;  
}

void initial_values (two_body * a, double & H ){
  
   const double e=0.6;
  H=-1.0/2.0;
  
 a-> q[0]=1.0 - e;
 a-> q[1]=0.0;
 a-> p[0]=0.0;
 a-> p[1]=sqrt((1.0 + e)/(1.0 - e));
  
}