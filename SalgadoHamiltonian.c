/*
Name: 			Antonio Salgado Lemus
Description:    This program will get data from files and 
				distinguish whether the text files create a 
				Hamiltonian Circuit or not. 
				
Course: 		CS-430
Date: 			11-25-2019
*/

#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h>


// Vertices in the matrix 
#define VERTICES 5 

//****************************************************************************************************
// Name:		checking
// Purpose:		This function will be checking if the vertex conncets by adding to the index
// Incoming:	chart[][] (bool), track[], (int), position (int)
// Outgoing:		
// Return:		TRUE or FALSE
//****************************************************************************************************
bool checking(int v, bool chart[VERTICES][VERTICES], int track[], int position) 
{ 
    
    if (chart [ track[position-1] ][ v ] == 0) // checking if vertex is adjacent
        return false; 
  
    
    int i;
	for ( i = 0; i < position; i++) // checking if its been used
        if (track[i] == v) 
            return false; 
  
    return true; 
} 
  
//****************************************************************************************************
// Name:		recursiveHamilton	
// Purpose:		This fucntion is a recursive function 
// 				to help solve the Hamiltonian circuit.
// Incoming:	chart[][] (bool), track[], (int), position (int)
// Outgoing:	
// Return:		TRUE or FALSE
//****************************************************************************************************
bool recursiveHamilton(bool chart[VERTICES][VERTICES], int track[], int position) 
{ 
    
    if (position == VERTICES) // checking if all vertices are assigned to matrix
    { 
       
        if (chart[ track[position-1] ][ track[0] ] == 1 ) 
           return true; 
           
        else
          return false; 
    } 
  
   
    int v;
	for ( v = 1; v < VERTICES; v++) // making different vertex move 
    { 
       
        if (checking(v, chart, track, position)) // checking if vertex can enter matrix
        { 
            track[position] = v; 
  
           
            if (recursiveHamilton (chart, track, position+1) == true) 
                return true; 
  
            
            track[position] = -1; 
        } 
    } 
  
   
    return false; 
} 
  
//****************************************************************************************************
// Name:		hamiltonCycle	
// Purpose:		This function will be using the backtracking
//				strategy in order to solve the Hamiltonian Circuit. 
// Incoming:	chart[][] (bool)
// Outgoing:	
// Return:		TRUE or FALSE
//****************************************************************************************************
bool hamiltonCycle(bool chart[VERTICES][VERTICES]) 
{ 
   
    int* track = malloc(sizeof(int)* VERTICES); 
    int i; 
	for ( i = 0; i < VERTICES; i++) 
        track[i] = -1; 
  
  
    track[0] = 0; 
    
    if ( recursiveHamilton(chart, track, 1) == false ) 
    { 
        printf("\nHamiltonian Circuit does not exist!\n"); 
        return false; 
    } 
  
    printf ("Hamiltonian Circuit \n"); 
  
	for ( i = 0; i < VERTICES; i++) // prints the path 
        printf(" %d ", track[i]); 
  
   
    printf(" %d ", track[0]); 
    printf("\n"); 
	
	free(track);
	 
    return true; 
} 
  

int main(void) 
{   
	int i, j, num;
    bool matrix[VERTICES][VERTICES];
    char filename[100], again;
    
	do{
	
		printf("Enter file name: ");    // ask for a file name
	    scanf("%s", filename);  // read file name
	    
	    // matrix1.txt will be hamiltonian circuit 
	     	// Path: 0, 1, 4, 3, 2, 0
	    
	    // matrix2.txt will not be hamiltonian circuit 
	    
	    // matrix3.txt will be hamiltonian circuit 
	    	// Path: 0, 1, 4, 2, 3, 0
	    
	    
	    FILE *fp = fopen(filename, "r");
	    
	    // read graph from file
	    for (i = 0; i < VERTICES; ++i) {
	        for (j = 0; j < VERTICES; ++j) {
	            fscanf(fp, "%d", &num); // reads each number from graph into a file.
	            matrix[i][j] = num;
	        }
	    }
	  
	     fclose(fp);
	     hamiltonCycle(matrix);
	     
	    printf("Do you want to continue (Y/N)?");
	    scanf("%s", &again);
	    
	 }while(again == 'Y' || again == 'y');
  	
    return 0;
} 
