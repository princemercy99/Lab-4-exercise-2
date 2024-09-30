#ifndef GRAPH_H
#define GRAPH_H

#include "Display.h"
#include "LineStyle.h"
#include "DataPoints.h"
#include <memory>

using std::shared_ptr;

class Graph
{
public:
	Graph(shared_ptr<Display> display) : display_(display)
	{
	}
	void plot(DataPoints data_points, LineStyle &line_plotter);

private:
	void drawToBuffer(const vector<PointPair> &points, LineStyle &line_plotter);
	shared_ptr<Display> display_;
};

#endif
