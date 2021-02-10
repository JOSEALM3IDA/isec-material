#include "error_codes.h"

std::map<int , std::string> codeToString = { {UNEXPECTED, "Erro inesperado"},
                                             {OK, "OK"},
                                             {NEXT, "Passar de subfase"},
                                             {AVANCA, "Passar de fase"},
                                             {ATIVA, "Ativar save"},

                                             {FILE_CANT_OPEN, "Abertura do ficheiro falhou"},
                                             {FILE_BAD_FORMAT, "Ficheiro com formato errado"},
                                             {FILE_NO_NEW_TERRITORIES, "Informacao no ficheiro nao gera territorios"},

                                             {CMD_UNKNOWN, "Comando desconhecido"},
                                             {CMD_INFO_UNKNOWN, "Nao existe informacao sobre esse comando"},
                                             {CMD_INVALID_ARGS, "Argumentos do comando errados"},
                                             {CMD_NOT_AVAILABLE, "Comando nao disponivel neste momento"},
                                             {CMD_DISP_UNCHANGED, "Disponibilidade do comando nao mudada"},
                                             {CMD_NO_NEW_TERRITORIES, "Comando nao gera territorios"},

                                             {IMP_NOT_ENOUGH_POWER, "Imperio nao tem forca suficiente"},
                                             {IMP_NOT_ENOUGH_LUCK, "A sorte gerada nao foi suficiente"},
                                             {IMP_NOT_ENOUGH_OURO, "Nao possui ouro suficiente"},
                                             {IMP_NOT_ENOUGH_PROD, "Nao possui produtos suficientes"},
                                             {IMP_TOO_MUCH_OURO, "O cofre do imperio atingiu a sua capacidade maxima e foram perdidas algumas unidades de ouro"},
                                             {IMP_TOO_MUCH_PROD, "O armazem do imperio atingiu a sua capacidade maxima e foram perdidas algumas unidades de produtos"},
                                             {IMP_TOO_MUCH_FORCA, "A forca militar atingiu a sua capacidade maxima e foram perdidas algumas unidades"},
                                             {IMP_TOO_MANY_RESOURCES, "Tanto o cofre como o armazem do imperio atingiram a sua capacidade maxima e foram perdidos recursos"},
                                             {IMP_CANT_TAKE_OURO, "O cofre do imperio nao tem capacidade para receber essa quantidade de ouro"},
                                             {IMP_CANT_TAKE_PROD, "O armazem do imperio nao tem capacidade para receber essa quantidade de produtos"},
                                             {IMP_CANT_TAKE_FORCA, "A forca militar nao pode passar do limite"},
                                             {IMP_NO_REQUIRED_TEC, "Nao possui a tecnologia necessaria para efetuar a acao"},

                                             {TERR_NOT_FOUND, "Territorio nao encontrado"},
                                             {TERR_ALREADY_CONQUERED, "Territorio ja conquistado"},
                                             {TERR_TYPE_UNKNOWN, "Tipo de territorio desconhecido"},
                                             
                                             {TEC_ALREADY_BOUGHT, "A tecnologia ja foi comprada previamente"},
                                             {TEC_DOESNT_EXIST, "Tecnologia nao existente"},

                                             {EVNT_NOT_FOUND, "Evento nao encontrado"},

                                             {SAVE_NOT_FOUND, "Save nao encontrado"},
                                             {SAVE_USER_CANCEL, "Cancelado pelo utilizador"},

                                             {FIM_JOGO, "O jogo chegou ao fim"} };