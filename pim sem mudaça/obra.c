#include <stdio.h>
#include <string.h>
#include "obra.h"

void inicializarObras(struct Obra obras[]) {
    strcpy(obras[0].titulo, "100 Anos da semana de arte moderna");
    strcpy(obras[0].descricao, "A obra '100 Anos da semana de arte moderna' comemora o centenario de um marco crucial na historia da arte brasileira, a Semana de Arte Moderna de 1922, que ocorreu em Sao Paulo. Esse evento representou uma ruptura com os padroes artisticos tradicionais e estabeleceu as bases para o movimento modernista no Brasil. A semana foi marcada por apresentacoes artisticas inovadoras, poesias revolucionarias e debates intensos sobre a identidade cultural do pais.");

    strcpy(obras[1].titulo, "150 Anos de Santos Dumont");
    strcpy(obras[1].descricao, "A obra '150 Anos de Santos Dumont' celebra o legado do renomado inventor e pioneiro da aviacao, Alberto Santos Dumont. Ele foi uma figura fundamental no desenvolvimento da aviacao e e reconhecido por seus projetos e experimentos com dirigiveis e avioes. Seus feitos incluem o primeiro voo de um veiculo mais pesado que o ar, o aviao 14 Bis, em Paris, em 1906, o que lhe rendeu reconhecimento internacional.");

    strcpy(obras[2].titulo, "Jogos Olimpicos de Paris 2024");
    strcpy(obras[2].descricao, "A obra 'Jogos Olimpicos de Paris 2024' e uma homenagem ao maior evento esportivo do mundo, que sera sediado em Paris. Os Jogos Olimpicos sao uma celebracao global do desempenho atletico e da uniao entre nacoes. Eles representam a competicao esportiva de elite, onde os melhores atletas do mundo se reunem para competir em varias modalidades esportivas, promovendo o espirito esportivo e a amizade entre os paises.");

    strcpy(obras[3].titulo, "Profissao de Dublador Ameacada pela IA");
    strcpy(obras[3].descricao, "A obra 'Profissao de Dublador Ameacada pela IA' aborda as transformacoes provocadas pela inteligencia artificial no campo da dublagem. Com avancos tecnologicos significativos, a capacidade das maquinas de replicar vozes humanas de maneira quase imperceptivel tem levantado questionamentos sobre o futuro dessa profissao. A discussao gira em torno dos desafios e oportunidades enfrentados pelos dubladores no contexto da evolucao tecnologica e das mudancas na industria do entretenimento.");
}

void exibirOpcoes(struct Obra obras[], int numObras) {
    printf("Obras Disponiveis:\n");

    for (int i = 0; i < numObras; i++) {
        printf("%d - %s\n", i + 1, obras[i].titulo);
    }

    printf("%d - Sair\n", numObras + 1);
}
