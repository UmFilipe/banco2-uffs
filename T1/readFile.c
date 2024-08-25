#include <stdio.h>
#include <string.h>
#include "readFile.h"

void readPhysicalFile(const char* filename, AttributeEntry* attributes, int attributeCount) {
    FILE* file = fopen(filename, "rb"); 
    if (!file) {
        printf("Erro ao abrir o arquivo físico %s\n", filename);
        return;
    }

    for (int i = 0; i < attributeCount; i++) {
        printf("%-20s ", attributes[i].attributeName);
    }
    printf("\n");
    for (int i = 0; i < attributeCount; i++) {
        printf("-------------------- ");
    }
    printf("\n");

    while (!feof(file)) {
        for (int i = 0; i < attributeCount; i++) {
            if (attributes[i].type == 'S') {
                char stringValue[attributes[i].size + 1];
                fread(stringValue, attributes[i].size, 1, file);
                stringValue[attributes[i].size] = '\0'; 
                printf("%-20s ", stringValue);
            } else if (attributes[i].type == 'I') {
                int intValue;
                fread(&intValue, sizeof(intValue), 1, file);
                printf("%-20d ", intValue);
            } else if (attributes[i].type == 'D') {
                double doubleValue;
                fread(&doubleValue, sizeof(doubleValue), 1, file);
                printf("%-20.2f ", doubleValue);
            }
        }
        printf("\n");
    }

    fclose(file);
}

int findTable(const char* tableName, Tabela* tabela) {
    FILE* file = fopen("table.dic", "rb");  
    if (!file) {
        printf("Erro ao abrir o arquivo table.dic\n");
        return 0;
    }

    int found = 0;
    while (fread(tabela, sizeof(Tabela), 1, file) == 1) {
        if (strcmp(tableName, tabela->nomeLogico) == 0) {
            printf("Tabela encontrada: ID=%d, Nome Físico='%s'\n", tabela->id, tabela->nomeFisico);
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

int findAttributes(int tableId, AttributeEntry* attributes, int maxAttributes) {
    FILE* file = fopen("att.dic", "rb");
    if (!file) {
        printf("Erro ao abrir o arquivo att.dic\n");
        return 0;
    }

    int count = 0;
    AttributeEntry entry;
    while (fread(&entry, sizeof(entry), 1, file) == 1) {
        if (entry.tableId == tableId) {
            attributes[count] = entry;
            count++;
            if (count >= maxAttributes) {
                break;
            }
        }
    }

    fclose(file);
    return count;
}

void readFile(const char* nomeLogico) {
    Tabela tabela;

    if (!findTable(nomeLogico, &tabela)) {
        printf("Tabela '%s' não encontrada em table.dic\n", nomeLogico);
        return; 
    }

    AttributeEntry attributes[100];
    int attributeCount = findAttributes(tabela.id, attributes, 100);

    if (attributeCount > 0) {
        printf("Esquema para a tabela '%s' encontrado. Lendo o arquivo físico '%s'...\n", tabela.nomeLogico, tabela.nomeFisico);
        readPhysicalFile(tabela.nomeFisico, attributes, attributeCount);
    } else {
        printf("Esquema para a tabela '%s' não encontrado em att.dic\n", nomeLogico);
    }
}