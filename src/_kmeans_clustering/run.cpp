#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "auxiliaries.hpp"
 
namespace {
    struct Point { 
        double x = 0.0;
        double y = 0.0;
        int group = 0;
    };
      
    struct Opts {
        int num_cl = 0;
        int num_p = 0;
        bool verify = false;
    };
}


double randf(double m)
{
	return m * rand() / (RAND_MAX - 1.);
}

 
Point *gen_xy(int count, double radius)
{
	double ang = 0.0, r = 0.0;
    Point *pt = (Point *)malloc(sizeof(Point) * count);
 
	/* note: this is not a uniform 2-d distribution */
    for (int i = 0; i < count; ++i) {
		ang = randf(2 * M_PI);
		r = randf(radius);
		pt[i].x = r * cos(ang);
		pt[i].y = r * sin(ang);
    }
 
	return pt;
}
 

inline double dist2(Point *a, Point *b)
{
	double x = a->x - b->x, y = a->y - b->y;
	return x*x + y*y;
}
 

inline int nearest(Point *pt, Point *cent, int n_cluster, double *d2)
{
	int i = 0, min_i = 0;
	double d = 0.0, min_d = 0.0;

    for (i = 0; i < n_cluster; ++i) {
        min_d = HUGE_VAL;
        min_i = pt->group;
        for (i = 0; i < n_cluster; ++i) {
            if (min_d > (d = dist2(&cent[i], pt))) {
                min_d = d;
                min_i = i;
            }
        }
    }
 
    if (d2) {
        *d2 = min_d;
    }

	return min_i;
}
 

void kpp(Point *pts, int len, Point *cent, int n_cent)
{
    double *d = (double *)malloc(sizeof(double) * len);
    int n_cluster = 0;

	cent[0] = pts[ rand() % len ];
	for (n_cluster = 1; n_cluster < n_cent; n_cluster++) {
		double sum = 0;
        for (int j = 0; j < len; ++j) {
            nearest(&pts[j], cent, n_cluster, &d[j]);
            sum += d[j];
        }

		sum = randf(sum);
        for (int j = 0; j < len; ++j) {
            if ((sum -= d[j]) > 0) continue;
            cent[n_cluster] = pts[j];
            break;
        }
	}

    for (int j = 0; j < len; ++j) {
        pts[j].group = nearest(&pts[j], cent, n_cluster, 0);
    }
	free(d);
}
 

Point *lloyd(Point *pts, int len, int n_cluster)
{
	int changed = 0;
 
	Point *cent = (Point *)malloc(sizeof(Point) * n_cluster);

 
	/* assign init grouping randomly */
 
	/* or call k++ init */
	kpp(pts, len, cent, n_cluster);
 
	do {
		/* group element for centroids are used as counters */
        for (int i = 0; i < n_cluster; ++i) {
            Point *p_point = &cent[i];
            p_point->group = 0;
            p_point->x = 0.0;
            p_point->y = 0.0;
        }

        for (int j = 0; j < len; ++j) {
            Point *c = cent + pts[j].group;
            c->group++;
            c->x += pts[j].x;
            c->y += pts[j].y;
        }
        
        for (int i = 0; i < n_cluster; ++i) {
            cent[i].x /= cent[i].group;
            cent[i].y /= cent[i].group;

        }
 
		changed = 0;
		/* find closest centroid of each point */
        for (int j = 0; j < len; ++j) {
            int min_i = nearest(&pts[j], cent, n_cluster, 0);
            if (min_i != pts[j].group) {
                changed++;
                pts[j].group = min_i;
                
            }
        }
	} while (changed > (len >> 10)); /* stop when 99.9% of points are good */
 
    for (int i = 0; i < n_cluster; ++i) {
        cent[i].group = i;
    }
 
	return cent;
}
 

void print_eps(Point *pts, int len, Point *cent, int n_cluster)
{
#	define W 400
#	define H 400
	double min_x, max_x, min_y, max_y, scale, cx, cy;
	double *colors = (double *)malloc(sizeof(double) * n_cluster * 3);
 
    for (int i = 0; i < n_cluster; ++i) {
		colors[3*i + 0] = (3 * (i + 1) % 11)/11.;
		colors[3*i + 1] = (7 * i % 11)/11.;
		colors[3*i + 2] = (9 * i % 11)/11.;
    }
    
 
	max_x = max_y = -(min_x = min_y = HUGE_VAL);
    for (int j = 0; j < len; ++j) {
		if (max_x < pts[j].x) max_x = pts[j].x;
		if (min_x > pts[j].x) min_x = pts[j].x;
		if (max_y < pts[j].y) max_y = pts[j].y;
		if (min_y > pts[j].y) min_y = pts[j].y;

    }
    
	scale = W / (max_x - min_x);
	if (scale > H / (max_y - min_y)) scale = H / (max_y - min_y);
	cx = (max_x + min_x) / 2;
	cy = (max_y + min_y) / 2;

    for (int i = 0; i < n_cluster; ++i) {
		printf("0_Cluster_center %g %g\n", (cent[i].x - cx) * scale + W / 2, (cent[i].y - cy) * scale + H / 2);
        for (int j = 0; j < len; ++j) {
            if (pts[j].group != i) continue;
			printf("%.3f %.3f\n", (pts[j].x - cx) * scale + W / 2, (pts[j].y - cy) * scale + H / 2);
        }

    }

	free(colors);
}


void parseArgs(int argc, char **argv, Opts &o) {
    if (argc < 3) {
        std::cout << "Specify num clusters and num points" << std::endl;
        exit(1);
    }
    read_value<int>(argv[1], o.num_cl);
    read_value<int>(argv[2], o.num_p);

    if (argc == 4) {
        read_value<bool>(argv[3], o.verify);
    }
}


void verify(Point *v, int num_p, Point *centers, int num_c) {
    std::cout << "Veryfing... " << std::endl;

    for (int i = 0; i < num_p; ++i) {
        double min_dist = HUGE_VAL;

        int closer_cluster = -1;
        for (int j = 0; j < num_c; ++j) {
            double tmp_dist = dist2(&v[i], &centers[j]);
            if (min_dist > tmp_dist) {
                min_dist = tmp_dist;
                closer_cluster = j;
            }
        }
        if (closer_cluster != v[i].group) {
            std::cout << "There is a closer cluster" << std::endl;
            exit(1);
        }
    }
    std::cout << "Successfull verification!" << std::endl;
}


int main(int argc, char **argv)
{
    Opts o;
    parseArgs(argc, argv, o);

	Point *v = gen_xy(o.num_p, 10);
	Point *c = lloyd(v, o.num_p, o.num_cl);

	print_eps(v, o.num_p, c, o.num_cl);

    if (o.verify) {
        verify(v, o.num_p, c, o.num_cl);
    }
	// free(v); free(c);
	return 0;
}
