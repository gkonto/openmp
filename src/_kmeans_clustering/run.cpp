#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "auxiliaries.hpp"
 
typedef struct Point { 
    double x = 0.0;
    double y = 0.0;
    int group = 0;
} Point, *point;
 
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
	double d, min_d;

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
 
#	define for_n for (c = cent, i = 0; i < n_cluster; i++, c++)
   
    if (d2) {
        *d2 = min_d;
    }

	return min_i;
}
 
void kpp(Point *pts, int len, Point *cent, int n_cent)
{
#	define for_len for (j = 0, p = pts; j < len; j++, p++)
	int i, j;
	int n_cluster;
	double sum, *d = (double *)malloc(sizeof(double) * len);
 
	point p, c;
	cent[0] = pts[ rand() % len ];
	for (n_cluster = 1; n_cluster < n_cent; n_cluster++) {
		sum = 0;
        for (j = 0; j < len; ++j) {
            nearest(&pts[j], cent, n_cluster, &d[j]);
            sum += d[j];
        }

		sum = randf(sum);
        for (j = 0; j < len; ++j) {
            if ((sum -= d[j]) > 0) continue;
            cent[n_cluster] = pts[j];
            break;
        }
	}

	//for_len p->group = nearest(p, cent, n_cluster, 0);
    for (j = 0; j < len; ++j) {
        pts[j].group = nearest(&pts[j], cent, n_cluster, 0);
    }
	free(d);
}
 
point lloyd(point pts, int len, int n_cluster)
{
	int i, j, min_i;
	int changed;
 
	point cent = (point)malloc(sizeof(Point) * n_cluster), p, c;
 
	/* assign init grouping randomly */
	//for_len p->group = j % n_cluster;
 
	/* or call k++ init */
	kpp(pts, len, cent, n_cluster);
 
	do {
		/* group element for centroids are used as counters */
		for_n { c->group = 0; c->x = c->y = 0; }
		for_len {
			c = cent + p->group;
			c->group++;
			c->x += p->x; c->y += p->y;
		}
		for_n { c->x /= c->group; c->y /= c->group; }
 
		changed = 0;
		/* find closest centroid of each point */
		for_len {
			min_i = nearest(p, cent, n_cluster, 0);
			if (min_i != p->group) {
				changed++;
				p->group = min_i;
			}
		}
	} while (changed > (len >> 10)); /* stop when 99.9% of points are good */
 
	for_n { c->group = i; }
 
	return cent;
}
 
void print_eps(point pts, int len, point cent, int n_cluster)
{
#	define W 400
#	define H 400
	int i, j;
	point p, c;
	double min_x, max_x, min_y, max_y, scale, cx, cy;
	double *colors = (double *)malloc(sizeof(double) * n_cluster * 3);
 
	for_n {
		colors[3*i + 0] = (3 * (i + 1) % 11)/11.;
		colors[3*i + 1] = (7 * i % 11)/11.;
		colors[3*i + 2] = (9 * i % 11)/11.;
	}
 
	max_x = max_y = -(min_x = min_y = HUGE_VAL);
	for_len {
		if (max_x < p->x) max_x = p->x;
		if (min_x > p->x) min_x = p->x;
		if (max_y < p->y) max_y = p->y;
		if (min_y > p->y) min_y = p->y;
	}
	scale = W / (max_x - min_x);
	if (scale > H / (max_y - min_y)) scale = H / (max_y - min_y);
	cx = (max_x + min_x) / 2;
	cy = (max_y + min_y) / 2;

	for_n {
		printf("0_Cluster_center %g %g\n", (c->x - cx) * scale + W / 2, (c->y - cy) * scale + H / 2);
		for_len {
			if (p->group != i) continue;
			printf("%.3f %.3f\n", (p->x - cx) * scale + W / 2, (p->y - cy) * scale + H / 2);
		}
	}

	free(colors);
#	undef for_n
#	undef for_len
}
 
#define PTS 100000
#define K 11
namespace {
    struct Opts {
        int num_cl = 0;
        int num_p = 0;
        bool verify = false;
    };
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
        Point *closer_p = nullptr;

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
	int i;
	point v = gen_xy(o.num_p, 10);
	point c = lloyd(v, o.num_p, o.num_cl);

	print_eps(v, o.num_p, c, o.num_cl);

    if (o.verify) {
        verify(v, o.num_p, c, o.num_cl);
    }
	// free(v); free(c);
	return 0;
}
