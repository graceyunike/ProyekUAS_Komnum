# 🔋 Energy Consumption Prediction Using Multiple Linear Regression

## Table of Contents
- [📌 Project Overview](#project-overview)
- [📊 Theory: Multiple Regression and Least Squares](#theory-multiple-regression-and-least-squares)
- [💻 Implementation Details](#implementation-details)
- [📁 Project Structure](#project-structure)
- [🚀 How to Run This Project](#how-to-run-this-project)
- [📈 Visualizations](#visualizations)
- [📚 References](#references)
- [🎓 Academic Note](#academic-note)

---

## 📌 Project Overview

This final project for the Numerical Computation course implements an energy prediction model for laboratory buildings using the multiple linear regression method solved via Least-Squares. The model estimates daily energy consumption (in kWh) based on three variables: room area (m²), number of electrical equipment, and environmental temperature (°C).

The computation is fully implemented in C, while result visualization and analysis are performed in Python.


---

## 📊 Theory: Multiple Regression and Least Squares

Multiple linear regression models the relationship between one dependent variable and multiple independent variables. The general form:

```
y = β₀ + β₁·x₁ + β₂·x₂ + β₃·x₃
```

Where:
- y: energy consumption (kWh)  
- x₁: room area (m²)  
- x₂: number of equipment  
- x₃: temperature (°C)  

The regression coefficients β are calculated using the Least-Squares method:

```
β = (Xᵀ·X)⁻¹ · Xᵀ·y
```

This method minimizes the squared error between actual and predicted values, producing an optimal linear solution.

---

## 💻 Implementation Details

### `Multiple Regression.c`
- Loads training data from `data_energi.csv`
- Calculates (Xᵀ·X) and (Xᵀ·y)
- Solves β using matrix inversion (Gauss-Jordan)
- Outputs predicted energy to `hasil_prediksi.csv`

### `regresi_plot_3in1.py`
- Visualizes:
  1. Actual vs Predicted Energy (Scatter Plot)
  2. Residuals
  3. Temperature vs Predicted Energy

---

## 📁 Project Structure

```
ProyekUAS_Komnum
├── Multiple Regression.c          # Main C program
├── data_energi.csv                # Input training data (area, alat, suhu, energi)
├── hasil_prediksi.csv             # Output predictions
├── regresi_plot_3in1.py           # Python visualization script
├── ProyekUAS_Komnum.pdf           # Final report
└── README.md                      # Documentation
```

---

## 🚀 How to Run This Project

### 🔧 Step 1: Compile and Run the C Program

```bash
gcc Multiple Regression.c -o prediksi
./prediksi
```

This will generate a file called `hasil_prediksi.csv`.

### 📈 Step 2: Install Python Dependencies

```bash
python --version
pip install matplotlib seaborn pandas
```

### 🧪 Step 3: Visualize Results with Python

```bash
python regresi_plot_3in1.py
```

This will generate three plots:
- Scatter plot of actual vs predicted energy
- Residual plot
- Temperature vs predicted energy plot

---

## 📈 Visualizations

- 📌 Actual vs Predicted Energy  
  ![plot_aktual_vs_prediksi](https://hackmd.io/_uploads/H1ei3TXQxx.png)
  Evaluates how well the model fits the data.

- 🧮 Residual Plot  
  ![plot_residual](https://hackmd.io/_uploads/BJE62TX7ex.png)
  Shows the distribution of prediction errors.

- 🌡️ Temperature vs Predicted Energy  
  ![plot_suhu_vs_prediksi](https://hackmd.io/_uploads/r1ikapQQee.png)
  Demonstrates correlation between ambient temperature and energy use.

All plots are automatically saved as image files when running `regresi_plot_3in1.py`.

---

## 📚 References

1. “View of Modelling and predicting energy consumption in laboratory buildings using multiple linear regression,” Uad.ac.id, 2025. https://journal.uad.ac.id/index.php/Konvergensi/article/view/21531/10683 (accessed Jun. 07, 2025).
2. Chapman, S. J., “Numerical Methods for Engineers and Scientists: Using MATLAB and C”, 3rd ed. New York: McGraw-Hill, 2010.
3. Python Software Foundation, “Matplotlib Documentation.” [Online]. Available: https://matplotlib.org/stable/index.html (accessed Jun. 07, 2025).
4. Steven C. Chapra and Raymond P. Canale, “Numerical Methods for Engineers,” Sixth Edition, McGraw Hill Higher Education, 2010. 
5. A. Payong, “Ridge Regression Part 2: Deep Dive,” Digitalocean.com, May 08, 2025. https://www.digitalocean.com/community/tutorials/ridge-regression-explained-part-2 (accessed Jun. 07, 2025).
6. “ML | Multiple Linear Regression using Python,” GeeksforGeeks, Jan. 18, 2019. https://www.geeksforgeeks.org/ml-multiple-linear-regression-using-python/ (accessed Jun. 07, 2025).

---

## 🎓 Academic Note

> This project was developed as part of the Project for the Numerical Computation course  
> Department of Computer Engineering, Universitas Indonesia, 2025.
