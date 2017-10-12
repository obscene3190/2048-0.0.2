#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{
	std::cout << "Let`s play 2048!\n";
	
	int matrix[4][4], i, j, l, count=1, m=0;
	char op;

	//Обнуление массива

	for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	
	// Ввод случайного значение (2 или 4) в случайнуюю ячейку матрицы
	
	i=rand()%4;
	j=rand()%4;
	
	if (rand()%10 <=8) 	matrix[i][j]=2;
	else matrix [i][j]=4;
	
	while(1) {
		
		std::cout << std::endl;
		
		/* Проверка условия, что игрок может сделать ход: если существуют два соседних равных или хотя бы один
		нулевой элементы. В противном случае, программа выходит из цикла */
		
		l = 0;
		
		for (i=0; i<4; i++){
			for (j=0; j<4; j++)
				if (matrix[i][j] == matrix[i+1][j] || matrix[i][j] == matrix[i][j+1] || matrix[i][j] == 0) {
					l = 1;
					break;
				}
			if (l == 1) break;
		}
		
		if (l != 1) break;
		
		/* Добавление случайного значение (2 или 4) в случайный нулевой элемент массива, если такой имеется.
		Если случайно сгенерированная позиция имеет ненулевое значение, то операция выполняется заново возвращением
		к метке again. Для проверки условия служит счетчик count, который принимает значение 1, если был совершен корректный
		ход. Далее на экран выводятся матрица, количество очков и пользователя приглашают совершить ход. Если введеный до этого
		момента ход совершить невозможно, программа просит совершить другой ход. */
		
		if (count == 1){

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
					}
		else {
			std::cout << "You can`t make this action. Please, choose another letter: ";
		}
				
		std::cin >> op;
		
		count = 0;
		
		/* С помощью оператора выбора по условию программа выполняет ход, введенный пользователем. В случае
		описки пользователем программа указывает, что пользователь ввел неправильный символ и просит ввести
		его корректно */
		
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
								count=1;
								break;
							}
						}
					}
					
				}
				
				for (j=0; j<4; j++) {
					
					for (i=3; i>0; i--){
						if (matrix[i][j] == matrix[i-1] [j] && matrix[i][j] != 0) {
							matrix[i][j] += matrix[i-1][j];
							matrix[i-1][j]=0;
							m+=matrix[i][j];
							count = 1;
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
								count=1;
								break;
							}
						}
					}
				}
				
				for (j=0; j<4; j++) {
					for (i=0; i<3; i++)
					if (matrix[i][j] == matrix[i+1] [j] && matrix[i][j] != 0) {
						matrix[i][j] += matrix[i+1][j];
						matrix[i+1][j]=0;
						m+=matrix[i][j];
						count=1;
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
								count=1;
								break;
							}
						}
					}
				}
				
				for (i=0; i<4; i++) {
					for (j=0; j<3; j++)
					if (matrix[i][j] == matrix[i] [j+1] && matrix[i][j] != 0) {
						matrix[i][j] += matrix[i][j+1];
						matrix[i][j+1]=0;
						m+=matrix[i][j];
						count=1;
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
								count=1;
								break;
							}
						}
					}
				}
				
				for (i=0; i<4; i++) {
					for (j=3; j>0; j--)
					if (matrix[i][j] == matrix[i] [j-1] && matrix[i][j] != 0) {
						matrix[i][j] += matrix[i][j-1];
						matrix[i][j-1]=0;
						m+=matrix[i][j];
						count=1;
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
	}
	
	// В случае окончания игры программа благодарит пользователя за игры и выводит количество его очков
	
	std::cout << "Sorry, you lose! Thanks for the good game! Your goals are: " << m;
	
	std::cin.get();
	
	return 0;
}
