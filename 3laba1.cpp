#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <iostream>

using namespace std;

typedef struct library {string writer, title, publisher;  int year; float cost; } str;

void init(str *book){
book[0] = { "Пушкин", "Сказка о рыбаке и рыбке", "ФГЛВ", 1998, 0.5 };
book[1] = { "Толстой", "Война и мир", "ФРАЙТ", 1984, 1000.5 };
book[2] = { "Народ", "Слово о полку Игореве", "ФГОС", 2004, 7328 };
book[3] = { "Достоевский", "Идиот", "ФАКР", 1988, 0.5 };
book[4] = { "лвоыаролыв", "Фроыаоларлоыврае", "ЛОЫГОС", 1988, 0.5 };
book[5] = { "Роулинг", "Гарри Поттер", "РОСМЭН", 1988, 934 };
book[6] = { "Пушкин", "Ллов вшлыов ", "ВОАРО", 1988, 0.5 };
book[7] = { "Булгаков", "Мастер и Маргарита", "ФЛОЫАРОЛЫ", 1849, 0.5 };
book[8] = { "Достоевский", "Преступление и наказание", "ВЛОАР", 1974, 0.5 };
book[9] = { "Булгаков", "Собачье сердце", "ФРАВО", 1908, 4534 }; }

void fizdat(str **lib, str *fbook, str *book,int counter) {
    int j = 0;
    int counter = 0;
    for (int i = 0; i < 10; i++) {
    string a = "Ф";
    string b = lib[i]->publisher;
    if (a[0] == b[0]) {
        fbook[j] = book[i];
        j++;
        counter++;
    }
    }
}
void sort(str* fbook,int counter) {
    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < counter - 1 - i; j++) {
            if (fbook[j].title > fbook[j + 1].title) {
                swap(fbook[j], fbook[j + 1]);}
        }
    }
}
void output(str *fbook, int counter) {
    for (int i = 0; i < counter; i++) {
        cout << "\nКнига:" << i << "\nПисатель:" << fbook[i].writer << "\nНазвание:" << fbook[i].title << "\nИздательство:" << fbook[i].publisher;
        cout << "\nГод издания:" << fbook[i].year << "\nСтоимость:" << fbook[i].cost;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    const int n = 10;
    int i, counter;
    
    str *book = new library[n];
    init(book);
    str **lib = new library*[n];
    for (i = 0; i < n; i++) { lib[i] = &book[i]; }
    
    str *fbook = new library[n];
    fizdat(lib, fbook, book,counter);
    sort(fbook,counter);
    
    output(fbook,counter);
    cout << sizeof(book[0]) << endl << sizeof(fbook[0]);
    return 0;
}
