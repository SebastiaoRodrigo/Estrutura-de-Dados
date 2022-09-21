/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 01  : Introdução a linguagem C/C++
 *   Exemplo 001: Menu de Opções simples
 *
 *   Autor: Rhuan Justo (rhuan.justo@matematica.ufrj.br)
 *   Autor: Sebastiao Rodrigo (sebastiao@matematica.ufrj.br)
 *
 *--------------------------------------------------------------
*/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include <locale.h>

using namespace std;

const int n = 100;
void Apresenta_texto_menu(void)
{
    cout << "+----------------------------------+" << endl;
    cout << "\t1 - Multiplicação por escalar" << endl;
    cout << "\t2 - Soma Vetorial" << endl;
    cout << "\t3 - Combinação Linear" << endl;
    cout << "\t4 - Produto escalar" << endl;
    cout << "\t5 - Norma 2 Vetorial" << endl;
    cout << "\t6 - Verificar dependência linear" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "+ aperte a tecla 's' para sair" << endl;
    cout << "+----------------------------------+" << endl;
}


double* multiplica_escalar(double param[n], double c)
{
    for(int i=0; i < n ; i++)
    {
        param[i] = param[i]*c;
    }
    return param;

}

void Executa_opcao_1(void)
{
    double vec[n];
    double escalar;
    double* vec_resp;
    cout << "Insira (posição por posição) o array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec[i];
    }
    cout << "Insira o escalar pelo qual você quer multiplicar o vetor: " << endl;
    cin >> escalar;
    vec_resp = multiplica_escalar(vec,escalar);
    cout<<"O vetor resposta é: ";
	for(int i=0 ; i<n; i++)
		cout<<vec_resp[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
}

double* soma_vetorial(double param1[n], double param2[n])
{
    for(int i=0; i < n ; i++)
    {
        param1[i] += param2[i];
    }
    return param1;

}

void Executa_opcao_2(void)
{
    double vec1[n];
    double vec2[n];
    double* vec_resp;
    cout << "Insira (posição por posição) o primeiro array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec1[i];
    }
    cout << "Insira (posição por posição) o segundo array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec2[i];
    }
    vec_resp = soma_vetorial(vec1,vec2);
    cout<<"O vetor resposta é: ";
	for(int i=0 ; i<n; i++)
		cout<<vec_resp[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
}

double* comb_linear(double vec_comb[n], double param1[n], double param2[n], double a, double b)
{
    for(int i=0; i < n ; i++)
    {
        vec_comb[i] = param1[i]*a + param2[i]*b;
    }
    return vec_comb;

}

void Executa_opcao_3(void)
{
    double vec_comb[n];
    double vec1[n];
    double vec2[n];
    double a;
    double b;
    double* vec_resp;
    cout << "Insira (posição por posição) o primeiro array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec1[i];
    }
    cout << "Insira (posição por posição) o segundo array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec2[i];
    }
    cout << "Insira o escalar que multiplica o primeiro vetor: " << endl;
    cin >> a;
    cout << "Insira o escalar que multiplica o segundo vetor: " << endl;
    cin >> b;
    vec_resp = comb_linear(vec_comb,vec1,vec2,a,b);
    cout<<"O vetor resposta é: ";
	for(int i=0 ; i<n; i++)
		cout<<vec_resp[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
}

double prod_escalar(double param1[n], double param2[n])
{
    double soma;
    for(int i=0; i < n ; i++)
    {
        soma += param1[i]*param2[i];
    }
    return soma;

}

void Executa_opcao_4(void)
{
    double vec1[n];
    double vec2[n];
    double prod_esc;
    cout << "Insira (posição por posição) o primeiro array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec1[i];
    }
    cout << "Insira (posição por posição) o segundo array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec2[i];
    }
    prod_esc = prod_escalar(vec1,vec2);
    cout<<"O produto escalar entre os vetores é: " << prod_esc << endl;
}

double norma_vetorial(double param[n])
{
    double soma = 0;
    for(int i=0; i < n ; i++)
    {
        soma += pow(param[i],2);
    }
    return sqrt(soma);

}

void Executa_opcao_5(void)
{
    double vec[n];
    double norma_vec;
    cout << "Insira (posição por posição) o array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec[i];
    }
    norma_vec = norma_vetorial(vec);
    cout<<"A 2-norma do vetor é: " << norma_vec << endl;
}

int checa_dependencia(double param1[n], double param2[n])
{
    double a1 = param1[0];
    double b1 = param2[0];
    double c;
    for(int i=0; i < n ; i++)
    {
        c = param2[i] - param1[i]*(b1/a1);
        if (fabs(c) > 1e-8)
        {
            return 1;
        }
    }
    return 0;

}

void Executa_opcao_6(void)
{
    double vec1[n];
    double vec2[n];
    unsigned char a;
    cout << "Insira (posição por posição) o primeiro array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec1[i];
    }
    cout << "Insira (posição por posição) o segundo array de tamanho " << n << endl;
    for(int i=0; i < n; i++)
    {
        cin >> vec2[i];
    }
    a = checa_dependencia(vec1,vec2);
    if(a == 1)
    {
        cout << "Os vetores são linearmente independentes" << endl;
    }
    else
    {
        cout << "Os vetores são linearmente dependentes" << endl;
    }

}
void Menu(void)
{
    char opcao_escolhida;

    do {
        Apresenta_texto_menu();
        cin >> opcao_escolhida;
        switch (opcao_escolhida) {
            case '1' : Executa_opcao_1(); break;
            case '2' : Executa_opcao_2(); break;
            case '3' : Executa_opcao_3(); break;
            case '4' : Executa_opcao_4(); break;
            case '5' : Executa_opcao_5(); break;
            case '6' : Executa_opcao_6(); break;
            case 's' : break;
            default  : cout << "Opcao invalida, tente novamente, ou 's' para sair" << endl;
        }
    } while (opcao_escolhida != 's');
}

int main()
{
    setlocale(LC_ALL,"");
    cout << "Menu da Calculadora Vetorial " << endl;
    Menu();
    return 0;
}
