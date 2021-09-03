/*
TOKENS
FDT = fin de texto; SEP = separador; CAD = cadena
*/
typedef enum
{
    FDT,
    SEP,
    CAD
} TOKEN;

//Prototipo para función get_token
TOKEN get_token(void);
