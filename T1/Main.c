#include <stdio.h>
#include <string.h>
#include "readFile.h"

int readFile(char nomeLog[20]) {
    FILE *file;
    int id;
    char nome_logico[20];
    char nome_fisico[20];
    
    file = fopen("table.dic", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo table.dic\n");
        return -1;
    }

    while (fscanf(file, "%d %20s %20s", &id, nome_logico, nome_fisico) != EOF) {
        if (strncmp(nomeLog, nome_logico, 20) == 0) {
            printf("Nome lógico encontrado: %s\n", nome_logico);
            printf("Nome físico correspondente: %s\n", nome_fisico);

            FILE *f = fopen(nome_fisico, "r");
            if (f == NULL) {
                printf("Erro ao abrir o arquivo %s\n", nome_fisico);
                fclose(file);
                return -1;
            }

            printf("Arquivo %s aberto com sucesso.\n", nome_fisico);
            fclose(f);
            
            FILE *attFile = fopen("att.dic", "r");
            if (attFile == NULL) {
                printf("Erro ao abrir o arquivo att.dic\n");
                fclose(file);
                return -1;
            }
            
            atributo att;
            while (fscanf(attFile, "%d %20s %c %c %d", &att.id_arquivo_att, att.nome_att, &att.tipo, &att.opcional, &att.tamanho) != EOF) {
                if (att.id_arquivo_att == id) {
                    printf("Atributo: %s, Tipo: %c, Opcional: %c, Tamanho: %d\n", att.nome_att, att.tipo, att.opcional, att.tamanho);
                }
            }

            fclose(attFile);
            fclose(file);
            return 0;
        }
    }

    printf("Nome lógico %s não encontrado em table.dic\n", nomeLog);
    fclose(file);
    return -1;
}
