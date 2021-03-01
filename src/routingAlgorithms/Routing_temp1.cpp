#include "Routing_temp1.h"

RoutingAlgorithmsRegister Routing_temp1::routingAlgorithmsRegister("temp1", getInstance());

Routing_temp1 * Routing_temp1::routing_temp1 = 0;
RoutingAlgorithm * Routing_temp1::caoe = 0;
RoutingAlgorithm * Routing_temp1::caxy = 0;

Routing_temp1 * Routing_temp1::getInstance() {
	if ( routing_temp1 == 0 )
		routing_temp1 = new Routing_temp1();

	return routing_temp1;
}

vector<int> Routing_temp1::route(Router * router, const RouteData & routeData)
{
	vector<int> directions;
	caoe = RoutingAlgorithms::get("CAOE");
	caxy = RoutingAlgorithms::get("CAXY");

	if (!caoe or !caxy)
			assert(false);

	/* [TODO] 
		calculate average congetion index.
		select a thrushold 
		if ci >= theta : CAOE
		else : CAXY

		Info:
		#define DIRECTION_NORTH         0
		#define DIRECTION_EAST          1
		#define DIRECTION_SOUTH         2
		#define DIRECTION_WEST          3
	*/ 

	float avg_cong = (router->CI(0) + router->CI(1) + router->CI(2) + router->CI(3))/4;
	//cout << avg_cong;
	if(avg_cong >= 2){
		directions = caoe->route(router,routeData);
	}
	else{
		directions = caxy->route(router,routeData);
	}

    return directions;
}
