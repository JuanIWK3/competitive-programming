#include <iostream>
#include "burble_sort.hpp"


int min(int *vector, int begin, int length)
{
	// identifica qual número é o menor da posicao do vetor
	int less = vector[begin];
	for (int i = begin; i < length; i++)
	{
		if (less >= vector[i])
			less = vector[i];
	}
	return less;
}


void burble(int min, int current, int *vector, int position, int length, int *p)
{
	// pega os menores valor e o atual e trocam suas respectivas posicoes
	int posi = 0;
	for (int i = 0; i < length; i++) {
		if (vector[i] == min) break;
		posi++;
	}
	(*p)++;
	int aux = vector[position];
	vector[position] = min;
	vector[posi] = aux;
}


void burble_sort(int *vector, int length, int *count)
{
	/*
	Burblesort é um algoritmo de ordenação
	simples que consiste em fazer "flutuar"
	o maior número para a posição mais ao topo
	do vetor
	Sua complexidade não é muito performática,
	é O(n²)
	*/
	for (int i = 0; i < length; i++) {
		burble(min(vector, i, length), i, vector, i, length, count);
	}
}


void print(int* vector, int length)
{
	// exibe elementos do vetor
	for (int i = 0; i < length; i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

int main()
{
	int vector[] = { 70, 90, 1, 3, 0, 100, 2 };
	int count = 0;
	int* pointer = &count;   // analisa complexidade

	std::cout << "Not ordered vector" << std::endl;
	print(vector, 7);

	std::cout << "Ordered vector" << std::endl;
	burble_sort(vector, 7, pointer);
	print(vector, 7);
	std::cout << std::endl << "Iteracoes: " << count << std::endl;
	return EXIT_SUCCESS;
}