#include "Grid.h"

namespace Engine
{
	Grid::Grid(GameDataRef data): _data(data)
	{

	}

	void Grid::InitializeCells(unsigned int x, unsigned int y)
	{
		srand(time(NULL));
		for (unsigned int i = 0; i < x; i++) {
			for (unsigned int j = 0; j < y; j++) {
				int random = rand() % 2;
				GridCell* c = new GridCell(j, i, random);
				cells.push_back(c);
			}
		}
	}

	void Grid::DrawCells()
	{
		for (unsigned int i = 0; i < cells.size(); i++)
		{
			_data->window.draw(cells[i]->GetRekt());
		}
	}

	void Grid::RandomizeCellsState()
	{
		for(int i=0;i<cells.size();i++)
		{
			int random = rand() % 2;
			random == 0 ? cells[i]->SetAlive() : cells[i]->SetDead();
			cells[i]->SetNewState();
		}	
	}
	
	std::vector<GridCell*> Grid::GetGridCells()
	{
		return cells;
	}

	Grid::~Grid()
	{
		delete[] &cells;
	}

}
	
	


