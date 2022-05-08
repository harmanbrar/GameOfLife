#pragma once
struct Cell
{
	/*
	* NeighborCount can be max of 8 so we can pack in to 4 bits
	* as well as alive can just be 0 or 1
	*/
	unsigned char alive : 1, 
				  neighborCount : 4, 
				  dirty : 1;
	Cell()
		:dirty(1)
	{
	}

	Cell(int aAlive, int aNeighborCount)
		:alive(aAlive), neighborCount(aNeighborCount), dirty(0)
	{
	}

	inline	bool IsDirty() const { return dirty == 1; }
};