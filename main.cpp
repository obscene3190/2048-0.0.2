#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{
	std::cout << "Let`s play 2048!\n";
	
	int matrix[4][4], i, j, l, count=1, m=0;
	char op;

	//Îáíóëåíèå ìàññèâà

	for ( i = 0; i < 4; i++) {
		for ( j = 0; j < 4; j++) {
			matrix[i][j]=0;
		}
	}
	
	srand(time(NULL));
	
	//Ââîä ñëó÷àéíîãî çíà÷åíèå (2 èëè 4) â ñëó÷àéíóþþ ÿ÷åéêó ìàòðèöû
	
	i=rand()%4;
	j=rand()%4;
	
	if (rand()%10 <=8) 	matrix[i][j]=2;
	else matrix [i][j]=4;
	
	while(1) {
		
		std::cout << std::endl;
		
		/*Ïðîâåðêà óñëîâèÿ, ÷òî èãðîê ìîæåò ñäåëàòü õîä: åñëè ñóùåñòâóþò äâà ñîñåäíèõ ðàâíûõ èëè õîòÿ áû îäèí 
		íóëåâîé ýëåìåíòû. Â ïðîòèâíîì ñëó÷àå, ïðîãðàììà âûõîäèò èç öèêëà */
		
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
		
		/*Äîáàâëåíèå ñëó÷àéíîãî çíà÷åíèå (2 èëè 4) â ñëó÷àéíûé íóëåâîé ýëåìåíò ìàññèâà, åñëè òàêîé èìååòñÿ.
		Åñëè ñëó÷àéíî ñãåíåðèðîâàííàÿ ïîçèöèÿ èìååò íåíóëåâîå çíà÷åíèå, òî îïåðàöèÿ âûïîëíÿåòñÿ çàíîâî âîçâðàùåíèåì
		ê ìåòêå again. Äëÿ ïðîâåðêè óñëîâèÿ ñëóæèò ñ÷åò÷èê count, êîòîðûé ïðèíèìàåò çíà÷åíèå 1, åñëè áûë ñîâåðøåí êîððåêòíûé
		õîä. Äàëåå íà ýêðàí âûâîäÿòñÿ ìàòðèöà, êîëè÷åñòâî î÷êîâ è ïîëüçîâàòåëÿ ïðèãëàøàþò ñîâåðøèòü õîä. Åñëè ââåäåíûé äî ýòîãî
		ìîìåíòà õîä ñîâåðøèòü íåâîçìîæíî, ïðîãðàììà ïðîñèò ñîâåðøèòü äðóãîé õîä.*/
		
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
		
		/* Ñ ïîìîùüþ îïåðàòîðà âûáîðà ïî óñëîâèþ ïðîãðàììà âûïîëíÿåò õîä, ââåäåííûé ïîëüçîâàòåëåì. Â ñëó÷àå
		îïèñêè ïîëüçîâàòåëåì ïðîãðàììà óêàçûâàåò, ÷òî ïîëüçîâàòåëü ââåë íåïðàâèëüíûé ñèìâîë è ïðîñèò ââåñòè
		åãî êîððåêòíî*/
		
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
	
	//Â ñëó÷àå îêîí÷àíèÿ èãðû ïðîãðàììà áëàãîäàðèò ïîëüçîâàòåëÿ çà èãðû è âûâîäèò êîëè÷åñòâî åãî î÷êîâ
	
	std::cout << "Sorry, you lose! Thanks for the good game! Your goals are: " << m;
	
	std::cin.get();
	
	return 0;
}
