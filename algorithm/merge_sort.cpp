#include <iostream>
#include "merge_sort.hpp"


void merge_sort(int *vector, int *aux, int begin, int end, int *p)
{
	/*
    Ordenação por junção consiste
    em dividir para conquistar.
    Utiliza recursividade, o que, por sua vez,
    implica em um maior consumo de memória.
    Por isso, não é tão eficiente para 
    containers grandes e muito desordenados
    O(nlogn)
	*/


	if(end - begin < 2) return;

	// calcula complexidade
	(*p)++;

		
	// divisão
	int half = ((end + begin) / 2);

	// recursividade
	merge_sort(vector, aux, begin, half, p);
	merge_sort(vector, aux, half, end, p);

	// junção,pós divisão recursiva
	merge(vector, aux, begin, half, end, end);
	
}


void merge_sort(int *vector, int length, int *count)
{
	int aux[length];
	merge_sort(vector,aux, 0, 6,count);
}


void merge(int *vector, int *aux, int begin, int half, int end, int length)
{	
	int left_part = begin;
	int right_part = half;

	for(int i = begin; i < end; i++)
	{
		//compara se o item do lado esquerdo é menor que o do lado direito:
		if((left_part < half) and ((right_part >= end) or (vector[left_part] < vector[right_part]))){
			aux[i] = vector[left_part];
			++left_part;
		}else{
			aux[i] = vector[right_part];
			++right_part;
		}
	}
	
	// como a funcao é void e a passagem de vetores dá-se por referência, é necessário preencher o vetor novamente
	for(int i = begin; i < end;++i){
		vector[i] = aux[i];
	}

}


void print(int *vector, int length)
{
	std::cout << std::endl;
	for(int i = 0; i < length; i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}


int main()
{
	int count = 0;           // mede o num de interações
	int *pointer = &count;   // aponta para o endereço de count

	int vector[] = {5, 3, 4, 2, 1};
    

	std::cout << "Not ordered";
	print(vector, 5);

	
	merge_sort(vector, 5, pointer);


	std::cout << std::endl << "Ordered";
	print(vector, 5);

	// complexidade
	std::cout << std::endl << "Quantidade de interações: " << count << std::endl;
	
	return 0;
}
