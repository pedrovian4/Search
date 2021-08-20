#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


 

//classe para armazenamento de dados heterogeneos 
class Linear_Search
{

public:

        //atributos do database

        string id, mandante_placar, visitante_placar, estado_vencedor;
        string rodada,horario,dia,mandante,visitante,data,vencedor, arena, estado_mandante, estado_visitante;


    //DECLARAÇÃO DE VARIAVEL DE ARQUIVO     
    ifstream myfile;  
    //LISTA QUE VAI ARMAZENAR DINAMICAMENTE OS DADOS DO TIME 
    vector <string> dados;
    //VARIÁVEL DE CONCATENAÇÃO 
    string line;
    //FUNÇÃO DE CONVERSÃO DE LOWERCASE PRA UPPERCASE EM DESENVOLVIMENTO
    void convert();
    //VERIFICADOR DE ABERTURA CORRETA DE ARQUIVO
    bool open();
    //FUNÇÃO VOID PARA FAZER A PESQUISA LINEAR OS DADOS PESQUISADOS 
    void Search(string team);
    //FUNÇÃO DE IMPRESSÃO
    void print(){
        for(vector<string>::iterator it= dados.begin(); it!= dados.end(); it++)
            cout<<*it<<endl<<endl; };
};





bool Linear_Search::open()
{
   //abertura de arquivo
    myfile.open("campeonato-brasileiro-full.csv");

    //verificação de abertura
    if (myfile.is_open())
        return true;

    return false;
}







void::Linear_Search::Search(string team){
    if(open()){

        //loop para ler todo o arquivo
        while (myfile.good()){
            //funções para a input de cada atributo desfragmentado em variaveis dentro da classe 
            // getline parametros: variável de arquivo, variavel de input, limitação de input 
            getline(myfile,id,';');
            getline(myfile,rodada,';'); 
            getline(myfile,data,';');
            getline(myfile,horario,';');
            getline(myfile, dia, ';'); 
            getline(myfile, mandante,';');
            getline(myfile,visitante, ';');
            getline(myfile,vencedor,';');
            getline(myfile, arena,';');
            getline(myfile,mandante_placar,';');
            getline(myfile, visitante_placar,';');
            getline(myfile,estado_mandante,';');
            getline(myfile,estado_visitante, ';');
            getline(myfile,estado_vencedor);

            if(team== mandante || team== visitante){
                line = "id:  "+ id + "\nrodada: " + rodada + "\nData: " + data + "\nHorário: " + horario + "\nDia: " + dia + "\nMandante: " + mandante + "\nVisitante: " + visitante + "\nVencedor: " + vencedor +"\nArena: " + arena + "\nPlacar do mandante: " + mandante_placar + "\nPlacar do Visitante: "+ visitante_placar + "\nMandante de estado: "+ estado_mandante + "\nVisitante de estado: " + estado_visitante + "\nVencedor de estado: " + estado_vencedor;
                dados.push_back(line);

            }
    }

    if(dados.empty()){
        line= "!!!!!!!!!!!!TIME NÃO ENCONTRADO NO BANCO DE DADOS!!!!!!!!";
        dados.push_back(line); }
         
           
    
    }
    }



int main()
{
    Linear_Search l; 
    l.Search("jumento"); 
    l.print();



    return 0;
}