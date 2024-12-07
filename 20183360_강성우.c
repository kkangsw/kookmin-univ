#include <stdio.h>

#define MAX_RECORDS 100

typedef struct {
    float distance;
    float speed;
    float fuel;
} CarData;

void inputCarData(CarData data[], int *count) {
    printf("Enter the number of records: ");
    scanf("%d", count);

    for (int i = 0; i < *count; i++) {
        printf("Record %d\n", i + 1);
        printf("Enter distance (km): ");
        scanf("%f", &data[i].distance);
        printf("Enter speed (km/h): ");
        scanf("%f", &data[i].speed);
        printf("Enter fuel consumption (liters): ");
        scanf("%f", &data[i].fuel);
    }
}

void calculateAverages(CarData data[], int count, float *avgSpeed, float *avgFuel) {
    float totalSpeed = 0, totalFuel = 0;

    for (int i = 0; i < count; i++) {
        totalSpeed += data[i].speed;
        totalFuel += data[i].fuel;
    }

    *avgSpeed = totalSpeed / count;
    *avgFuel = totalFuel / count;
}

void printData(CarData data[], int count) {
    printf("\nData Output:\n");
    printf("Record\tDistance (km)\tSpeed (km/h)\tFuel (liters)\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i + 1, data[i].distance, data[i].speed, data[i].fuel);
    }
}

int main() {
    CarData data[MAX_RECORDS];
    int count;
    float avgSpeed, avgFuel;

    inputCarData(data, &count);  
    calculateAverages(data, count, &avgSpeed, &avgFuel);  

    
    printf("\nAverage Speed: %.2f km/h\n", avgSpeed);
    printf("Average Fuel Consumption: %.2f liters\n", avgFuel);

    printData(data, count); 

    return 0;
}
