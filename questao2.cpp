/*-------------------------------------------------------------
 * UFRJ - Universidade Federal do Rio de Janeiro
 * IM   - Instituto de Matemática
 * DMA  - Departamento de Matemática Aplicada
 *
 *   MAE015 - Tópicos em Engenharia de Dados A
 *            "Estruturas de Dados (e seus algoritmos)"
 *
 *   Semana 01  : Introdução a linguagem C/C++
 *   Exemplo 002: Classes Aluno e Curso
 *
 *   Autor: Rhuan Justo (rhuan.justo@matematica.ufrj.br)
 *   Autor: Sebastiao Rodrigo (sebastiao@matematica.ufrj.br)
 *
 *--------------------------------------------------------------
*/
#include <iostream>
using namespace std;
typedef unsigned long int t_DRE;

struct t_Aluno
{
    t_DRE   DRE;
    string  Nome;
    double  CR;


    // Area de algoritmos: métodos do objeto
    void Cadastro(t_DRE pDRE, string pNome, double pCR = 0)
    {
        DRE = pDRE;
        Nome = pNome;
        CR = pCR;

    }
    void Print(void)
    {
        cout << "+-------------------+" << endl;
        cout << "| Registro de Aluno |" << endl;
        cout << "+-------------------+" << endl;
        cout << "| DRE : " << DRE << endl;
        cout << "| Nome: " << Nome << endl;
        cout << "| CR  : " << CR << endl;
        cout << "+-------------------+" << endl;
    }
    double operator +(t_Aluno B) // operador polimorfo
    {
        return (CR + B.CR);
    }

};

class t_Curso
{
    public:
    string  Codigo_Curso;
    string  Nome_Curso;
    //t_Aluno lista_de_alunos[500];
    double Nota;

    void Cadastro(string pCodigo_curso, string pNome_Curso , double pNota)
    {
        Codigo_Curso = pCodigo_curso;
        Nome_Curso = pNome_Curso;
        //lista_de_alunos[500] = pAluno;
        Nota = pNota;
    }
    void Print(void)
    {
        cout << "+----------------------------------+" << endl;
        cout << "| Registro do Curso |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "| Codigodo  Curso : " << Codigo_Curso << endl;
        cout << "| Nome do Curso: " << Nome_Curso << endl;
        //cout << "| Aluno: " << lista_de_alunos << endl;
        cout << "| Notano Mec: " << Nota << endl;
        cout << "+----------------------------------+" << endl;
    }
    double operator +(t_Curso B) // operador polimorfo
    {
        return (Nota + B.Nota);
    }

};

/*--------------------------------------------------------------
 * Area de criação de funções polimorfas: templates
 *--------------------------------------------------------------
*/
template <class T>
double Media(T a1, T a2)
{
    return (a1 + a2)/2;
}
template <class T>
double Media_Curso(T c1, T c2)
{
    return (c1 + c2)/2;
}

//---------------------------------------------------------------
int main()
{
    t_Aluno a1,a2;

    cout << "+-------------------------------------------- +" << endl;
    cout << "| Exemplo 002: Estruturas de Dados primitivas |" << endl;
    cout << "+-------------------------------------------- +" << endl << endl;

    a1.Cadastro(122001765,"Ze das Coves",7.8);
    a2.Cadastro(122002893,"Fulano de Tal",8.9);
    a1.Print();
    a2.Print();

    t_Curso c1,c2;
    c1.Cadastro("123456789","Matematica",4.5);
    c2.Cadastro("012345678","Matematica Aplicada",5.0);

    c1.Print();
    c2.Print();
    cout << "Media entre os cursos : " << Media_Curso(c1,c2) << endl;
    return 0;
}
