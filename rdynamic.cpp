#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 


struct triplet 									//enables to use 3 values that is weight/cost, vertice 1 and vertice 2 for krushals
{ 
   int x, y, z; 
}; 

bool repetetiveSorter(triplet xval, triplet yval)     //Custom boolean sorter
{ 
    return (xval.z < yval.z); 
} 


bool repetetiveSorter2(triplet xval, triplet yval)     //Custom boolean sorter
{ 
    return (xval.y < yval.y); 
} 

int max(int a, int b) { return (a > b) ? a : b; }

int q = 2;
int mod = 0;
vector<int> weight;
vector<triplet> vec1;

void knaps(int a, int b){

	if(a-1<=0 || b<=0){
		return;
	}
	else {
		
		vec1.push_back({q, a-1, b});
		q = q + 1;
		if(b - weight[a]<=0){return;}
		vec1.push_back({q, a-1, b - weight[a]});
		q = q+ 1;
	 	knaps(a-1,b);
		knaps(a-1,b - weight[a]);
		
	}
}

void Rdynamic()								// Gets N and Vector array 
{ 

	srand(time(NULL));			//Makes sure random digit doesn't repeat

	int n = (rand() % (8 - 4) + 4);		// gets values for N between 5 to 10
	
	cout <<"Selected N Value: " << n << endl; 	
    cout << "\n"; 
	int V = n; 
	
		
	vector<int> value;
	weight.resize(V,0);
	value.resize(V,0);
	
	srand (time(NULL));
	int sum= 0;
	for (int i = 1; i <=n; i++) {  
				
				int r = (rand() % (20 - 5)+5);			//generates random to be put in the Matrix Created
				weight[i] = r;					//insert random value
				sum += r;
	}
	int W = (0.6 * sum);
	
	
	srand (time(NULL));
	for (int i = 1; i <=n; i++) {  
				int s = (rand() % (	30 - 10) + 10);			//generates random to be put in the Matrix Created
				value[i] = s;					//insert random values
	}
	
	cout << "W value is :" <<W<<endl;
	for (int i = 1; i <=n; i++) {  
				
				cout << i<<". value: " << value[i] << "  weight: " << weight[i]<<endl;		//insert random values
	}
	
	
	vector<vector<int> > vec( n+1 , vector<int> (W+1, 0));
	
	
	
	vec1.push_back({1, n, W});
	knaps(n,W);															//Determination of nodes
	
	
	sort(vec1.begin(), vec1.end(), repetetiveSorter);  		//sorting all the edges E in non decreasing order
	sort(vec1.begin(), vec1.end(), repetetiveSorter2);  		//sorting all the edges E in non decreasing order

	
	
	
	
	for(int i = 1; i < W;i++){
		if(vec1[i].y!=0){
			
				
			
			int temp = vec1[i].z-weight[vec1[i].y];							//refinement logic
			int current = vec[vec1[i].y-1][temp] + value[vec1[i].y];
			
			if(weight[vec1[i].y]<=vec1[i].z){
			vec[vec1[i].y][vec1[i].z] = max(vec[vec1[i].y-1][vec1[i].z],current);	
			}
			else {
				vec[vec1[i].y][vec1[i].z] = 0;
			}
			
		}
	
	}
	
	cout<< "\n"; 								
	cout<< "\n";
	
	
	for (int i = 0; i <=n; i++) 
	{ 	
		for (int j = 0; j <=W; j++)
		{ 
			cout<< " "<< vec[i][j]; 				//Displaying Matrix
			
		} 
	
			cout<< "\n"; 				
	}	
	cout<< "\n"; 								
	cout<< "\n";
	if(vec[n][W]==0){
		cout << "Please try compiling and running again..."<<endl;
	}
	else
	cout << "Output processed in : Rdynamic.txt" << endl;
		FILE *tp;
	tp = fopen("Rdynamic.txt", "w");
	int z = 1;
	for (int i = 0; i <=n; i++) 
	{ 	
		
		
		for (int j = 0; j <=W; j++)
		if(vec[i][j]!=0){
		{ 
			fprintf(tp," %d",vec[i][j]); 				//Writing Matrix 
			
		} 
		
		}
		

			fprintf(tp,"\n");
			fprintf(tp,"row %d",z);
			z++;
	}
	fprintf(tp,"\n");
	fprintf(tp,"Please ignore last line");
	fclose(tp);
	
}		



	
int main(){
	
	Rdynamic();
	
}
 