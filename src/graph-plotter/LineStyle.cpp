#include "LineStyle.h"

LineStyle::LineStyle(Colour colour, shared_ptr<Display> display_ptr):
	colour_(colour),
	display_ptr_(display_ptr)
{
	if (display_ptr == nullptr) throw "A valid display is required.";
}





