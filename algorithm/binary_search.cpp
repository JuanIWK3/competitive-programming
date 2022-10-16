#include <iostream>


short int count_bin = 0;  // contador que indica n 
			              // tal que para busca binária O(logn) 
short int count = 0;      // e para busca normal O(n) 


bool binary_search(short int *count, int *vector, int search, int ini, int end)
{
	/*
	 Realiza a busca binária
	 funcionamento: divide a lista, ordenada,
	 pela metade verificando se o numero é
	 maior ou menor que a posição do meio
	 */
	(*count)++;

	int m = (ini + end) / 2;         // pega a metade do vetor
	int half = vector[m];		     // pega o que estiver nesta metade
	
	if(ini < end){
	    if(half == search) return true;
	    else if(half < search)
		    return binary_search(count, vector, search, half,end);
	    return binary_search(count, vector, search, ini + 1, half);   
	}
	return false;
}


bool normal_search(short int *count, int *vector, int search, int ini, int end)
{
	/*
	 Busca normal é menos eficiente,
	 pois, procura em todas as posições
	 do vetor, ordinalmente, até encontrar
         */
	(*count) ++;
	if(ini <= end){
	    if(vector[ini] == search) return true;
	    return normal_search(count, vector, search, ini+1, end);
            
	}
	return false;

}


int main()
{
	int vector[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int search = 7;
	
	short int *pointer_to_counter = &count;
	short int *pointer_to_counter_bin = &count_bin;

	std::cout << "NORMAL SEARCH" << std::endl;
	
	if(normal_search(pointer_to_counter, vector, search, 0, 8)){
		std::cout << "Encontrado" << std::endl <<
		 "Interações -> " << count << std::endl;
	}else{ std::cout << "Não encontrado" << std::endl << "Interações -> "  << count << std::endl;
	}


	std::cout << std::endl << "BINARY SEARCH" << std::endl;
	if(binary_search(pointer_to_counter_bin, vector, search, 0, 8)){
		std::cout << "Encontrado" << std::endl
		 << "Interações -> " << count_bin << std::endl;
	}else{ std::cout << "Não encontrado" << std::endl << "Interações -> "
		<< count << std::endl;
	}

	return 0;

}


