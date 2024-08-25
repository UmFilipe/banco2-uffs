typedef struct {
    int id;
    char nomeLogico[20];
    char nomeFisico[20];
} Tabela;

typedef struct {
    int tableId;
    char attributeName[20];
    char type;
    char optional;
    int size;
} AttributeEntry;

void readFile(const char* nomeLogico);
int findTable(const char* tableName, Tabela* tableEntry);
int findAttributes(int tableId, AttributeEntry* attributes, int maxAttributes);
void readPhysicalFile(const char* filename, AttributeEntry* attributes, int attributeCount);
