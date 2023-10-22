#include<iostream>
#include<fstream>
#include<string>
#include<utility>
#include<stdexcept>


int addmatrix(int A[100][100],int B[100][100],int size)
{
	int C[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			C[i][j]=A[i][j]+B[i][j];
		}
	}
    std::cout<<"Matrix Sum(A+B)\n";
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            std::cout<<C[i][j]<<" ";
        }
    std::cout<<"\n";
    }
    return 0;
}

int submatrix(int A[100][100],int B[100][100],int size)
{
	int C[size][size];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			C[i][j]=A[i][j]-B[i][j];
		}
	}
	std::cout<<"Matrix subtract(A-B)\n";
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            std::cout<<C[i][j]<<" ";
        }
    std::cout<<"\n";
    }
	return 0;
}

int mulmatrix(int A[100][100],int B[100][100],int size)
{
	int C[size][size];

	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			C[i][j]=0;
			for (int k=0;k<size;k++)
			C[i][j]=C[i][j]+A[i][k]*B[k][j];
		}
	}
	std::cout<<"Matrix Product(A*B)\n";
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            std::cout<<C[i][j]<<" ";
        }
    std::cout<<"\n";
    }
	return 0;
}




int main()
{

    int A[100][100],B[100][100],size;
    std::string line;
    std::ifstream input_file;
    input_file.open("input.txt");
    input_file >> line;
    size = std::stoi(line);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            input_file>>line;
            A[i][j] = std::stoi(line);
        }
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            input_file>>line;
            B[i][j] = std::stoi(line);
        }
    }
    addmatrix(A,B,size);
    submatrix(A,B,size);
    mulmatrix(A,B,size);
}