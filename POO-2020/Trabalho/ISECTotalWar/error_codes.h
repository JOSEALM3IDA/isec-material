#ifndef ERROR_CODES_H
#define ERROR_CODES_H

#include <map>
#include <string>

#define errcode int

#define DEBUG true // Comandos de debug

#define UNEXPECTED -1
#define OK -2
#define NEXT -3
#define AVANCA -4
#define ATIVA -5

#define FILE_CANT_OPEN -6
#define FILE_BAD_FORMAT -7
#define FILE_NO_NEW_TERRITORIES -8

#define CMD_UNKNOWN -9
#define CMD_INFO_UNKNOWN -10
#define CMD_INVALID_ARGS -11
#define CMD_NOT_AVAILABLE -12
#define CMD_DISP_UNCHANGED -13
#define CMD_NO_NEW_TERRITORIES -14

#define IMP_NOT_ENOUGH_POWER -15
#define IMP_NOT_ENOUGH_LUCK -16
#define IMP_NOT_ENOUGH_OURO -17
#define IMP_NOT_ENOUGH_PROD -18
#define IMP_TOO_MUCH_OURO -19
#define IMP_TOO_MUCH_PROD -20
#define IMP_TOO_MUCH_FORCA -21
#define IMP_TOO_MANY_RESOURCES -22
#define IMP_CANT_TAKE_OURO -23
#define IMP_CANT_TAKE_PROD -24
#define IMP_CANT_TAKE_FORCA -25
#define IMP_NO_REQUIRED_TEC -26

#define TERR_NOT_FOUND -27
#define TERR_ALREADY_CONQUERED -28
#define TERR_TYPE_UNKNOWN -29

#define TEC_ALREADY_BOUGHT -30
#define TEC_DOESNT_EXIST -31

#define EVNT_NOT_FOUND -32

#define SAVE_NOT_FOUND -33
#define SAVE_USER_CANCEL -34

#define FIM_JOGO -35

extern std::map<int, std::string> codeToString;

#endif /* ERROR_CODES_H */