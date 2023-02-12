#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>

enum { SIZE_MATRIX = 4,
       ARBITRARY_VALUE = 0,
};

const double τ =  1e-1;
const double ε = 1e-1;

__attribute__((unused)) void PrintMatrix(std::vector<double> matrix) {
    for(int i = 0; i < SIZE_MATRIX; ++i) {
        for(int j = 0; j < SIZE_MATRIX; ++j) {
            std::cout << matrix[i* SIZE_MATRIX + j];
        }
        std::cout << std::endl;
    }
}

void PrintVector(std::vector<double> vector) {
    for(int j = 0; j < SIZE_MATRIX; ++j) {
        std::cout << (double)vector[j] << " ";
    }
    printf("\n");
}

std::vector<double> GenerateSolutionVector() {
    std::vector<double> matrix;
    matrix.resize(SIZE_MATRIX, ARBITRARY_VALUE);
    return matrix;
}


std::vector<double> GenerateVectorRightParts() {
    std::vector<double> matrix;
    matrix.resize(SIZE_MATRIX, SIZE_MATRIX+1);
    return matrix;
}


std::vector<double> MultVectors(const std::vector<double>& vector1, const std::vector<double>& vector2, int cntProcess, int rang) {
    std::vector<double> vector;
    vector.resize(SIZE_MATRIX, ARBITRARY_VALUE);
    for(int i = 0; i < SIZE_MATRIX / cntProcess; ++i) {
        for  (int j = 0; j < SIZE_MATRIX; ++j) {
            vector[j] = vector1[j+i*SIZE_MATRIX] * vector2[j];
        }
    }
    return vector;
}

std::vector<double> MinusVectors(const std::vector<double>& vector1, const std::vector<double>& vector2) {
    std::vector<double> vector;
    vector.resize(SIZE_MATRIX);
    for(int i = 0; i < SIZE_MATRIX; ++i) {
        vector[i] = vector1[i] - vector2[i];
    }
    return vector;

}

std::vector<double> GeneratePartMatrix(const int& rank, const int& countProcess) {
    std::vector<double> matrix;
    int partSizeMatrix = SIZE_MATRIX * (SIZE_MATRIX / countProcess);

    matrix.resize(partSizeMatrix, 1.0);

    for(int  i = 0, offset = 0; i < SIZE_MATRIX / countProcess; ++i) {
        matrix[offset + rank+i] = 2.0;
        offset += SIZE_MATRIX;
    }
    return matrix;
}

std::vector<double> MultVectorByConstant(std::vector<double> vector, double constant) {
    for(int i = 0; i < SIZE_MATRIX; ++i) {
        vector[i] *= constant;
    }
    return vector;
}
double FormingFirstNorm(const std::vector<double>& vector) {
    double sumVector = 0;
    for(int i = 0; i < SIZE_MATRIX; ++i) {
        sumVector += vector[i]*vector[i];
    }
    return sqrt(sumVector);
}

double NormCalculation(const std::vector<double>& multAx,
                       const std::vector<double>& b) {
    std::vector<double> vector;
    return FormingFirstNorm(MinusVectors(multAx, b)) / FormingFirstNorm(b);
}

bool IsFirstNormMoreEpsilon(const std::vector<double>& multAx,
                            const std::vector<double>& b) {
    std::cout << "norma: " <<  NormCalculation(multAx, b) << "\n";

    return !(NormCalculation(multAx, b) < ε);
}

std::vector<double> IterativeMethod(int rank, int cntProcess) {
    std::vector<double> A = GeneratePartMatrix(rank, cntProcess);
    std::vector<double> b = GenerateVectorRightParts();
    std::vector<double> x = GenerateSolutionVector();
    MPI_Barrier(MPI_COMM_WORLD);
    PrintVector(b);
    std::vector<double> vectorResult, multAx;
//   do {
         multAx = MultVectors(A, x, cntProcess, rank);

         MPI_Barrier(MPI_COMM_WORLD);

         vectorResult = MinusVectors(x, MultVectorByConstant(MinusVectors(multAx, b), τ));
         std::copy(vectorResult.begin(), vectorResult.end(),x.begin());
//   } while(IsFirstNormMoreEpsilon(multAx, b));

    PrintVector(vectorResult);
    return A;
}

//x^n+1 = x^n – τ(Ax^n – b)

int main(int argc, char* argv[]){
    //if(argc != 1) return 1;

    MPI_Init(&argc, &argv);
    int rank = 0, cntProcess = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &cntProcess);

    std::vector<double> vector = IterativeMethod(rank, cntProcess);
    //double*vector = new double[SIZE_MATRIX];
    if(rank == 0) {
        MPI_Send(&vector, SIZE_MATRIX, MPI_DOUBLE, 1, 24, MPI_COMM_WORLD);
    } if(rank == 1) {
        //std::vector<double> vector2;
         double *vector2 = new double[SIZE_MATRIX];
         //vector2.resize(vector.size());
         MPI_Recv(vector2, SIZE_MATRIX, MPI_DOUBLE, 0, 24, MPI_COMM_WORLD,  MPI_STATUS_IGNORE);
         //PrintVector(vector2);
    }
    // MPI_Allreduce(&vector, &norm_Axn_minus_b, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

//    MPI_Finalize();
    MPI_Finalize();
//    printf("result: \n");
//    PrintVector(vector);

    //PrintMatrix(vector);
    return 0;
}