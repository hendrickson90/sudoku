#include <iostream>
#include <vector>
using namespace std;

class sudoko_object {       // The class
public:             // Access specifier
	bool found = false;
	vector<int> solutions = { 1,2,3,4,5,6,7,8,9 };
};


int main()
{
	// x[0][0] x[0][1] x[0][2]
	// x[1][0] x[1][1] x[1][2]
	// x[2][0] x[2][1] x[2][2]

	bool main_loop = true;

	sudoko_object arrayobj[3][3][3][3];


	int PuzzleInput[3][3][3][3] = {
						  {{{7,8,0},{4,0,0},{1,2,0}},
						   {{6,0,0},{0,7,5},{0,0,9}},
						   {{0,0,0},{6,0,1},{0,7,8}}},
						  {{{0,0,7},{0,4,0},{2,6,0}},
						   {{0,0,1},{0,5,0},{9,3,0}},
						   {{9,0,4},{0,6,0},{0,0,5}}},
						  {{{0,7,0},{3,0,0},{0,1,2}},
						   {{1,2,0},{0,0,7},{4,0,0}},
						   {{0,4,9},{2,0,6},{0,0,7}}}

	};


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					if (PuzzleInput[i][j][k][l] != 0) {
						arrayobj[i][j][k][l].solutions.clear();
						arrayobj[i][j][k][l].solutions.push_back(PuzzleInput[i][j][k][l]);
					}
				}
			}
			cout << endl;
		}

	}

	cout << endl;



	do {


		main_loop = false;


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if ((arrayobj[i][j][k][l].solutions.size() == 1) && 
							(arrayobj[i][j][k][l].found == false)) {



							main_loop = true;

							//remove vertical 


							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if ((z == i && x == j)) {

									}
									else {
										// remove found thing from array arrayobj[z][x][k][l].solutions

										arrayobj[z][x][k][l].solutions.erase(
												remove(arrayobj[z][x][k][l].solutions.begin(), 
												arrayobj[z][x][k][l].solutions.end(), 
												arrayobj[i][j][k][l].solutions.front()), 
											arrayobj[z][x][k][l].solutions.end());

									}


								}
							}
							//removal horizontal


							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if ((z == k && x == l)) {


									}
									else {
										// remove found thing from array arrayobj[i][j][z][x].solutions

										arrayobj[i][j][z][x].solutions.erase(
											remove(arrayobj[i][j][z][x].solutions.begin(), 
											arrayobj[i][j][z][x].solutions.end(),
											arrayobj[i][j][k][l].solutions.front()),
										arrayobj[i][j][z][x].solutions.end());


									}


								}
							}

							//remove cell local group (3x3)


							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if (((z == j) && (x == l))) {


									}
									else {

										arrayobj[i][z][k][x].solutions.erase(
											remove(arrayobj[i][z][k][x].solutions.begin(), 
												arrayobj[i][z][k][x].solutions.end(), 
												arrayobj[i][j][k][l].solutions.front()), 
											arrayobj[i][z][k][x].solutions.end());


									}


								}
							}

							arrayobj[i][j][k][l].found = true;
						}
					}
				}

			}

		}

	} while (main_loop);


	cout << endl;
	cout << endl;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					cout << arrayobj[i][j][k][l].solutions.front() << "   ";
				}
			}
			cout << endl;
		}

	}
	return 0;
}