#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100
#define VARS 4  // intercept + 3 variabel (luas, alat, suhu)

// Gauss-Jordan untuk invers matriks 4x4
int inverseMatrix(double A[VARS][VARS], double inverse[VARS][VARS]) {
    int i, j, k;
    double ratio;

    for (i = 0; i < VARS; i++) {
        for (j = 0; j < VARS; j++)
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
    }

    // Gauss-Jordan eliminasi
    for (i = 0; i < VARS; i++) {
        double pivot = A[i][i];
        if (pivot == 0.0) return 0; // singular

        for (j = 0; j < VARS; j++) {
            A[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        for (k = 0; k < VARS; k++) {
            if (k != i) {
                ratio = A[k][i];
                for (j = 0; j < VARS; j++) {
                    A[k][j] -= ratio * A[i][j];
                    inverse[k][j] -= ratio * inverse[i][j];
                }
            }
        }
    }

    return 1;
}

int main() {
    double X[MAX_DATA][VARS];
    double y[MAX_DATA];
    int n = 0;

    FILE *fp = fopen("data_energi.csv", "r");
    if (!fp) {
        printf("Gagal membuka file data_energi.csv\n");
        return 1;
    }

    char line[1024];
    fgets(line, sizeof(line), fp); 

    // Baca CSV
    while (fgets(line, sizeof(line), fp)) {
        int luas, alat, suhu, energi;
        if (sscanf(line, "%d,%d,%d,%d", &luas, &alat, &suhu, &energi) == 4) {
            X[n][0] = 1;        
            X[n][1] = luas;
            X[n][2] = alat;
            X[n][3] = suhu;
            y[n] = energi;
            n++;
        }
    }
    fclose(fp);

    // Hitung XtX dan Xty
    double XtX[VARS][VARS] = {0};
    double Xty[VARS] = {0};

    for (int i = 0; i < VARS; i++) {
        for (int j = 0; j < VARS; j++) {
            for (int k = 0; k < n; k++) {
                XtX[i][j] += X[k][i] * X[k][j];
            }
        }
        for (int k = 0; k < n; k++) {
            Xty[i] += X[k][i] * y[k];
        }
    }

    // Invers XtX
    double XtX_copy[VARS][VARS], XtX_inv[VARS][VARS];
    for (int i = 0; i < VARS; i++)
        for (int j = 0; j < VARS; j++)
            XtX_copy[i][j] = XtX[i][j];

    if (!inverseMatrix(XtX_copy, XtX_inv)) {
        printf("Matriks tidak dapat diinvers (singular).\n");
        return 1;
    }

    // Hitung beta = (XtX)^-1 * Xty
    double beta[VARS] = {0};
    for (int i = 0; i < VARS; i++)
        for (int j = 0; j < VARS; j++)
            beta[i] += XtX_inv[i][j] * Xty[j];

    // Output model
    printf("Model Regresi Least-Squares:\n\n");
    printf("Beta[0] = %.4f  --> Intercept\n", beta[0]);
    printf("Beta[1] = %.4f  --> Koefisien Luas Ruang (m2)\n", beta[1]);
    printf("Beta[2] = %.4f  --> Koefisien Jumlah Alat\n", beta[2]);
    printf("Beta[3] = %.4f  --> Koefisien Suhu (Celsius)\n", beta[3]);

    // Prediksi untuk bangunan uji
    int luas_uji = 130, alat_uji = 15, suhu_uji = 31;
    double prediksi = beta[0] + beta[1]*luas_uji + beta[2]*alat_uji + beta[3]*suhu_uji;

    printf("\nPrediksi konsumsi energi untuk bangunan dengan:\n");
    printf("- Luas Ruangan      : %d m2\n", luas_uji);
    printf("- Jumlah Peralatan  : %d\n", alat_uji);
    printf("- Suhu Rata-rata    : %d derajat Celcius\n", suhu_uji);
    printf("=> Prediksi Energi: %.2f kWh\n", prediksi);

    // Simpan ke file hasil_prediksi.csv
    FILE *out = fopen("hasil_prediksi.csv", "w");
    fprintf(out, "luas,alat,suhu,prediksi_kWh\n");
    fprintf(out, "%d,%d,%d,%.2f\n", luas_uji, alat_uji, suhu_uji, prediksi);
    fclose(out);
    printf("\nHasil disimpan ke: hasil_prediksi.csv\n");

    return 0;
}

