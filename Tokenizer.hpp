#include <string>

using namespace std;

class Tokenizer{

private:
int isNum(char *token);
int countTokens (char *line);


public:
string* GetTokens();

};
