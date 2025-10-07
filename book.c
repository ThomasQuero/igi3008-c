#include <stdio.h>
#include <stddef.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    long int isbn;
    double price;
};

void changePrice(struct Book *book, double percent){
    book->price *= 1+percent/100;
}

int main()
{
    struct Book book1 = {"Le Seigneur des anneaux", "J.R.R. Tolkien", 2266286269, 18.90};

    printf("Book 1 title : %s\n", book1.title);
    printf("Book 1 author : %s\n", book1.author);
    printf("Book 1 ISBN : %li\n", book1.isbn);
    printf("Book 1 price : %.2f €\n", book1.price);

    struct Book book2 = {"Game Of Thrones, Le trône de fer", "George R.R. Martin", 2290208876, 22.00};

    printf("Book 2 title : %s\n", book2.title);
    printf("Book 2 author : %s\n", book2.author);
    printf("Book 2 ISBN : %li\n", book2.isbn);
    printf("Book 2 price : %.2f €\n", book2.price);

    changePrice(&book2, -5);

    printf("Book 2 title : %s\n", book2.title);
    printf("Book 2 author : %s\n", book2.author);
    printf("Book 2 ISBN : %li\n", book2.isbn);
    printf("Book 2 price : %.2f €\n", book2.price);

    printf("Taille de title pour book1 : %lu\n", strlen(book1.title));
    printf("Taille de author pour book1 : %lu\n", strlen(book1.author));
    printf("Taille de title pour book2 : %lu\n", strlen(book2.title));
    printf("Taille de author pour book2 : %lu\n", strlen(book2.author));

    // printf("size of Book structure: %zu bytes\n", sizeof(book1));
    // printf("    size of title field: %zu bytes\n", sizeof(book1.title));
    // printf("    size of author field: %zu bytes\n", sizeof(book1.author));
    // printf("    size of ISBN field: %zu bytes\n", sizeof(book1.isbn));
    // printf("    size of price field: %zu bytes\n", sizeof(book1.price));

    // size_t titleOffset = offsetof(struct Book, title);
    // size_t authorOffset = offsetof(struct Book, author);
    // size_t isbnOffset = offsetof(struct Book, isbn);
    // size_t priceOffset = offsetof(struct Book, price);

    // printf("Offset de title: %zu bytes\n", titleOffset);
    // printf("Offset de author: %zu bytes\n", authorOffset);
    // printf("Offset de isbn: %zu bytes\n", isbnOffset);
    // printf("Offset de price: %zu bytes\n", priceOffset);

    return 0;
}