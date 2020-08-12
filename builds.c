#include<stdio.h>
#include<math.h>
#define PI 3.1415926

float convert_deg(float degree)
{
	float radian = degree * (PI / 180.0);
	return radian;
}

void main()
{
	float arr_x[8] = {4, 4, 7, 7, 0.4, 0.4, 2.5, 2.5};
	float arr_y[8] = {0, -5, -5, 0, -2, -5, -5, -2};
	float sun_x = -3.5;
	float sun_y = 1;
	double dist_sun_small_a = sqrt((arr_x[7]-sun_x)*(arr_x[7]-sun_x)+(arr_y[7]-sun_y)*(arr_y[7]-sun_y));
	double dist_sun_small_b = sqrt((arr_y[7]-sun_y)*(arr_y[7]-sun_y));
	double dist_sun_small_c = sqrt((sun_x-arr_x[7])*(sun_x-arr_x[7]));
	float angle_upper_a = asin((dist_sun_small_b / dist_sun_small_a));
	float angle_a = convert_deg(90);
	float angle_b = asin((dist_sun_small_b / dist_sun_small_a));
	float angle_c = convert_deg(180) - angle_a - angle_b;
	float side_c = sqrt((arr_x[6]-arr_x[1])*(arr_x[6]-arr_x[1])+(arr_y[6]-arr_y[1])*(arr_y[6]-arr_y[1]));
	float side_a = (side_c*sin(angle_a))/sin(angle_c);
	float side_b = (side_c*sin(angle_b))/sin(angle_c);
	float small_dist = sqrt((arr_x[5]-arr_x[4])*(arr_x[5]-arr_x[4])+(arr_y[5]-arr_y[4])*(arr_y[5]-arr_y[4]));
	float big_dist = sqrt((arr_x[0]-arr_x[1])*(arr_x[0]-arr_x[1])+(arr_y[0]-arr_y[1])*(arr_y[0]-arr_y[1]))-(small_dist-side_b);	
	float upper_small = sqrt((arr_x[4]-arr_x[7])*(arr_x[4]-arr_x[7])+(arr_y[4]-arr_y[7])*(arr_y[4]-arr_y[7]));
	float upper_big = sqrt((arr_x[0]-arr_x[3])*(arr_x[0]-arr_x[3])+(arr_y[0]-arr_y[3])*(arr_y[0]-arr_y[3]));
	float total = small_dist + big_dist + upper_small + upper_big;
	printf("Total : %f", total);
}