/////José Viecili//////
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int TAMANHO_VETOR = 50000;

// Função para gerar um número inteiro randômico entre min e max
int randomInt(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Função para criar o vetor randômico e salvar em um arquivo de texto
void criarVetorAleatorio(const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo.c_str()); // Convertendo para const char* com c_str()

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    srand(static_cast<unsigned>(time(0))); // Inicializa a semente do gerador randômico

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        int valor = randomInt(1, 1000000); // Números randômicos entre 1 e 1.000.000
        arquivo << valor << endl;
    }

    arquivo.close();
}

// Função para exibir o vetor na saída padrão
void exibirVetor(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo.c_str()); // Convertendo para const char* com c_str()

    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    int valor;
    while (arquivo >> valor) {
        cout << valor << " ";
    }

    arquivo.close();
}

int main() {
    string nomeArquivo = "vetor_randomico.txt";

    // Medir o tempo de execução
    clock_t inicio = clock();
    criarVetorAleatorio(nomeArquivo);
    clock_t fim = clock();

    cout << "Vetor randômico criado e salvo no arquivo: " << nomeArquivo << endl;
    cout << "Tempo de execução: " << (static_cast<double>(fim - inicio) / CLOCKS_PER_SEC) << " segundos" << endl;

    cout << "Exibindo o vetor:" << endl;
    exibirVetor(nomeArquivo);

}

