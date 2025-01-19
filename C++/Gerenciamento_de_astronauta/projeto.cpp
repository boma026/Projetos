#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Astronauta{
    protected:
    string cpf;
    string nome;
    int idade;
    bool disponivel;
    bool morto;
    vector <int> voos_finalizados_do_astronauta;

    public:
    Astronauta() : morto(false) {}
    void cadastrar_astronauta();
    void Setcpf(string _cpf);
    void Setnome(string _nome);
    void Setidade(int _idade); 
    void set_morto(bool _morto);
    void SetDisponibilidade(bool _disponivel);
    void set_voos_finalizados_do_astronauta(int _voos_finalizados_do_astronauta);
    vector <int> get_voos_finalizados_do_astronauta();
    bool get_morto();
    bool GetDisponibilidade();
    string Getcpf();
    string Getnome();
    int Getidade();
    void listar_mortos();
    static vector <Astronauta> lista_astronautas;    
};

vector <Astronauta> Astronauta :: lista_astronautas;

void Astronauta::SetDisponibilidade(bool _disponivel) {
    disponivel = _disponivel;
}

bool Astronauta :: GetDisponibilidade(){
    return disponivel;
}

void Astronauta :: Setcpf(string _cpf){
    cpf = _cpf;
}
    
void Astronauta :: Setnome(string _nome){
    nome = _nome;
}

void Astronauta :: Setidade(int _idade){
    idade = _idade;
}

void Astronauta :: set_morto(bool _morto){
    morto = _morto;
}

void Astronauta :: set_voos_finalizados_do_astronauta(int _voos_finalizados_do_astronauta){
    voos_finalizados_do_astronauta.push_back(_voos_finalizados_do_astronauta);
}

vector <int> Astronauta :: get_voos_finalizados_do_astronauta(){
    return voos_finalizados_do_astronauta;
}

bool Astronauta :: get_morto(){
    return morto;
}

string Astronauta :: Getcpf(){
    return cpf;
}

string Astronauta :: Getnome(){
    return nome;
}

int Astronauta :: Getidade(){
    return idade;
}

void Astronauta::cadastrar_astronauta() {       
    Astronauta NovoAstronauta;
    string cpf, nome;
    int idade;

    cout << "Digite o CPF (sem pontos e barras, 11 dígitos): " << endl;
    cin >> cpf;

    if (cpf.length() != 11) {
        cout << "Erro: O CPF deve ter exatamente 11 dígitos." << endl;
        return;
    }

    NovoAstronauta.Setcpf(cpf);

    cout << "Digite o nome do astronauta: " << endl;
    cin >> nome;
    NovoAstronauta.Setnome(nome);

    cout << "Digite a idade: " << endl;
    cin >> idade;
    NovoAstronauta.Setidade(idade);

    lista_astronautas.push_back(NovoAstronauta);
    cout << "Astronauta cadastrado com sucesso!" << endl;
}


