#pragma once
struct Cell
{
	/*
	* NeighborCount can be max of 8 so we can pack in to 4 bits
	* as well as alive can just be 0 or 1
	*/
	unsigned char alive : 1, neighborCount : 4;
};