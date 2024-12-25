//HERE I do Matrix mul of one matrix

#include <iostream>
using namespace std;

#define N	2

int matrix[N][N];
int result[N][N];

void matrix_mul(void);

int main(void){
	int i, j;
	int c = 0;

	for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
			matrix[i][j] = (c + 1) * 1;
			++c;
		}
	}

	for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
				cout<<"matrix["<<i<<"]"<<"["<<j<<"]:"<<matrix[i][j]<<endl;
		}
	}

	matrix_mul();
	cout<<"The matrix mul is: "<<endl;

	for(i = 0; i < N; ++i){
		for(j = 0; j < N; ++j){
				cout<<"result["<<i<<"]"<<"["<<j<<"]:"<<result[i][j]<<endl;
		}
	}

}

void matrix_mul(void){
	result[0][0] = matrix[0][0] * matrix[0][0] + matrix[0][1] * matrix[1][0];
	result[0][1] = matrix[0][0] * matrix[0][1] + matrix[0][1] * matrix[1][1];
	result[1][0] = matrix[1][0] * matrix[0][0] + matrix[1][1] * matrix[1][0];
	result[1][1] = matrix[1][0] * matrix[0][1] + matrix[1][1] * matrix[1][1];
}
