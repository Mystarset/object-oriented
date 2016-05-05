 /************************************************************ 
  FileName: calculation 

  Author: Starset        Version :  1.1        Date:  2016.5.6

  Description:      
  
               输入r,计算圆的面积并输出。 

  Function List:
            

*************************************************************/ 
#ifndef CALCULATION_H
#define CALCULATION_H

#include <cmath> 

#define Pi 3.14

class calculation
{	 
	public:
		calculation();
		~calculation();
	    double calarea(double r);
	protected:
};

#endif
