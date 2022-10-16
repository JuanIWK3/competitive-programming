#include <iostream>



void selection_sort(int *vector,int length, int *count)
{
	/*
	Ordernação por seleção consiste em pegar
        o menor valor de um container e movê-lo
	para a primeira posição, até que esteja
	ordenado.
	
	É um dos menos performáticos métodos de 
	ordenação O(n²)	
	*/
	int aux;
	for(int i = 0; i < length - 1;i++){
	    for(int j = 0; j < length - 1; j++){
		    if(vector[j] > vector[j + 1]){
			(*count)++;       // mede interações
		    	aux = vector[j];
			vector[j] = vector[j + 1];
			vector[j + 1] = aux;
		    }
	    }
	 }

}


int main()
{
	int count = 0;           // mede o num de interações
	int *pointer = &count;   // aponta para o endereço de count

	int vector[] = {6, 2, 1, 3, 5, 4};   

	std::cout << "Not ordered" << std::endl;
	for(int element: vector){
		std::cout << element << " ";
	}

	std::cout << std::endl << "Ordered" << std::endl;

	selection_sort(vector, 6, pointer);

	for(int element: vector){
		std::cout << element << " "; 
	}

	std::cout << std::endl << "Quantidade de interações: " << count << std::endl;
	
	return 0;
}