void Astronauta::listar_mortos() {
    bool mortos_encontrados = false;

    for (size_t i = 0; i < Astronauta::lista_astronautas.size(); i++) {
        if (Astronauta::lista_astronautas[i].get_morto()) {
            mortos_encontrados = true;
            cout << "Nome: " << Astronauta::lista_astronautas[i].Getnome() << endl;
            cout << "CPF: " << Astronauta::lista_astronautas[i].Getcpf() << endl;
            cout << "Voos que participou: ";

            vector<int> voos_finalizados = Astronauta::lista_astronautas[i].get_voos_finalizados_do_astronauta();
            for (size_t j = 0; j < voos_finalizados.size(); j++) {
                cout << voos_finalizados[j];
                if (j != voos_finalizados.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

    if (!mortos_encontrados) {
        cout << "Nenhum astronauta morto encontrado." << endl;
    }
}


class Voo {
private:
    int codigo;
    vector<string> CPFdoAstronauta;
    vector<string> CPFdoAstronautaFinalizado; 
    bool planejamento;
    bool voo_finalizado;
    bool voo_em_curso;
    bool voo_explodido;

public:
    Voo() : planejamento(false), voo_finalizado(false), voo_em_curso(false), voo_explodido(false) {}

    void set_voo_finalizado(bool _codigo_voo_finalizado);
    void set_codigo(int _codigo);
    void set_CPFdoAstronauta(string _cpf);
    void set_planejamento(bool _planejamento);
    void set_voo_explodido(bool _voo_explodido);
    void set_voo_em_curso(bool _curso);
    bool get_voo_em_curso();
    bool get_voo_explodido();
    bool get_voo_finalizado();
    vector<string>& get_CPFdoAstronauta();
    vector<string>& get_CPFdoAstronautaFinalizado();
    bool get_planejamento();
    int get_codigo();
    void remover_astronauta();
    void lancar_voo();
    void cadastrar_voo();
    void finalizar_voo();
    void voo_cadastrar_astronauta();
    void explodir_voo();
    void listar_voo();
    vector<Voo> voo;
};

void Voo::set_voo_finalizado(bool _codigo_voo_finalizado) {
    voo_finalizado = _codigo_voo_finalizado;
}

void Voo::set_codigo(int _codigo) {
    codigo = _codigo;
}

void Voo::set_CPFdoAstronauta(string _cpf) {
    CPFdoAstronauta.push_back(_cpf);
}

void Voo::set_planejamento(bool _planejamento) {
    planejamento = _planejamento;
}

void Voo::set_voo_explodido(bool _voo_explodido) {
    voo_explodido = _voo_explodido;
}

void Voo::set_voo_em_curso(bool _curso) {
    voo_em_curso = _curso;
}

bool Voo::get_voo_em_curso() {
    return voo_em_curso;
}

bool Voo::get_voo_explodido() {
    return voo_explodido;
}

bool Voo::get_voo_finalizado() {
    return voo_finalizado;
}

vector<string>& Voo::get_CPFdoAstronauta() {
    return CPFdoAstronauta;
}

vector<string>& Voo::get_CPFdoAstronautaFinalizado() { 
    return CPFdoAstronautaFinalizado;
}

bool Voo::get_planejamento() {
    return planejamento;
}

int Voo::get_codigo() {
    return codigo;
}

void Voo::cadastrar_voo() {
    int codigo;
    cout << "Digite o código do voo (4 dígitos): " << endl;
    cin >> codigo;

    if (codigo < 1000 || codigo > 9999) {
        cout << "Erro: O código do voo deve ter exatamente 4 dígitos." << endl;
        return;
    }
    
    cout << "Voo adicionado com sucesso" << endl;

    Voo NovoVoo;
    NovoVoo.set_codigo(codigo);
    NovoVoo.set_planejamento(true);
    Voo::voo.push_back(NovoVoo);
}


void Voo::voo_cadastrar_astronauta() {
    string _cpf;
    int _codigo;

    cout << "Digite o código do voo do astronauta que deseja cadastrar (só em números): " << endl;
    cin >> _codigo;

    cout << "Digite o CPF do astronauta que deseja cadastrar: " << endl;
    cin >> _cpf;

    bool astronauta_encontrado = false;
    int indice_astronauta = -1;

    for (size_t i = 0; i < Astronauta::lista_astronautas.size(); i++) {
        if (Astronauta::lista_astronautas[i].Getcpf() == _cpf && Astronauta::lista_astronautas[i].GetDisponibilidade() == true) {
            astronauta_encontrado = true;
            indice_astronauta = i;
            break;
        }
    }

    if (!astronauta_encontrado) {
        cout << "Astronauta não encontrado ou não está disponível." << endl;
        return;
    }

    bool voo_encontrado = false;
    int indice_voo = -1;

    for (size_t i = 0; i < voo.size(); i++) {
        if (voo[i].get_codigo() == _codigo && voo[i].get_planejamento()) {
            voo_encontrado = true;
            indice_voo = i;
            break;
        }
    }

    if (!voo_encontrado) {
        cout << "Voo não encontrado ou não está no planejamento." << endl;
        return;
    }

    voo[indice_voo].set_CPFdoAstronauta(Astronauta::lista_astronautas[indice_astronauta].Getcpf());
    Astronauta::lista_astronautas[indice_astronauta].SetDisponibilidade(false);
    cout << "Astronauta adicionado com sucesso ao voo." << endl;
}

void Voo::remover_astronauta() {
    string _cpf;
    int _codigo;

    cout << "Digite o código do voo do qual deseja remover o astronauta (4 dígitos): " << endl;
    cin >> _codigo;

    cout << "Digite o CPF do astronauta que deseja remover: " << endl;
    cin >> _cpf;

    bool voo_encontrado = false;
    bool astronauta_encontrado = false;

    for (size_t i = 0; i < Voo::voo.size(); i++) {
        if (Voo::voo[i].get_codigo() == _codigo) {
            voo_encontrado = true;
            
            if (!Voo::voo[i].get_planejamento()) {
                cout << "Erro: O voo não está mais em estado de planejamento." << endl;
                return;
            }

            vector<string>& astronautas = Voo::voo[i].get_CPFdoAstronauta();
            vector<string>::iterator it = std::find(astronautas.begin(), astronautas.end(), _cpf);

            if (it != astronautas.end()) {
                astronautas.erase(it);
                astronauta_encontrado = true;
                break;
            }
        }
    }

    if (!voo_encontrado) {
        cout << "Erro: Voo não encontrado com o código especificado." << endl;
        return;
    }

    if (!astronauta_encontrado) {
        cout << "Erro: Astronauta não encontrado no voo especificado." << endl;
        return;
    }

    for (size_t i = 0; i < Astronauta::lista_astronautas.size(); i++) {
        if (Astronauta::lista_astronautas[i].Getcpf() == _cpf) {
            Astronauta::lista_astronautas[i].SetDisponibilidade(true);
            break;
        }
    }

    cout << "Astronauta removido com sucesso do voo." << endl;
}




void Voo::lancar_voo() {
    int codigo;
    cout << "Digite o código do voo (4 dígitos): " << endl;
    cin >> codigo;

    for (size_t i = 0; i < Voo::voo.size(); i++) {
        if (Voo::voo[i].get_codigo() == codigo) {
            if (!Voo::voo[i].get_planejamento()) {
                cout << "Erro: O voo não está mais em planejamento." << endl;
                return;
            }

            if (Voo::voo[i].get_CPFdoAstronauta().empty()) {
                cout << "Erro: O voo não pode ser lançado sem astronautas." << endl;
                return;
            }

            Voo::voo[i].set_voo_em_curso(true);
            Voo::voo[i].set_planejamento(false);
            cout << "Voo lançado com sucesso!" << endl;
            return;
        }
    }

    cout << "Erro: Voo não encontrado com o código especificado." << endl;
}




void Voo :: finalizar_voo(){
    int codigo;
    cout << "Digite o código do voo (4 dígitos): " << endl;
    cin >> codigo;

    for (size_t i = 0; i < Voo::voo.size(); i++) {
        if (Voo::voo[i].get_codigo() == codigo && Voo::voo[i].get_voo_em_curso() == true) {
            Voo::voo[i].set_voo_finalizado(true);
            Voo::voo[i].set_voo_em_curso(false);

            Voo::voo[i].CPFdoAstronautaFinalizado = Voo::voo[i].CPFdoAstronauta;

            for (size_t j = 0; j < Astronauta::lista_astronautas.size(); j++) {
                for (size_t k = 0; k < Voo::voo[i].get_CPFdoAstronauta().size(); k++) {
                    if (Astronauta::lista_astronautas[j].Getcpf() == Voo::voo[i].get_CPFdoAstronauta()[k]) {
                        Astronauta::lista_astronautas[j].SetDisponibilidade(true);
                        Astronauta::lista_astronautas[j].set_voos_finalizados_do_astronauta(Voo::voo[i].get_codigo());
                    }
                }
            }

            Voo::voo[i].CPFdoAstronauta.clear();
            cout << "Voo finalizado com sucesso!" << endl;
            return;
        }
    }
    cout << "Voo não encontrado ou não está em curso." << endl;
}

void Voo :: explodir_voo(){
    int codigo;
    cout << "Digite o código do voo (4 dígitos): " << endl;
    cin >> codigo;

    for (size_t i = 0; i < Voo::voo.size(); i++) {
        if (Voo::voo[i].get_codigo() == codigo && Voo::voo[i].get_voo_em_curso() == true) {
            Voo::voo[i].set_voo_explodido(true);
            Voo::voo[i].set_voo_em_curso(false);
           
            Voo::voo[i].CPFdoAstronautaFinalizado = Voo::voo[i].CPFdoAstronauta;

            for (size_t j = 0; j < Astronauta::lista_astronautas.size(); j++) {
                for (size_t k = 0; k < Voo::voo[i].get_CPFdoAstronauta().size(); k++) {
                    if (Astronauta::lista_astronautas[j].Getcpf() == Voo::voo[i].get_CPFdoAstronauta()[k]) {
                        Astronauta::lista_astronautas[j].set_morto(true);
                    }
                }
            }

            Voo::voo[i].CPFdoAstronauta.clear();
            cout << "Voo explodido e finalizado!" << endl;
            return;
        }
    }
    cout << "Voo não encontrado ou não está em curso." << endl;
}

void Voo :: listar_voo(){
    for (size_t i = 0; i < Voo::voo.size(); i++) {

        if (voo[i].get_planejamento() == true) {
            cout << voo[i].get_codigo() << " (Planejamento)" << endl;
            cout << "Astronautas: ";
            vector<string> astronautas = voo[i].get_CPFdoAstronauta();

            for (size_t j = 0; j < astronautas.size(); j++) {
                cout << astronautas[j] << " ";
            }

            cout << endl;

        } 
        
        else if (Voo::voo[i].get_voo_em_curso() == true) {
            cout << Voo::voo[i].get_codigo() << " (Em curso) " << endl;
            cout << "Astronautas: ";
            vector<string> astronautas = voo[i].get_CPFdoAstronauta();

            for (size_t j = 0; j < astronautas.size(); j++) {
                cout << astronautas[j] << " ";
            }

            cout << endl;
        }
            
        else if (Voo::voo[i].get_voo_finalizado() == true) {
            cout << Voo::voo[i].get_codigo() << " (Finalizado com sucesso) " << endl;
            cout << "Astronautas: ";
            vector<string> astronautas = voo[i].get_CPFdoAstronautaFinalizado();

            for (size_t j = 0; j < astronautas.size(); j++) {
                cout << astronautas[j] << " ";
            }

            cout << endl;
        }

        else if (Voo::voo[i].get_voo_explodido() == true) {
            cout << Voo::voo[i].get_codigo() << " (Finalizado explodido) " << endl;
            cout << "Astronautas: ";
            vector<string> astronautas = voo[i].get_CPFdoAstronautaFinalizado();
            
            for (size_t j = 0; j < astronautas.size(); j++) {
                cout << astronautas[j] << " ";
            }

            cout << endl;
        }
    }
}


void listar_astronautas_disponiveis() {
    cout << "Astronautas disponíveis:" << endl;
    for (size_t i = 0; i < Astronauta::lista_astronautas.size(); i++) {
        
        if (Astronauta::lista_astronautas[i].GetDisponibilidade()) {
            cout << "Nome: " << Astronauta::lista_astronautas[i].Getnome() << ", CPF: " << Astronauta::lista_astronautas[i].Getcpf() << endl;
        }
    }
}

void mostralista(){
    cout << "1. Cadastrar astronauta" << endl;
    cout << "2. Cadastrar voo" << endl;
    cout << "3. Adicionar astronauta em voo" << endl;
    cout << "4. Remover astronauta de voo" << endl;
    cout << "5. Lançar um voo" << endl;
    cout << "6. Explodir voo" << endl;
    cout << "7. Finalizar um voo (com sucesso)" << endl;
    cout << "8. Listar todos os voos" << endl;
    cout << "9. Listar todos os astronautas mortos" << endl;
    cout << "10. Listar astronautas disponíveis" << endl;
    cout << "0. Sair do programa" << endl;
}

int main(){

    Astronauta astronauta;
    Voo voo;
    int opcao;

    do {
        cout << endl << "Digite o que você deseja fazer: " << endl << endl;
        mostralista();
        cin >> opcao;

        switch (opcao) {
        case 1:

            astronauta.cadastrar_astronauta();
            break;

        case 2:
            voo.cadastrar_voo();
            break;

        case 3:
            voo.voo_cadastrar_astronauta();
            break;

        case 4:

            voo.remover_astronauta();
            break;

        case 5:

            voo.lancar_voo();
            break;
            
        case 6:

            voo.explodir_voo();
            break;

        case 7:

            voo.finalizar_voo();
            break;

        case 8:

            voo.listar_voo();
            break;

        case 9:

            astronauta.listar_mortos();
            break;

        case 10:

            listar_astronautas_disponiveis();
            break;

        default:
            break;

        }
    
    } while (opcao != 0);

    return 0;
}