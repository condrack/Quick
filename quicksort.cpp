/*************************************
Name: Taylor Condrack
Course: 3110
Assignment: Program 2 quicksort
Due Date: 9/19/15
************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class census
{
        public:
                string names;
                double area;
                int count;
                double density;
		census();

};
void quicksort(census a[],int, int);
int partition(census a[],int,int);
int medianofthree(census a[], int,int);
void swap(census a[],int,int);
int main()
{
//variables for runtime
	clock_t begin, end;
	double exectime;
	int p=0; //index of sequence beginning
        int r=73999; //index of sequence ending
	census a[74000];

	begin = clock();
	quicksort(a,p,r);
	end = clock();
//prints sorted output to text file
	ofstream sorted;
	sorted.open("quicksortoutput.txt");
	for(int i=0;i<74000;i++)
        {
                sorted<<a[i].names<<'|'<<a[i].area<<'|'<<a[i].count<<'|'<<a[i].density<<endl;
        }
	sorted.close();

	exectime = (double)(end-begin)/CLOCKS_PER_SEC;
	cout<<"Execution time = "<<exectime<<" S"<<endl;
	return 0;
}
//constructor reads in values from input file
census::census()
{
		getline(cin,names,'|');
                cin>>area;
                cin.get();
                cin>>count;
                cin.get();
                cin>>density;
}
//high level quicksort function arguments original array of objects, start and end indices
void quicksort(census a[],int p, int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
//returns index position
int partition(census a[], int p, int r)
{
	double x;
	int i;

	x=a[r].density;
	i=p-1;

	for(int j=p;j<r;j++)
	{
		if(a[j].density<=x)
		{
			i+=1;
			swap(a,i,j);
		}
	}
	swap(a,i+1,r);

	return i+1;

}
//swaps variables values
void swap(census a[], int u, int v)
{
	census buffer;

	buffer.names=a[u].names;
	buffer.area=a[u].area;
	buffer.count=a[u].count;
	buffer.density=a[u].density;

	a[u].names=a[v].names;
	a[u].area=a[v].area;
	a[u].count=a[v].count;
	a[u].density=a[v].density;

	a[v].names=buffer.names;
	a[v].area=buffer.area;
	a[v].count=buffer.count;
	a[v].density=buffer.density;

}
//calculates the pivot returns function that returns integer so partition function can use the median of three pivot
int medianofthree(census a[],int p,int r)
{
	int mid=(p+r)/2;
//swaps to put the values to create median in order
	if(a[mid].density<a[p].density)
	{
		swap(a,p,mid);
	}
	if(a[r].density<a[p].density)
	{
		swap(a,p,r);
	}
	if(a[r].density<a[mid].density)
	{
		swap(a,mid,r);
	}

	swap(a,mid,r);


	return partition(a,p,r);
}
