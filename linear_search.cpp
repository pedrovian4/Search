#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <locale.h>




using namespace std;


 

//classe para armazenamento de dados heterogeneos 
class Linear_Search
{

public:


        int jogos=0; 

        //atributos do database
        string id, mandante_placar, visitante_placar, estado_vencedor;
        string rodada,horario,dia,mandante,visitante,data,vencedor, arena, estado_mandante, estado_visitante;



    //VARIÁVEL DE CONTROLE 
    int i=0;


    //VARIÁVEL DE LIMPEZA DE TELA 
    void clear_(){
        
        #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
            system("clear");
        #endif

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");  
        #endif 
        
        };


    //VARIÁVEL DE INPUT DO TIME
    string team_usr;




//FUNÇÃO PARA FAZER STRING SEPARADA JUNTA
  string get_together(string data){ 
    
      data.erase(remove(data.begin(), data.end(),' '),data.end());

    return data;};
    
  


  


    //DECLARAÇÃO DE VARIAVEL DE ARQUIVO     
    ifstream myfile;  
    //LISTA QUE VAI ARMAZENAR DINAMICAMENTE OS DADOS DO TIME 
    vector <string> dados;
    //ITERATOR PARA ADMINSTRAÇÃO DE MEMÓRIA DO VECTOR DADOS
    vector<string>::iterator it;

    //METODO DE LIMPEZA DE LISTA 
    void list_clear(){
        dados.clear();
    };


    //VARIÁVEL DE CONCATENAÇÃO 
    string line;
    //FUNÇÃO DE CONVERSÃO DE LOWERCASE PRA UPPERCASE EM DESENVOLVIMENTO
    void convert(string team_usr,string visitante, string mandante );
    //VERIFICADOR DE ABERTURA CORRETA DE ARQUIVO
    bool open();
    //FUNÇÃO VOID PARA FAZER A PESQUISA LINEAR OS DADOS PESQUISADOS 
    void Search(string team);
    //FUNÇÃO DE IMPRESSÃO
    void print(){
        for(it= dados.begin(); it!= dados.end(); it++){
            cout<<*it<<endl<<endl;} 
            list_clear();
            };

    
};


void Linear_Search::convert(string team_usr, string visitante, string mandante ){
   
    for_each(this->visitante.begin(), this->visitante.end(), [](char & a){
    a = ::tolower(a);
});
    for_each(this->mandante.begin(), this->mandante.end(), [](char & c){
    c = ::tolower(c);
});
    for_each(this->team_usr.begin(), this->team_usr.end(), [](char & b){
    b = ::tolower(b);
});


}



bool Linear_Search::open()
{
   //abertura de arquivo
    myfile.open("AWPr_range.csv");

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
            getline(myfile,id,',');
            getline(myfile,rodada,','); 
            getline(myfile,data,',');
            getline(myfile,horario,',');
            getline(myfile, dia, ','); 
            getline(myfile, mandante,',');
            getline(myfile,visitante, ',');
            getline(myfile,vencedor,',');
            getline(myfile, arena,',');
            getline(myfile,mandante_placar,',');
            getline(myfile, visitante_placar,',');
            getline(myfile,estado_mandante,',');
            getline(myfile,estado_visitante,',');
            getline(myfile,estado_vencedor);


            convert(team,visitante,mandante);
            
            if( get_together(team) == get_together (mandante) ||  get_together(team) == get_together(visitante)){
                line = "\nrodada: " + rodada + "\nData: " + data + "\nHorário: " + horario + "\nDia: " + dia + "\nMandante: " + mandante + "\nVisitante: " + visitante + "\nVencedor: " + vencedor +"\nArena: " + arena + "\nPlacar do mandante: " + mandante_placar + "\nPlacar do Visitante: "+ visitante_placar + "\nMandante de estado: "+ estado_mandante + "\nVisitante de estado: " + estado_visitante + "\nVencedor de estado: " + estado_vencedor;
                dados.push_back(line);

                jogos++;

            }
    
    }

    if(dados.empty()){
        line= "!!!!!!!!!!!!TIME NÃO ENCONTRADO NO BANCO DE DADOS!!!!!!!!";
        dados.push_back(line); }
         
           
    
    }

    print();
    }



int main()
{

    setlocale(LC_ALL, "portuguese");

    Linear_Search ls; 


    while (ls.i!=2)
    {
        cout<<"\n========== PESQUISA LINEAR =========\n";
        cout<<"\n\tDigite o time para pesquisar:\n";
        //PEGAR STRING COM ESPAÇO
        getline(cin, ls.team_usr);
        ls.Search(ls.team_usr);
        cout<<"\n\t1-Nova pesquisa\t"<<"\t2-Fechar\t\n";
        cin>>ls.i;
        if(ls.i==1){
            ls.clear_();
            //REABERTURA DE ARQUIVO 
            ls.open();          
        }
         //FEACHAMENTO DE ARQUIVO    
        else 
            ls.myfile.close();
    
     }
    cout<<"\n\nQuantidade de jogos: "<<ls.jogos<<endl;
 
    return 0;
}