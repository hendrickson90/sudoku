#include <iostream>
#include <vector>
using namespace std;

class sudoko_object {       // The class
public:             // Access specifier
	bool found = false;    
	vector<int> solutions = {1,2,3,4,5,6,7,8,9};
};


void print(std::vector <int> const& a) {
	std::cout << "The vector elements are : ";

	for (int i = 0; i < a.size(); i++)
		std::cout << a.at(i) << ' ';
}

/*
sudoko_object::sudoko_object(){
	found = false;
	solutions = {1,2,3,4,5,6,7,8,9};
}

*/

int main()
{
    // x[0][0] x[0][1] x[0][2]
    // x[1][0] x[1][1] x[1][2]
    // x[2][0] x[2][1] x[2][2]


	bool main_loop = true;

	sudoko_object *obj1;

	obj1 = new sudoko_object();

	cout << obj1->found << endl;

	cout << endl;




	sudoko_object arrayobj[3][3][3][3];


	cout << arrayobj[2][2][2][2].found << endl;

	cout << arrayobj[2][2][2][2].solutions.size() << endl;

	cout << endl;


	/*
	
	// example array 
    int PuzzleInput[3][3][3][3] = { 
                           {{{ 1, 2, 3},{ 4, 5, 6},{ 7, 8, 9}},
							{{10,11,12},{13,14,15},{16,17,18}},
							{{19,20,12},{22,23,24},{25,26,27}}},
                           {{{28,29,30},{31,32,33},{34,35,36}},
							{{37,38,39},{40,41,42},{43,44,45}},
							{{46,47,48},{49,50,51},{52,53,54}}},
                           {{{55,56,57},{58,59,60},{61,62,63}},
							{{64,65,66},{67,68,69},{70,71,72}},
							{{73,74,75},{76,77,78},{79,80,81}}}

                        };
    
   
   */

	/*
	int PuzzleInput[3][3][3][3] = {
						  {{{5,3,0},{0,7,0},{0,0,0}},
						   {{6,0,0},{1,9,5},{0,0,0}},
						   {{0,9,8},{0,0,0},{0,6,0}}},
						  {{{8,0,0},{0,6,0},{0,0,3}},
						   {{4,0,0},{8,0,3},{0,0,1}},
						   {{7,0,0},{0,2,0},{0,0,6}}},
						  {{{0,6,0},{0,0,0},{2,8,0}},
						   {{0,0,0},{4,1,9},{0,0,5}},
						   {{0,0,0},{0,8,0},{0,7,9}}}

	};

	*/
	

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
					cout << PuzzleInput[i][j][k][l] << "   ";
				}
			}
			cout << endl;
		}
		
	}


	//cout << PuzzleInput[2][0][2][0] << "   ";


	
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
	cout << endl;



	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					cout << arrayobj[i][j][k][l].solutions.size() << "   ";
				}
			}
			cout << endl;
		}

	}

	cout << endl;



	//cout << arrayobj[0][0][0][0].solutions[8] << endl;

	//for (auto b = arrayobj[0][0][0][0].solutions.begin(); b != arrayobj[0][0][0][0].solutions.end(); b++)
		//std::cout << *b << ' ';






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
						if ((arrayobj[i][j][k][l].solutions.size() == 1) && (arrayobj[i][j][k][l].found == false)) {

							cout << endl;
							cout << endl;
							cout << endl;

							cout << "************************************************************************************" << endl;
							cout << "********************array[" << i << "][" << j << "][" << k << "][" << l << "]" << " has a size of 1 and an element of " << arrayobj[i][j][k][l].solutions.front() << endl;
							//cout << "array[" << i << "][" << j << "][" << k << "][" << l << "]" << " size = " << arrayobj[i][j][k][l].solutions.size() << " containing " << arrayobj[i][j][k][l].solutions.front() << endl; 

							cout << endl;

							main_loop = true;

							//remove vertical 

														
							cout << endl;
							cout << "////////// checking vertical ///////////// " << endl;
							cout << endl;
							

							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if (
										//(std::find(arrayobj[z][x][k][l].solutions.begin(), arrayobj[z][x][k][l].solutions.end(), arrayobj[i][j][k][l].solutions.front()) != arrayobj[z][x][k][l].solutions.end()) &&
										(z == i && x == j)
										) {

										cout << "[" << z << "][" << x << "][" << k << "][" << l << "]" << " is itself not removing element " << endl;
										cout << " z:" << z << " = i:" << i << "       x:" << x << " = j:" << j << endl;
										cout << endl;
										
									}
									else {
										// remove found thing from array arrayobj[z][x][k][l].solutions


										print(arrayobj[z][x][k][l].solutions);
										cout << endl;

										arrayobj[z][x][k][l].solutions.erase(remove(arrayobj[z][x][k][l].solutions.begin(), arrayobj[z][x][k][l].solutions.end(), arrayobj[i][j][k][l].solutions.front()), arrayobj[z][x][k][l].solutions.end());
									
										cout << "[" << z << "][" << x << "][" << k << "][" << l << "]" << " removing " << arrayobj[i][j][k][l].solutions.front() << endl;
										//cout << arrayobj[i][z][k][x].solutions.size() << endl;
										print(arrayobj[z][x][k][l].solutions);
										cout << endl;
										cout << endl;
									
									}


								}
							}


							

							//removal horizontal
							cout << endl;
							cout << "////////// checking horizontal ///////////// " << endl;
							cout << endl;

							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if (
										//(std::find(arrayobj[i][j][z][x].solutions.begin(), arrayobj[i][j][z][x].solutions.end(), arrayobj[i][j][k][l].solutions.front()) != arrayobj[i][j][z][x].solutions.end()) &&
										(z == k && x == l)
										) {

										cout << "[" << i << "][" << j << "][" << z << "][" << x << "]" << " is itself not removing element " << endl;
										cout << " z:" << z << " = k:" << k << "       x:" << x << " = l:" << l << endl;
										cout << endl;

									}
									else {
										// remove found thing from array arrayobj[i][j][z][x].solutions


										print(arrayobj[i][j][z][x].solutions);
										cout << endl;

										arrayobj[i][j][z][x].solutions.erase(remove(arrayobj[i][j][z][x].solutions.begin(), arrayobj[i][j][z][x].solutions.end(), arrayobj[i][j][k][l].solutions.front()), arrayobj[i][j][z][x].solutions.end());


										//if (arrayobj[i][j][k][l].solutions.size() < 0 )
										cout << "[" << i << "][" << j << "][" << z << "][" << x << "]" << " removing " << arrayobj[i][j][k][l].solutions.front() << endl;
										//cout << arrayobj[i][z][k][x].solutions.size() << endl;
										print(arrayobj[i][j][z][x].solutions);
										cout << endl;
										cout << endl;


									}


								}
							}

							

							//remove cell local group (3x3)

							cout << endl;
							cout << "////////// checking local squair ///////////// " << endl;
							cout << endl;


							for (int z = 0; z < 3; z++)
							{
								for (int x = 0; x < 3; x++)
								{
									if (

										//this is 
										//(std::find(arrayobj[i][z][k][x].solutions.begin(), arrayobj[i][z][k][x].solutions.end(), arrayobj[i][j][k][l].solutions.front()) != arrayobj[i][z][k][x].solutions.end()) &&
										((z == j) && (x == l))
										) {

										cout << "[" << i << "][" << z << "][" << k << "][" << x << "]" << " is itself not removing element " << endl;
										cout << " z:" << z << " = j:" << j << "       x:" << x << " = l:" << l << endl;
										cout << endl;


									}
									else {



										// remove found thing from array arrayobj[i][z][k][x].solutions


										print(arrayobj[i][z][k][x].solutions);
										cout << endl;
										//cout << arrayobj[i][z][k][x].solutions.size() << endl;
										arrayobj[i][z][k][x].solutions.erase(remove(arrayobj[i][z][k][x].solutions.begin(), arrayobj[i][z][k][x].solutions.end(), arrayobj[i][j][k][l].solutions.front()), arrayobj[i][z][k][x].solutions.end());

										//if (arrayobj[i][j][k][l].solutions.size() < 0 )
										cout << "[" << i << "][" << z << "][" << k << "][" << x << "]" << " removing " << arrayobj[i][j][k][l].solutions.front() << endl;
										//cout << arrayobj[i][z][k][x].solutions.size() << endl;
										print(arrayobj[i][z][k][x].solutions);
										cout << endl;
										cout << endl;


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
					cout << arrayobj[i][j][k][l].solutions.size() <<":"<< arrayobj[i][j][k][l].found <<"   ";
				}
			}
			cout << endl;
		}

	}


	cout << endl;
	cout << endl;

	cout << "0,0,2,2 ";
	print(arrayobj[0][0][2][2].solutions);
	cout << endl;

	cout << "2,2,0,0 ";
	print(arrayobj[2][2][0][0].solutions);
	cout << endl;


	cout << arrayobj[0][1][0][0].solutions.front();

	cout << arrayobj[0][1][0][0].solutions.front();


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
					cout << arrayobj[i][j][k][l].solutions.front()<< "   ";
				}
			}
			cout << endl;
		}

	}

	cout << endl;
	


    return 0;
}