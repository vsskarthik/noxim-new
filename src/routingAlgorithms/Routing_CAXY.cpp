#include "Routing_CAXY.h"

RoutingAlgorithmsRegister Routing_CAXY::routingAlgorithmsRegister("CAXY", getInstance());

Routing_CAXY * Routing_CAXY::routing_CAXY = 0;
RoutingAlgorithm * Routing_CAXY::xy = 0;

Routing_CAXY * Routing_CAXY::getInstance() {
	if ( routing_CAXY == 0 )
		routing_CAXY = new Routing_CAXY();

	return routing_CAXY;
}

vector<int> Routing_CAXY::route(Router * router, const RouteData & routeData)
{
		vector<int> directions;
		xy = RoutingAlgorithms::get("XY");

		if (!xy)
				assert(false);

		vector<int> temp_dirs = xy->route(router,routeData);
		if(temp_dirs.size() == 1)
			directions.push_back(temp_dirs[0]);
		else{
			int ci1 = router->CI(temp_dirs[0]);
			int ci2 = router->CI(temp_dirs[1]);
			if(ci1<ci2)
				directions.push_back(temp_dirs[0]);
			else if(ci1>ci2)
				directions.push_back(temp_dirs[1]);
			else{
				directions.push_back(temp_dirs[0]);
				directions.push_back(temp_dirs[1]);
			}
		}

    return directions;
}
