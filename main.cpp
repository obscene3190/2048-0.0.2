#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{
	std::cout << "Let`s play 2048!\n" << std::endl;
	
	int matrix[4][4], i, j, count=1, m=0;
	char op;

	for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	
	for (int k=0; k<2; k++){
sluchay:i=rand()%4;
		j=rand()%4;
		
		if (matrix[i][j] == 0) {
			if (rand()%10 <=8) 	matrix[i][j]=2;
			else matrix [i][j]=4;
		}
		else goto sluchay;
	};
	
	
	for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
			if (matrix[i][j] == 0){
				std::cout << "*  ";
			}
			else {
				std::cout << matrix[i][j] << "  ";
			}
		}
		std::cout << std::endl;
	}
	
	std::cout << "Press your letter: ";
	
	std::cin >> op;
	
	while(count > 0) {
		
		std::cout << std::endl;
		
begin: switch (op)
		{
			case 'j': 
			{
				for (j=0; j<4; j++) {
					for (i=3; i>0; i--)
					if (matrix[i] [j] == 0) {
						for (int k=i-1; k>=0; k--){
							if (matrix[k][j] != 0){
								matrix[i][j] = matrix[k][j];
								matrix[k][j]=0;
								break;
							}
						}
					}
					
				}
				
				for (j=0; j<4; j++) {
					
					for (i=3; i>0; i--){
						if (matrix[i][j] == matrix[i-1] [j]) {
							matrix[i][j] += matrix[i-1][j];
							matrix[i-1][j]=0;
							m+=matrix[i][j];
						}
					}
				}
				
				for (j=0; j<4; j++) {
					for (i=3; i>0; i--)
					if (matrix[i] [j] == 0) {
						for (int k=i-1; k>=0; k--){
							if (matrix[k][j] != 0){
								matrix[i][j] = matrix[k][j];
								matrix[k][j]=0;
								break;
							}
						}
					}
					
				}
			
				break;
			}
		
			case 'k': 
			{
				for (j=0; j<4; j++) {
					for (i=0; i<3; i++)
					if (matrix[i] [j] == 0) {
						for (int k=i+1; k<=3; k++){
							if (matrix[k][j] != 0){
								matrix[i][j] = matrix[k][j];
								matrix[k][j]=0;
								break;
							}
						}
					}
				}
				
				for (j=0; j<4; j++) {
					for (i=0; i<3; i++)
					if (matrix[i][j] == matrix[i+1] [j]) {
						matrix[i][j] += matrix[i+1][j];
						matrix[i+1][j]=0;
						m+=matrix[i][j];
					}
				}
				
				for (j=0; j<4; j++) {
					for (i=0; i<3; i++)
					if (matrix[i] [j] == 0) {
						for (int k=i+1; k<=3; k++){
							if (matrix[k][j] != 0){
								matrix[i][j] = matrix[k][j];
								matrix[k][j]=0;
								break;
							}
						}
					}
				}
							
				break;
			}
			
			case 'h': 
			{
				for (i=0; i<4; i++) {
					for (j=0; j<3; j++)
					if (matrix[i] [j] == 0) {
						for (int k=j+1; k<=3; k++){
							if (matrix[i][k] != 0){
								matrix[i][j] = matrix[i][k];
								matrix[i][k]=0;
								break;
							}
						}
					}
				}
				
				for (i=0; i<4; i++) {
					for (j=0; j<3; j++)
					if (matrix[i][j] == matrix[i] [j+1]) {
						matrix[i][j] += matrix[i][j+1];
						matrix[i][j+1]=0;
						m+=matrix[i][j];
					}
				}
			
				for (i=0; i<4; i++) {
					for (j=0; j<3; j++)
					if (matrix[i] [j] == 0) {
						for (int k=j+1; k<=3; k++){
							if (matrix[i][k] != 0){
								matrix[i][j] = matrix[i][k];
								matrix[i][k]=0;
								break;
							}
						}
					}
				}
						
				break;
			}
			
			case 'l': 
			{
				for (i=0; i<4; i++) {
					for (j=3; j>0; j--)
					if (matrix[i] [j] == 0) {
						for (int k=j-1; k>=0; k--){
							if (matrix[i][k] != 0){
								matrix[i][j] = matrix[i][k];
								matrix[i][k]=0;
								break;
							}
						}
					}
				}
				
				for (i=0; i<4; i++) {
					for (j=3; j>0; j--)
					if (matrix[i][j] == matrix[i] [j-1]) {
						matrix[i][j] += matrix[i][j-1];
						matrix[i][j-1]=0;
						m+=matrix[i][j];
					}
				}
				
				for (i=0; i<4; i++) {
					for (j=3; j>0; j--)
					if (matrix[i] [j] == 0) {
						for (int k=j-1; k>=0; k--){
							if (matrix[i][k] != 0){
								matrix[i][j] = matrix[i][k];
								matrix[i][k]=0;
								break;
							}
						}
					}
				}
				
				break;
			}
			
			default: {
				std::cout << "You`ve printed the wrong symbol! Please, print it again: ";
				std::cin >> op;
				std::cout << std::endl;
				goto begin;
			}
			
		}
		
again:	i=rand()%4;
		j=rand()%4;

		if (matrix[i][j] == 0) {
		if (rand()%10 <=8) 	matrix[i][j]=2;
		else matrix [i][j]=4;
		}
		else goto again;
	
		for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
		if (matrix[i][j] == 0){
			std::cout << "*  ";
		}
		else {
			std::cout << matrix[i][j] << "  ";
		}
		}
				
		std::cout << std::endl;
		}
				
		std::cout << "Your goals are: " << m << std::endl << "Press your letter: ";
				
		std::cin >> op;
	}
	
	return 0;
}
