#include <stdio.h>
#include <string.h>

#define SIZE 10

char currencies[SIZE][5] = {"USD", "EGP", "EUR", "SAR", "GBP"};
float rates[SIZE] = {1.0, 50.96, 0.88, 3.75, 0.75};


//function to check currency input
int getCurrencyIndex(char currency[]) {
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(currency, currencies[i]) == 0) {
            return i; //valid currency
        }
    }
    return -1; //unvalid currency
}



//converter
float convert(float amount, int fromIndex, int toIndex) {
    float inUSD = amount / rates[fromIndex]; //convert to USD
    inUSD =inUSD * rates[toIndex]; // convert to target currency
    
    return inUSD;

}



int main() {
    char from[10], to[10];
    float amount, result;

    printf("Available currencies: USD, EGP, EUR, SAR, GBP\n");

    printf("Enter source currency: ");
    scanf("%s", from);

    printf("Enter target currency: ");
    scanf("%s", to);

    printf("Enter amount: ");
    scanf("%f", &amount);


    int fromIndex = getCurrencyIndex(from);
    int toIndex = getCurrencyIndex(to);

    if (fromIndex == -1 || toIndex == -1) {
        printf("Invalid currency name entered.\n");
        return 1;
    }



    result = convert(amount, fromIndex, toIndex);

    printf("\n%.2f %s = %.2f %s\n", amount, from, result, to);

    return 0;
}
