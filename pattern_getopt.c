/* В этом файле пример использования getopt() с некоторыми пояснениями. */
/* getopt() лежит здесь.
 * Прототип выглядит следующим образом:
 *  getopt(int argc, char * const argv[],
           const char *optstring);
 * Вместе с getopt() лежат:
 *  extern char *optarg;
 *  extern int optind, opterr, optopt;
 * где:
 *  optarg - указатель на текущий аргумент, если таковой имеется,
 *  optind - индекс на следующий указатель argv, который будет обработан при следующем вызове getopt()
 *  optopt - последний из известных параметров.
 * так написано здесь: https://www.ibm.com/developerworks/ru/library/au-unix-getopt/
 * Информации по opterr найти не удалось (ладно, мне лень),
 * возвращает 0 если опция нормально отработала и код клавиши в случае если опция не найдена в optstring.
 * Когда все опции обработаны, getopt() возвращает -1.
 * optstring заполняется так:
 *  если параметр должен принимать значение,
 *  после него ставится символ двоеточия:
 *   getopt(argc, argv, "o:");
 *   "-o <file> | output file"
 *  иначе просто символ
 *   getopt(argc, argv, "v");
 *   "-v        | enable verbose mode"
 * Иногда для optstring делают отдельную переменную:
 * const char opt_list = "f:o:h";
 * и используют:
 * opt = getopt(argc, argv, opt_list);
 * Не вижу в этом смысла.
 * Подробнее в man getopt(3).
 */
#include <unistd.h>


char opt;

while((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
        /* Располагаем опции и инструкции к ним здесь. */
        case '?': /* Этот кейс означает что опции нет в списке  */
                /* Пишем что-то типа "Такой опции нет" и проходим в следующий кейс. */
        case 'h':
                /* Выводим справку. */
                break;
        default: /* Если никаких ошибок нет, сюда невозможно попасть.*/
                break;
        }
}
